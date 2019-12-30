#include "Statistics.h"

Statistics::Statistics(string path) {
    _categories = new map<string, list<string>>();

    ifstream file(path);
    string line, field;
    vector<string> fields;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            while (getline(ss, field, ';'))
                fields.push_back(field);
            list<string> groups;
            for (int i = 1; i < fields.size(); ++i)
                groups.push_front(fields[i]);
            _categories->insert(pair<string, list<string>>(fields[0], groups));
            fields.clear();
        }
        file.close();
    }
}

void Statistics::getGeneralStatistics(CreditCard *card) {
    ofstream output_file("../statistics/general_statistics.txt");
    float income = card->getIncome();
    float expenses = card->getExpenses();
    output_file << "Income: " << income << "€" << endl;
    output_file << "Expenses: " << expenses << "€" << endl;
    output_file << "Net value: " << income + expenses << "€" << endl;
}

Statistics::~Statistics() {}
