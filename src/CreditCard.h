/**
 * @file CreditCard.h
 * @details Store registries of all movements of a card
 */

#ifndef FINANCES_CREDITCARD_H
#define FINANCES_CREDITCARD_H

#include "Registry.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>

class CreditCard {
public:
    CreditCard(string path, char delimiter);
    virtual ~CreditCard();

    float getIncome() const ;
    float getExpenses() const;
    void showRegistries();

private:
    vector<Registry *> *_movements;
};

#endif //FINANCES_CREDITCARD_H
