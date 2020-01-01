/**
 * @file Statistics.h
 * @details Implementation of all statistics
 */

#ifndef FINANCES_STATISTICS_H
#define FINANCES_STATISTICS_H

#include "CreditCard.h"
#include <map>
#include <list>
#include <cctype>

using namespace std;

#include "FileFormatter.h"

class Statistics {
public:
    Statistics(string path);
    virtual ~Statistics();

    void insertCategories(vector<string> &categories);
    void makeCategorization(vector<string> &categories, vector<string> &items);

    void getGeneralStatistics(CreditCard *card, string name_file);
    void getExpensesByCategories(CreditCard *card, string file_name);

    bool containString(char *str, char *substr);
    void toLowerCase(char *str);
    void showCategorization();
    int getPositionCategorization(string str);
    void calculateCategoriesAmount(CreditCard *card);
    void writeHeadToFile(string head, ofstream &file);
    void writeToFile(ofstream &file, vector<pair<string, float> > *categories_with_amounts);
    void cleanCategoriesAmount();
private:
    vector<pair<string, list<string>>> *_categorization;
    map<string, float> *_all_categories;
};

#endif //FINANCES_STATISTICS_H
