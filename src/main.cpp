/**
 * @brief Application for finance management
 * @details The application from the parameters reads the data files provided to build statistics
 * @author manuelalferez
 */

#include "CreditCard.h"
#include "FileFormatter.h"
#include "Statistics.h"

int main() {
    string data_paths[] = {"../data/data.csv", "../data/revolut.csv"};
    FileFormatter::formatFiles(data_paths[0], false, ',');
    FileFormatter::formatFiles(data_paths[1], true, ';');
    data_paths[0] = "../formatted_data/data.csv";
    data_paths[1] = "../formatted_data/revolut.csv";
    CreditCard *card = new CreditCard(data_paths[1], ';');
    Statistics statistics_data("../categories/categories.csv");

    return 0;
}
