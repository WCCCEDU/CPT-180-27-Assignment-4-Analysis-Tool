#include <iostream>
#include <fstream>

using std::string;

int main(int argc, char *argv[]) {

    std::string info_file_path = "";

    if (argv[1]) {
        info_file_path = static_cast<string>(argv[1]);
    }

    if (static_cast<string>(argv[2]) == "count") {
        std::ifstream data_file;
        data_file.open(info_file_path);

        if (data_file.is_open()) {
            const int SIZE = 36;

            char letters_numbers[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                                          'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                                          'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            int amounts[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0,
                                 0, 0, 0, 0};

            while (!data_file.eof()) {
                char data_stuff;
                data_file >> data_stuff;
                std::cout << data_stuff;
                for (int i = 0; i < SIZE - 1; i++) {
                    if (data_stuff == letters_numbers[i]) {
                        amounts[i]++;
                    }
                }
            }for(int i = 0; i < SIZE - 1; i++){
                std::cout << letters_numbers[i] << "=" << amounts[i] << std::endl;
            }
            for (int i = 0; i < SIZE - 1; i++){
                for(int j = 0; j < SIZE-i-1; j++){
                    if( amounts[i] > amounts[j+i]){
                        int temp = amounts[j];
                        amounts[j] = amounts[j+i];
                        amounts[j+i] = temp;
                        char temp2 = letters_numbers[i];
                        letters_numbers[j] = letters_numbers[j+i];
                        letters_numbers[j+i] = temp2;
                    }
                }
            }
        }
        return 0;
    }
}






