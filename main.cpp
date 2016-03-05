#include <iostream>
#include <fstream>
#include <string.h>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

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
                    int line_number = 0;
                    int line_position = 0;
                    ifstream data_file;
                    data_file.open(data_file_path);

                    if (data_file.is_open()) {
                        string read_line;
                        while (std::getline(data_file, read_line)) {

                            line_position = read_line.find(search_string, 0);
                            line_number++;


                            while (line_position >= 0) {
                                cout << "The string " << search_string << " was found on line " << line_number <<
                                " at position " << ++line_position << endl;
                                line_position = read_line.find(search_string, line_position);
                            }
                        }
                        data_file.close();
                    } else {
                        cout << "Error opening the data file." << endl;
                    }
                } else {
                    cout << "Argument 3 invalid.";

                }


            } else if (argument2 == "sort") {

                if (argv[3] != nullptr) {
                    string sort_order = static_cast<string>(argv[3]);

                    if (sort_order != "asc" || sort_order != "desc") {

                        ifstream data_file;
                        data_file.open(data_file_path);

                        if (data_file.is_open()) {
                            string read_line;
                            while (std::getline(data_file, read_line)) {

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
                                cout << "sorted line:" << endl;
                                cout << read_line << endl;
                            }
                        }

                    } else {
                        cout << "Argument 3 invalid. You must use asc or desc." << endl;
                    }
                } else {
                    cout << "Argument 3 invalid. You must use asc or desc." << endl;
                }

            } else if (argument2 == "count") {

                ifstream data_file;
                data_file.open(data_file_path);

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
                        for (int i = 0; i < LETTER_ARRAY_SIZE; i++) {

                            if (letter_count[i] > largest_count) {
                                largest_count = letter_count[i];
                                largest_index = i;
                            }
                        }

                        cout << "The most used letter on line " << line_count << " is " << letters[largest_index] <<
                                " it was used " << letter_count[largest_index] << " times." << endl;

                    }


                }

            } else {
                cout << "Argument 2 invalid." << endl;
            }


        }
    }

    else cout << "No arguments provided.";
    return 0;
}