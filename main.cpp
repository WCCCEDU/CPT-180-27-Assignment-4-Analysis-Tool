#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    ifstream file;
    file.open ("data.txt");

    string word;
    int WordNumber = 0;
    string data[100] = {};

    while (file >> word){
        data[WordNumber] = word;
        cout << data[WordNumber] << '\n';
        WordNumber++;
    }
    file.close();


    //if(argv[1]){

    //}else if(argv[2]){
    string Mode = "Sort";
    if (Mode == "Query") {
        string Query = "how";
        int Position = 0;
        while (WordNumber > -1) {
            if (Query == data[WordNumber]) {
                cout << "Found a match" << '\n';
                for (int Holder = 0; Holder < WordNumber; Holder++) {
                    int size = data[WordNumber].length();
                    Position = Position + size + 1;
                }
                cout << Position << '\n';
            }
            WordNumber--;
        }
        ofstream textfile;
        textfile.open("report");
        textfile << "Searched for: " << Query << endl;
        textfile << "Located on:" << endl;
        textfile << "Pos" << endl;
        textfile << Position << endl;
    }else if (Mode == "Sort") {
        string SortMode = "Descending";
        if (SortMode == "Descending") {
            int Size = 100;
            for (int i = 0; i < Size - 1; i++) {
                for (int j = 0; j < Size - i - 1; j++) {
                    if (data[j] > data[j + 1]) {
                        string temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < Size; i++) {
                cout << data[i] << endl;
            }
        }
        if (SortMode == "Ascending"){
            int Size = 100;
            for (int i = 0; i < Size - 1; i++) {
                for (int j = 0; j < Size - i - 1; j++) {
                    if (data[j] < data[j + 1]) {
                        string temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < Size; i++) {
                cout << data[i] << endl;
            }
        }else{
            cout << "Bad SortMode" << endl;
        }
    }else if (Mode == "Count"){
    cout << "DO IT YOURSELF" << endl;
    }else{
        cout << "Bad mode"<<endl;
    }





    //}





    return 0;

}
