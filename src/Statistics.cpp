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

void Statistics::getGeneralStatistics(CreditCard *card, string name_file) {
    ofstream output_file("../statistics/general_statistics_" + name_file + ".txt");
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
    for (int i = 0; i < _categorization->size(); ++i)
        if (containString(FileFormatter::stringToChar(str),
                          FileFormatter::stringToChar(_categorization->at(i).first)))
            return i;
    return -1;
}

void Statistics::calculateCategoriesAmount(CreditCard *card) {
    int numMovements = card->getNumMovements();
    for (int i = 0; i < numMovements; ++i) {
        Registry *current_registry = card->getMovement(i);
        int pos = getPositionCategorization(current_registry->getNotion());

        if (pos != -1) {
            auto it = _categorization->at(pos).second.begin();

            while (it != _categorization->at(pos).second.end()) {
                _all_categories->find(*it)->second += current_registry->getAmount();
                it++;
            }
        } else {
            throw logic_error("[Statistics] Notions without categorize. Please add <"
                              + current_registry->getNotion() + "> to one category");
        }
    }
}

void Statistics::writeHeadToFile(string head, ofstream &file) {
    file << endl;
    file << "------------------------------" << endl;
    file << "     " + head << endl;
    file << "------------------------------" << endl;
    file << endl;
}

void Statistics::writeToFile(ofstream &file, vector<pair<string, float> > *categories_with_amounts) {
    for (int j = 0; j < categories_with_amounts->size(); ++j) {
        file << categories_with_amounts->at(j).first << ": "
             << categories_with_amounts->at(j).second << "€" << endl;
    }
}

void Statistics::getExpensesByCategories(CreditCard *card, string file_name) {
    ofstream output_file_incomes("../statistics/incomes_by_categories_" + file_name + ".txt");
    ofstream output_file_expenses("../statistics/expenses_by_categories_" + file_name + ".txt");

    calculateCategoriesAmount(card);

    auto it = _all_categories->begin();
    vector<pair<string, float>> expenses_under_250;
    vector<pair<string, float>> expenses_over_250;
    vector<pair<string, float>> expenses_under_100;
    vector<pair<string, float>> incomes;

    while (it != _all_categories->end()) {
        if (it->second) {
            if (it->second < 0)
                if (it->second > -100 && it->second < 0)
                    expenses_under_100.push_back(*it);
                else if (it->second > -250)
                    expenses_under_250.push_back(*it);
                else
                    expenses_over_250.push_back(*it);
            else
                incomes.push_back(*it);
        }
        it++;
    }

    writeHeadToFile("Incomes", output_file_incomes);
    writeToFile(output_file_incomes, &incomes);

    writeHeadToFile("Expenses over 250€", output_file_expenses);
    writeToFile(output_file_expenses, &expenses_over_250);

    writeHeadToFile("Expenses between 250€-100€", output_file_expenses);
    writeToFile(output_file_expenses, &expenses_under_250);

    writeHeadToFile("Expenses between 100€-0€", output_file_expenses);
    writeToFile(output_file_expenses, &expenses_under_100);
}

Statistics::~Statistics() {}
