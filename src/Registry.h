/**
 * @file Registry.h
 * @details Stores information related to a financial movement
 */

#ifndef FINANCES_REGISTRY_H
#define FINANCES_REGISTRY_H

#include <iostream>
#include <string>

using namespace std;

class Registry {
public:
    Registry(string date, string notion, float amount);
    virtual ~Registry();

    float getAmount() const;
    string getDate() const;
    string getNotion() const;

private:
    string _date;
    string _notion;
    float _amount;
};

#endif //FINANCES_REGISTRY_H

