#include <iostream>
#include <fstream>

using std::string;
using std::ifstream;

void search();
void sortasc();
void sortdesc();
void count();
int main (int argc, char *argv[]) {

    if (static_cast<string>(argv[1]) == "data.txt" ){
         ("data.txt");
    }
    if (static_cast<string>(argv[2]) == "search" ){
        if (argv[3]){
            string search_item = static_cast<string>(argv[3]);
            search();
        }
    }
    else if (static_cast<string>(argv[2]) == "sort" ){
        if (static_cast<string>(argv[3]) == "asc"){
        sortasc();
        }
        else if (static_cast<string>(argv[3]) == "desc"){
        sortdesc();
        }
        }
    else if (static_cast<string>(argv[2]) == "count" ){
    count();
    }
    return 0;
}
void search(string search_item) {

    int position = 0;
    int line = 0;
    ifstream data_file;
    if (data_file.is_open()) {
        while (!data_file.eof()) {
            
        }
    }
}