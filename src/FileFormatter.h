/**
 * @file FileFormatter.h
 * @details The data files are not in the correct format. Functions needed to format the data
 */

#ifndef FINANCES_FILEFORMATTER
#define FINANCES_FILEFORMATTER

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

namespace FileFormatter {
    bool isIncome(vector<string> &incomes_categories, string notion);
    vector<string> *readCategories(string path);
    void formatFiles(string path, bool is_revolut, char *delimiter);
    string getNameFile(string path);
    char *stringToChar(string str);
};


#endif //FINANCES_FILEFORMATTER
