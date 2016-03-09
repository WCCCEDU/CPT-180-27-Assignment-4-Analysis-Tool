#include <iostream>
#include <fstream>
#include <string>

using std::string

int main(int argc, char *argv[]) {

    std::string info_file_path = "";

    if(argv[1]) {
        info_file_path = static_cast<string>(argv[1]);
    }

    if(static_cast<string>(argv[2]) == "count") {
        if(argv[3]) {
            std::ifstream data_file;
            data_file.open(info_file_path);

        if (data_file.is_open()) {
            const int SIZE = 36;
            std::string* letters_numbers = new std::string[SIZE];

                char letter_numbers[SIZE] = {'a', 'b', 'c','d', 'e', 'f', 'g' , 'h', 'i', 'j', 'k', 'l',
                                                         'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                                                         'y', 'z', '0', '1', '2', '3' ,'4', '5', '6', '7', '8', '9'};

                int count [SIZE] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                               0,0,0,0};

            for(int i=0; i<SIZE; i++) {
                for(int j = i+1; j < SIZE; j++) {
                    std::cout<< letter_numbers[i] << "  " << letter_numbers[j];

                }
            }
        }

        }
    }

}