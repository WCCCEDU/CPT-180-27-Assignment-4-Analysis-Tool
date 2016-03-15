#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {


    ifstream file;
    file.open ("data.txt");

    const int SIZE = 4;
    string* Lines = new string[SIZE];
    while (!file.eof()) {
        for(int i = 0; i < SIZE -1; i++){
            getline (file,Lines[i]);
        }
    }

    file.close();





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

    //string UserSelection = static_cast<string>(argv[2]);
    //if(argv[1]){

    //}
    //else if(argv[2]) {
        string Mode = "Query";
        if (Mode == "Query") {
            string Query = "the";

            ofstream textfile;
            textfile.open("report");
            textfile << "Searched for: " << Query << endl;
            textfile << "Located on:" << endl;
            textfile << "Pos    Line" << endl;

            int Position = 0;
            while (WordNumber > -1) {
                if (Query == data[WordNumber]) {
                    cout << "Found a match" << '\n';
                    for (int Holder = 0; Holder < WordNumber; Holder++) {
                        int size = data[WordNumber].length();
                        Position = Position + size + 1;
                    }
                    cout << Position << '\n';
                    textfile << Position << endl;
                }
                WordNumber--;
            }
            textfile.close();





        } else if (Mode == "Sort") {
            string SortMode = "desc";

            ofstream textfile;
            textfile.open("report");
            textfile << "File sorted in" << SortMode << 'order:' << endl;

            if (SortMode == "desc") {
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
                    textfile << data[i] << ' ';
                }
            }
            if (SortMode == "asc") {
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
                    textfile << data[i] << ' ';
                }

            } else {
                cout << "Bad SortMode" << endl;
            }
            textfile.close();
        } else if (Mode == "Count") {

        } else {
            cout << "Bad mode" << endl;
        }
    //}



    return 0;

}
