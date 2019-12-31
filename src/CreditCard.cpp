#include "CreditCard.h"

CreditCard::CreditCard(string path, char delimiter) {
    _movements = new vector<Registry *>();

    ifstream file(path);
    string line, field;
    vector<string> fields;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            while (getline(ss, field, delimiter))
                fields.push_back(field);
            try {
                float amount = stof(fields[2]);
                _movements->push_back(new Registry(fields[0], fields[1], amount));
            } catch (exception &e) {
                cout << "[CreditCard]: When loading the data file: " << endl;
                cout << "Registry: "
                     << "Date: " << fields[0]
                     << "Notion: " << fields[1]
                     << "Amount: " << fields[2] << endl;
            }
            fields.clear();
        }
        file.close();
    }
}

CreditCard::~CreditCard() {
    for (int i = 0; i < _movements->size(); ++i)
        delete _movements->at(i);
    delete _movements;
}

float CreditCard::getIncome() const {
    float income = 0;
    for (int i = 0; i < _movements->size(); ++i)
        if (_movements->at(i)->getAmount() >= 0)
            income += _movements->at(i)->getAmount();
    return income;
}

float CreditCard::getExpenses() const {
    float expenses = 0;
    for (int i = 0; i < _movements->size(); ++i)
        if (_movements->at(i)->getAmount() <= 0)
            expenses += _movements->at(i)->getAmount();
    return expenses;
}

void CreditCard::showRegistries() {
    for (int i = 0; i < _movements->size(); ++i) {
        cout << _movements->at(i)->getDate() << ";"
             << _movements->at(i)->getNotion() << ";"
             << _movements->at(i)->getAmount() << endl;
    }
}

Registry* CreditCard::getMovement(int pos) {
    return _movements->at(pos);
}

int CreditCard::getNumMovements() {
    return _movements->size();
}