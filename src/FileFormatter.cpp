#include "FileFormatter.h"

string FileFormatter::getNameFile(string path) {
    string name = path;
    int separation = name.find_last_of("/");
    name = name.substr(separation + 1, name.size() - separation - 1);
    name = name.substr(0, name.find("."));
    return name;
}

bool FileFormatter::isIncome(vector<string> &incomes_categories, string notion) {
    stringstream ss(notion);
    string first_word;
    getline(ss, first_word, ' ');
    for (int i = 0; i < incomes_categories.size(); ++i)
        if (first_word == incomes_categories[i])
            return true;
    return false;
}

vector<string> *FileFormatter::readCategories(string path) {
    ifstream file(path);
    vector<string> *incomes_categories = new vector<string>();
    if (file.is_open()) {
        string line;
        while (getline(file, line))
            incomes_categories->push_back(line);
        file.close();
    }
    return incomes_categories;
}

string changeToPoint(string number_with_coma) {
    stringstream ss(number_with_coma);
    string first_digit, second_digit;
    getline(ss, first_digit, ',');
    getline(ss, second_digit, ',');
    return first_digit + "." + second_digit;
}

string removePoint(string number_with_point) {
    stringstream ss(number_with_point);
    string first_digit, second_digit;
    getline(ss, first_digit, '.');
    getline(ss, second_digit, '.');
    return first_digit + second_digit;
}

void FileFormatter::formatFiles(string path, bool is_revolut, char delimiter) {
    ifstream file(path);
    string line, field;
    vector<string> fields;
    vector<string> *incomes_categories = nullptr;
    if (is_revolut)
        incomes_categories = readCategories("../categories/incomes_categories.txt");

    string name_file = getNameFile(path);
    string path_output_file = "../formatted_data/" + name_file + ".csv";
    ofstream output_file(path_output_file);

    getline(file, line);
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            while (getline(ss, field, delimiter))
                fields.push_back(field);
            if (is_revolut) {
                output_file << fields[0] << delimiter
                            << fields[1] << delimiter;
                if (!isIncome(*incomes_categories, fields[1])) {
                    if (fields[2].empty()) {
                        fields[3] = changeToPoint(fields[3]);
                        fields[3] = "-" + fields[3];
                        output_file << fields[3] << endl;
                    } else {
                        fields[2] = changeToPoint(fields[2]);
                        fields[2] = "-" + fields[2];
                        output_file << fields[2] << endl;
                    }
                } else {
                    fields[3] = changeToPoint(fields[3]);
                    output_file << fields[3] << endl;
                }
            } else {
                fields[3] = removePoint(fields[3]);
                fields[3] = fields[3] + "." + fields[4];
                output_file << fields[0] << delimiter
                            << fields[2] << delimiter
                            << fields[3] << endl;
            }
            fields.clear();
        }
        file.close();
        output_file.close();
        delete incomes_categories;
    }
}