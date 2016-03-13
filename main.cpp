#include <iostream>
#include <fstream>


using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::getline;
using std::find;

void search(string, ifstream *, ofstream *);
void sortasc(ifstream *);
void sortdesc(ifstream *);
void count(ifstream *);
int ctoi(char c);


int main (int argc, char *argv[]) {
    ifstream datafile;
    ofstream output;
    string filename = "data.txt";

    if (static_cast<string>(argv[1]) != filename ){
        filename = static_cast<string>(argv[1]);
    }
    datafile.open(filename);
    output.open("output.txt");
    string method = static_cast<string>(argv[2]);


    if (method == "search" ){
        string search_item = static_cast<string>(argv[3]);
        search (search_item, &datafile, &output);
    }
    else if (method == "sort" ){
        string sort = static_cast<string>(argv[3]);
        if (sort == "asc"){
            sortasc(&datafile);
        }
        else if (sort == "desc"){
            sortdesc(&datafile);
        }
    }
    else if (method == "count" ){
        count(&datafile);
    }
    datafile.close();
    output.close();
    return 0;
}

void search(string search_item, ifstream *datafile, ofstream *output) {

    string fileline;
    int linenumber = 0;
    while(*datafile){
        getline(* datafile, fileline);

        if(fileline == ""){
            break;
        }

        int pos = fileline.find(search_item);
        if(pos >=0) {
            cout << "line: " << linenumber << " pos: " << pos << endl;
        }
        linenumber++;

    }

}


void sortasc(ifstream *datafile){
    string fileline;
    while(*datafile) {
        getline(*datafile, fileline);

        int length = fileline.size();
        string *words = new string [length];
        char *tokens = strtok((char *)fileline.c_str(), " ");
        int counter = 0;
        while (tokens) {
            words[counter++] = string(tokens);
            tokens = strtok(NULL, " ");
        }

        for (int i = 0; i < counter - 1; i++){
             int current_pos = i;
              for(int j = i + 1; j < counter; j++){
                if(words[j] < words[current_pos]){
                    current_pos = j;
                }
            }
             string temp = words[i];
                words[i] = words[current_pos];
                words[current_pos] = temp;
        }
        for (int i= 0; i < counter; i++) {
           cout << words[i] << endl;
        }
        }
    }


void sortdesc(ifstream *datafile){
    string fileline;
    while(*datafile) {
        getline(*datafile, fileline);

        int length = fileline.size();
        string *words = new string [length];
        char *tokens = strtok((char *)fileline.c_str(), " ");
        int counter = 0;
        while (tokens) {
            words[counter++] = string(tokens);
            tokens = strtok(NULL, " ");
        }

        for (int i = 0; i < counter - 1; i++) {
            int current_pos = i;
            for(int j = i + 1; j < counter; j++){
                if(words[j] < words[current_pos]){
                    current_pos = j;
                }
            }
            string temp = words[i];
            words[i] = words[current_pos];
            words[current_pos] = temp;
        }
        for (int i = counter; i  >= 0 ; i--){
            cout << words[i] << endl;
        }
        }
    }

void count(ifstream *datafile) {
    string fileline;
    while (*datafile) {
        getline(*datafile, fileline);
        int length = fileline.size();
        int *words = new int[length];
        char *tokens = strtok((char *) fileline.c_str(), " ");
        int counter = 0;
        while (tokens) {
            words[counter++] = ctoi(*tokens);
            tokens = strtok(NULL, " ");
        }

    char[36] = { "a" , "b" , "c" , "d"}
    }
}
int ctoi (char c){
    return c - '0';
}