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

            } else if (argument2 == "count") {

            } else {
                cout << "Argument 2 invalid." << endl;
            }


        }
    }

    else cout << "No arguments provided.";
    return 0;
}