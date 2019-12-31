#include "Statistics.h"

Statistics::Statistics(string path) {
    _categorization = new vector<pair<string, list<string>>>();
    _all_categories = new map<string, float>();

    ifstream file(path);
    string line, field;
    vector<string> items;
    vector<string> categories_fields;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            while (getline(ss, field, ';'))
                items.push_back(field);

            getline(file, line);
            ss.clear();
            ss.str(line);

            while (getline(ss, field, ';'))
                categories_fields.push_back(field);

            insertCategories(categories_fields);
            makeCategorization(categories_fields, items);

            getline(file, line);
            items.clear();
            categories_fields.clear();
        }
        file.close();
    }
}

void Statistics::makeCategorization(vector<string> &categories, vector<string> &items) {
    for (int j = 0; j < items.size(); ++j) {
        int pos = 0;
        auto it = _categorization->begin();
        while (it != _categorization->end()) {
            if (it->first == items[j])
                break;
            it++;
        }
        if (it != _categorization->end()) {
            for (int i = 0; i < categories.size(); ++i)
                it->second.push_front(categories[i]);
        } else {
            list<string> categories_list;
            for (int i = 0; i < categories.size(); ++i)
                categories_list.push_front(categories[i]);
            _categorization->push_back(pair<string, list<string>>(items[j], categories_list));
        }
    }
}

void Statistics::insertCategories(vector<string> &categories) {
    for (int i = 0; i < categories.size(); ++i)
        _all_categories->insert(pair<string, float>(categories[i], 0));
}

void Statistics::getGeneralStatistics(CreditCard *card) {
    ofstream output_file("../statistics/general_statistics.txt");
    float income = card->getIncome();
    float expenses = card->getExpenses();
    output_file << "Income: " << income << "€" << endl;
    output_file << "Expenses: " << expenses << "€" << endl;
    output_file << "Net value: " << income + expenses << "€" << endl;
}

bool Statistics::containString(char *str, char *substr) {
    toLowerCase(str);
    toLowerCase(substr);
    char *tmp = str;
    char *cut_str;

    cut_str = strstr(tmp, substr);
    if (cut_str) return true;

    return false;
}

void Statistics::toLowerCase(char *str) {
    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

char *Statistics::stringToChar(string str) {
    char *c_str = new char[str.size() + 1];
    strcpy(c_str, str.c_str());
    return c_str;
}

void Statistics::showCategorization() {
    for (int i = 0; i < _categorization->size(); ++i) {
        cout << _categorization->at(i).first << endl;
        auto it = _categorization->at(i).second.begin();
        cout << "Categorias: ";
        while (it != _categorization->at(i).second.end()) {
            cout << *it << " ";
            it++;
        }
        cout << endl;
        cout << endl;
    }
}

int Statistics::getPositionCategorization(string str) {
    for (int i = 0; i < _categorization->size(); ++i) {
        if (containString(stringToChar(str), stringToChar(_categorization->at(i).first)))
            return i;
    }
    return -1;
}

void Statistics::getExpensesByCategories(CreditCard *card) {
    ofstream output_file("../statistics/expenses_by_categories.txt");
    int numMovements = card->getNumMovements();
    for (int i = 0; i < numMovements; ++i) {
        Registry *current_registry = card->getMovement(i);
        string current_notion = current_registry->getNotion();
        float current_amount = current_registry->getAmount();

        int pos = getPositionCategorization(current_notion);

        if (pos != -1) {
            auto it = _categorization->at(pos).second.begin();

            while (it != _categorization->at(pos).second.end()) {
                auto found = _all_categories->find(*it);
                found->second += current_amount;
                it++;
            }
        } else {
            throw logic_error(
                    "[Statistics] Notions without categorize. Please add <" + current_notion + "> to one category");
        }
    }

    auto it = _all_categories->begin();
    while (it != _all_categories->end()) {
        if (it->second) {
            output_file << it->first << ": " << it->second << "€" << endl;
        }
        it++;
    }
}

Statistics::~Statistics() {}
