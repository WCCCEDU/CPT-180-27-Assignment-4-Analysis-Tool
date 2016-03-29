#include<iostream>
#include<fstream>
#include<string>

//declare the used std
using std::string;
using std::cout;
using std::endl;
using std::find;

//declare the prototype
void squirtle_used(int array[], int size);
void its_not_very_effective(int array[], int size);

int main(int argc, char* argv[] ){

    //declare the variables
    string count, search, sort, asc, dsc;

    if (argc >= 3)
    {
        //allow the user to access
        std::ifstream file(argv[1]);

        //argument sor searching the file
        if (static_cast<string>(argv[2]) == "search")
        {
            int pos = 0;


            if (argc >= 4)
            {
                //set a traget for the search
                string target = static_cast<string>(argv[2]) + " ";

                pos = line.find(target);
                while (pos != string::npos)
                {
                    //output the necessary comments
                    pos = line.substr(pos + target.length,line.length - pos - target.length).find(target);
                }
            }
        }
            //Argument for sorting the file
        else if (static_cast<string>(argv[2]) == "sort")
        {
            if (argc >= 4)
            {
                //argument for choosing which way to sort the file, either ascending or descending
                if (static_cast<string>(argv[3]) == "asc") {

                     void squirtle_used(int array[], int size) {

                            bool swap;
                            int temp;

                            do{
                                swap = false;
                                for (int count = 0; count < (size - 1); count++) {

                                    if (array[count] > array [count + 1]) {

                                        temp = array[count];
                                        array[count] = array[count + 1];
                                        array[count + 1] = temp;
                                        swap = true;
                                    }
                                }
                            } while (swap);
                    } cout << squirtle_used << endl;
                }
                else if (static_cast<string>(argv[3]) == "desc") {

                    void its_not_very_effective(int array[], int size) {

                            bool swap;
                            int temp;

                            do{
                                swap = false;
                                for (int count = 0; count < (size - 1); count--) {

                                    if (array[count] > array [count - 1]) {

                                        temp = array[count];
                                        array[count] = array[count - 1];
                                        array[count - 1] = temp;
                                        swap = true;
                                    }
                                }
                            } while (swap);
                    }cout << its_not_very_effective << endl;
                }
                else {
                    cout << "That is not a valid input my friend :/" << endl;
                }
            }
        }

        //the argument for counting the characters in the file
        //I don't know what to do here
        else if (static_cast<string>(argv[2]) == "count")
        {
            ;
        }

        //lets the user know they
        else {
            cout << "That is not a valid input my friend :/" << endl;
        }
    }
    else {
        std::cout << "That is not a valid input my friend :/" << std::endl;
    }

    return 0;
}

