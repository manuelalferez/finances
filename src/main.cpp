/**
 * @brief Application for finance management
 * @details The application from the parameters reads the data files provided to build statistics
 * @author manuelalferez
 */

#include "CreditCard.h"
#include "FileFormatter.h"
#include "Statistics.h"

bool to_bool(string const &s) {
    return s != "0";
}

void readParams(string path, vector<string> *paths_data_files, vector<string> *delimiters,
                vector<bool> *is_revolut, vector<bool> *is_formatted) {
    ifstream file(path);
    if (file.is_open()) {
        string line, field;
        stringstream ss;

        getline(file, line);
        getline(file, line);
        ss << line;

        while (getline(ss, field, ':')) {
            paths_data_files->push_back("../data/" + field);
        }

        getline(file, line);
        getline(file, line);
        ss.clear();
        ss.str(line);

        while (getline(ss, field, ':')) {
            delimiters->push_back(field);
        }

        getline(file, line);
        getline(file, line);
        ss.clear();
        ss.str(line);

        while (getline(ss, field, ':')) {
            is_revolut->push_back(to_bool(field));
        }

        getline(file, line);
        getline(file, line);
        ss.clear();
        ss.str(line);
        while (getline(ss, field, ':')) {
            is_formatted->push_back(to_bool(field));
        }

        file.close();
    }
}

int main() {
    vector<string> *paths_data_files = new vector<string>();
    vector<string> *delimiters = new vector<string>();
    vector<bool> *is_revolut_file = new vector<bool>();
    vector<bool> *is_formatted = new vector<bool>();

    readParams("../params/params.csv", paths_data_files, delimiters, is_revolut_file, is_formatted);

    for (int i = 0; i < paths_data_files->size(); ++i) {
        if (!is_formatted->at(i))
            FileFormatter::formatFiles(paths_data_files->at(i), is_revolut_file->at(i),
                                       FileFormatter::stringToChar(delimiters->at(i)));
    }

    vector<CreditCard *> *cards = new vector<CreditCard *>();
    for (int j = 0; j < paths_data_files->size(); ++j) {
        string name_file = FileFormatter::getNameFile(paths_data_files->at(j));
        string path_file_formatted;

        if (is_formatted->at(j))
            path_file_formatted = "../data/" + name_file + ".csv";
        else
            path_file_formatted = "../formatted_data/" + name_file + ".csv";

        cards->push_back(new CreditCard(path_file_formatted, FileFormatter::stringToChar(delimiters->at(j))));
    }

    Statistics statistics_data("../categories/categories.csv");

    for (int j = 0; j < paths_data_files->size(); ++j) {
        statistics_data.getGeneralStatistics(cards->at(j), FileFormatter::getNameFile(paths_data_files->at(j)));
        try {
            statistics_data.getExpensesByCategories(cards->at(j), FileFormatter::getNameFile(paths_data_files->at(j)));
        } catch (exception &e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
