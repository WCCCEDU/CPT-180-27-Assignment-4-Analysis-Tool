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
            output << "line: " << linenumber << " pos: " << pos << endl;
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
            ofstream output;
            output << words[i] << endl;
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
            ofstream output;
            output << words[i] << endl;
        }
        }
    }

void count(ifstream *datafile) {
    const int SIZE = 36;
    char characters[SIZE] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l",
                              "m", "n", "o", "p", "q", "r", "s", "t", "u", "v" , "w", "x", "y", "z",
                                "0", "1", "2", "3", "4", "5", "6", "7" , "8", "9"};
    int count[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while(*!datafile.eof()){
        char data_in_file;
        datafile >> data_in_file;
        for (int i = 0; i < SIZE - 1; i++){
            if (data_in_file == characters[i]){
                count[i]++;
            }
        }
    }
    for(int i = 0; i < SIZE - 1; i++){
        for(int j = 0; j < SIZE - i - 1; j++){
            if(count[i] > count[i + 1]){
                int temp = count[j];
                count[j] = count[j + 1];
                count[j + 1] = temp;
                char temp2 = characters[j];
                characters[j] = characters[j + 1];
                characters[j + 1] = temp2;
        }
    }
}
    ofstream output;
    output << "The most used character is " << characters[0] << " used " << count[0] << " times" << endl;
    output << "The least used character is " << characters[SIZE - 1] << " used " << count[36] << " times" << endl;
int ctoi (char c){
    return c - '0';
}