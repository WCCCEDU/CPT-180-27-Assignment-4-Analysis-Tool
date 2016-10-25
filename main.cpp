#include <iostream>
#include <fstream>
#include <string.h>
#include "./header.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

const string OUTPUT_FILE_PATH = "output.txt";

int main(int argc, char *argv[]) {

    string data_file_path = "";
    // Make sure that the argument isn't empty
    if (argv[1] != nullptr) {

        data_file_path = static_cast<string>(argv[1]);

        if (argv[2] != nullptr) {
            string argument2 = static_cast<string>(argv[2]);

            if (argument2 == "search") {

                if (argv[3] != nullptr) {
                    string search_string = static_cast<string>(argv[3]);

                    string_search(data_file_path, search_string);
                } else {
                    cout << "Argument 3 invalid.";

                }

            } else if (argument2 == "sort") {

                if (argv[3] != nullptr) {
                    string sort_order = static_cast<string>(argv[3]);

                    string_sort(data_file_path, sort_order);


                } else {
                    cout << "Argument 3 invalid. You must use asc or desc." << endl;
                }

            } else if (argument2 == "count") {

                string_count(data_file_path);

            } else {
                cout << "Argument 2 invalid." << endl;
            }


        }
    }

    else cout << "No arguments provided.";
    return 0;
}

int string_search(string data_file_path, string search_string){

    int line_number = 0;
    int line_position = 0;
    ifstream data_file;
    ofstream output_file;
    data_file.open(data_file_path);
    output_file.open("./Search_" + OUTPUT_FILE_PATH);

    output_file << "SEARCH" << endl;
            output_file << "Searched for: " << search_string << endl;
    output_file << "Located on:" << endl;
    output_file << "Pos\t\tLine" << endl;
    if (data_file.is_open()) {
        string read_line;
        while (std::getline(data_file, read_line)) {

            line_position = read_line.find(search_string, 0);
            line_number++;


            while (line_position >= 0) {

                output_file << ++line_position << "\t\t" << line_number << endl;
                line_position = read_line.find(search_string, line_position);
            }
        }
        data_file.close();
        output_file.close();
    } else {
        cout << "Error opening the data file." << endl;
    }


    return 0;
}


int string_sort(string data_file_path, string sort_order){

    ofstream output_file;
    output_file.open("./Sort_" + OUTPUT_FILE_PATH);

    if (sort_order != "asc" || sort_order != "desc") {
        output_file << "SORTED " << sort_order << endl;
        ifstream data_file;
        data_file.open(data_file_path);

        if (data_file.is_open()) {
            string read_line;
            while (std::getline(data_file, read_line)) {
                output_file << "Unsorted line: " << read_line << endl;
                char temp_value;

                for (int i = 0; i < read_line.size(); i++) {


                    for (int j = i + 1; j < read_line.size(); j++) {
                        // compare lowercase because lower and upper case letters
                        // have different values

                        if (sort_order == "asc") {
                            if (tolower(read_line[i]) > tolower(read_line[j])) {
                                temp_value = read_line[i];
                                read_line[i] = read_line[j];
                                read_line[j] = temp_value;
                            }
                        } else {

                            if (tolower(read_line[i]) < tolower(read_line[j])) {
                                temp_value = read_line[i];
                                read_line[i] = read_line[j];
                                read_line[j] = temp_value;
                            }
                        }


                    }

                }
                //cout << "sorted line:" << endl;
                output_file << "Sorted line: " << read_line << endl;
            }
        }
        data_file.close();
        output_file.close();
    } else {
        cout << "Argument 3 invalid. You must use asc or desc." << endl;
    }
    return 0;
}


int string_count(string data_file_path){

    ifstream data_file;
    data_file.open(data_file_path);

    ofstream output_file;
    output_file.open("./Count_" + OUTPUT_FILE_PATH);

    output_file << "COUNT" << endl;

    if (data_file.is_open()) {
        const int LETTER_ARRAY_SIZE = 36;
        int line_count =0;

        string read_line;
        while (std::getline(data_file, read_line)) {
            line_count++;
            char letters[LETTER_ARRAY_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                                               'p', 'q', 'r', 's',
                                               't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
                                               '8', '9'};
            int letter_count[LETTER_ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

            for (int i = 0; i < read_line.size(); i++) {
                // cout << static_cast<char>(tolower(read_line[i])) << endl;
                for (int j=0; j < LETTER_ARRAY_SIZE; j++) {

                    if (tolower(read_line[i]) == letters[j]) {

                        letter_count[j]++;
                        //cout << letters[j] << "\t" << letter_count[j] << endl;

                    }
                }
            }
            // get the most used used letter/number
            int largest_count = 0;
            int largest_index = 0;
            int lowest_count = INT_MAX;
            int lowest_index =0;
            for (int i = 0; i < LETTER_ARRAY_SIZE; i++) {

                if (letter_count[i] > largest_count) {
                    largest_count = letter_count[i];
                    largest_index = i;
                }
                if (letter_count[i] < lowest_count && letter_count[i] > 0) {// Don't want to include 0 counts
                    lowest_count = letter_count[i];
                    lowest_index = i;
                }

            }

            output_file << "The most used letter on line " << line_count << " is " << letters[largest_index] <<
            " it was used " << letter_count[largest_index] << " times." << endl;
            output_file << "The least used letter on line " << line_count << " is " << letters[lowest_index] <<
            " it was used " << letter_count[lowest_index] << " times." << endl;

        }


    }

    return 0;
}