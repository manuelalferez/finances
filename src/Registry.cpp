#include "Registry.h"

Registry::Registry(string date, string notion, float amount) :
        _date(date),
        _notion(notion),
        _amount(amount) {
}

Registry::~Registry() {}

float Registry::getAmount() const {
    return _amount;
}

string Registry::getDate() const {
    return _date;
}

string Registry::getNotion() const {
    return _notion;
}

