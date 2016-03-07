#include <iostream>
#include <fstream>
#include <string.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::ifstream;

const int SIZE = 30;
string data_file_path="";

int main(int argc, char *argv[]) {

    if(argv[1]){
        data_file_path= static_cast<string>(argv[1]);

    } else if(argv[2]) {
        if (argv[3]) {
            string search_word = static_cast<string>(argv[3]);
            char word[SIZE];
            int line_position = 0;
            string str;
            ifstream file;
            file.open(data_file_path);
            cout << "Enter a word or string of words to search for: ";
            cin.getline(word, SIZE);

            if (file.is_open()) {
                if (file.getline(word, SIZE)) {
                    line_position = str.find(word, 0);
                    cout << "Word" << word << "was found at" << line_position << endl;

                } else {
                    cout << word << "was not found";
                }
                file.close();
            }


        }
    }

    return 0;
}