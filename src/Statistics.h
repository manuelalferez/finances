/**
 * @file Statistics.h
 * @details Implementation of all statistics
 */

#ifndef FINANCES_STATISTICS_H
#define FINANCES_STATISTICS_H

#include "CreditCard.h"
#include <map>
#include <list>

using namespace std;

class Statistics {
public:
    Statistics(string path);

    virtual ~Statistics();
    void getGeneralStatistics(CreditCard *card);
private:


    map<string, list<string>> *_categories;
};

#endif //FINANCES_STATISTICS_H
