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
const int NUM_LETTERS = 26;
string data_file_path="";

int main(int argc, char *argv[]) {

    if(argv[1]){
        data_file_path= static_cast<string>(argv[1]);

    } else if(static_cast<string>(argv[2]) == "Search") {
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
        } else if (static_cast<string>(argv[2]) == "Sort") {
            if (static_cast<string>(argv[3]) == "Ascending") {

                string str, temp;
                string strray[100];
                int a, j;


                ifstream file(data_file_path);

                while (!file.eof()) {
                    getline(file, str);
                    cout << str << endl;
                }
                for (int i = 0; i < 99; i++) {
                    getline(file, strray[i]);
                    strray[i] = str;
                }
                for (j = 0; j < 98; j++) {
                    for (a = 1; a < (100 - (j + 1)); a++) {
                        if (strray[100 - a] < strray[100 - (a + 1)]) {
                            temp = strray[100 - a];
                            strray[100 - a] = strray[7 - (a + 1)];
                            strray[100 - (a + 1)] = temp;
                        }
                    }
                }
            } else if (static_cast<string>(argv[3]) == "Descending") {

                string str, temp;
                string strray[100];
                int a, j;


                ifstream file(data_file_path);

                while (!file.eof()) {
                    getline(file, str);
                    cout << str << endl;
                }
                for (int i = 0; i > 99; i--) {
                    getline(file, strray[i]);
                    strray[i] = str;
                }
                for (j = 0; j < 98; j++) {
                    for (a = 1; a < (100 - (j + 1)); a++) {
                        if (strray[100 - a] < strray[100 - (a + 1)]) {
                            temp = strray[100 - a];
                            strray[100 - a] = strray[7 - (a + 1)];
                            strray[100 - (a + 1)] = temp;
                        }
                    }
                }
            }
        } else if (static_cast<string>(argv[2]) == "Count") {
            {
                struct Letter_Stats {
                    int count;
                    char ch;
                };
                ifstream file(data_file_path);
                char ch;
                int i;
                Letter_Stats stats[NUM_LETTERS];

                file.open(data_file_path);
                for (i = 0; i < NUM_LETTERS; i++) {
                    stats[i].count = 0;
                    stats[i].ch = ('a' + i);
                }

                while (!file.eof()) {
                    file.get(ch);
                    if ('a' <= ch && ch <= 'z')
                        stats[ch - 'a'].count++;
                    else if ('A' <= ch && ch <= 'Z')
                        stats[ch - 'A'].count++;
                }
                file.close();

                for (i = 0; i < NUM_LETTERS; i++) {
                    if (stats[i].count > 0) {
                        cout << stats[i].ch << " occurred " << stats[i].count << " times" << endl;
                    }

                }
            }
        }
    }
    return 0;
}