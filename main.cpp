#include <string.h>
#include "analysis_tool.h"



int main(int argc, char* argv[]) {

  string arg1 = "";  // filepath
  string arg2 = "";  // method provided
  string arg3 = "";  // additional method provided depending on what arg2 method is called

  // argc will be at least one automatically because arg[0] is equal to executable filepath
  if(argc > 1){
    arg1 = static_cast<string>(argv[1]);
    if(argc > 2) {
      arg2 = static_cast<string>(argv[2]);
      if (argc > 3) {
        arg3 = static_cast<string>(argv[3]);
      }
    }
  }

  arg1 = validateArg1(arg1);
  arg2 = validateArg2(arg2);
  //arg3 = validateArg3(arg2, arg3);

  int num_lines = getFileNumLines(arg1);
  ifstream file(arg1);

  file.seekg(0L, file.beg); // should return the read position to beginning of file

  // Store lines in array of strings
  string lines[num_lines];
  for(int i = 0; i < num_lines; i++){
    getline(file, lines[i]);
    lines[i] = tokenize(lines[i]);
  }

  file.close();

  // run tool depending on user selection
 // if(arg2 == "search"){
  //  search(file, arg3);
 // }else if(arg2 == "sort"){
  //  sort(file, arg3);
 // }else
  //if(arg2 == "count"){
    //count(file);
  //}
  //file.close();
  return 0;
}

/*
 * Argument 1 one should hold a valid filepath upon return
 */
string validateArg1(string arg){
  ifstream file;
  file.open(arg);
  while(!file){
    file.close();
    cout << "File provided could not be located. Enter a file path: ";
    cin >> arg;
    file.open(arg);
  }
  file.close();
  return arg;
}

/*
 * Argument 2 should provide a valid tool choice upon return
 */
string validateArg2(string arg){
  while(arg != "search" && arg != "sort" && arg != "count"){
    cout << "You did not provide a valid method. Enter \"search\", \"sort\", or \"count\": ";
    cin >> arg;
  }
  return arg;
}

/*
 * Argument 3 should provide a valid searchable item or order type upon return if the user chose either sort or
 * search for Argument 2
 */
/*string validateArg3(string arg2, string arg3){
  if(arg2 == "search"  || arg2 == "sort") {
    if (arg2 == "search") {
      while (arg3 == "") {
        cout << "Query needed for Search Tool. Enter a string value to search for: ";
        cin >> arg3;
      }
    } else {    //This else handles arg3 if "sort" is provided
      while (arg3 != "asc" && arg3 != "desc") {
        cout << "Order type needed for Sort Tool. Enter either \"asc\" for ascending or \"desc\" for descending: ";
        cin >> arg3;
      }
    }
  }
  return arg3;
}
 */

//void search(ifstream file, string arg){}
//void sort(ifstream file, string arg){}
/*void count(ifstream file){
  const int SIZE = 36;
  const char digits[SIZE] = {'a','b','c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
  't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int occurances[SIZE];  // parallel to digits

  bool found;
  int index = 0;
  for(string line : lines){ // For each line in lines array

    for(int current = 0; current < line.length(); current++){ // For each character in line
      found = false;
      while (found == false && index <= SIZE) {
        if (line.at(current) == digits[index]) {
          found = true;
          occurances[index]++; //Add one to the number of occurances for found digit
        }
        index++;
      }
    }
  }

  for(int i = 0; i < SIZE; i++){
    cout << digits[i] << "\t\t" << occurances[i] << "endl";
  }
}
*/

void tokenize(string line){

  const int LENGTH = line.size();

  char *tokenized = new char[LENGTH];
  char *tokens = strtok((char *)line.c_str(), " ");

  int count = 0;
  while(tokens){
    tokenized[count++] = *tokens;
    tokens = strtok(NULL," ");
  }

  //Testing
   for(int i = 0; i < LENGTH; i++){
      cout << tokenized[i];
   }
}

int ctoi(char character){
  return character - '0';
}

int getFileNumLines(string path){
  ifstream file(path);
  string line;
  int line_count = 0;
  while(getline(file, line)){
    ++line_count;
  }
  file.close();
  return line_count;
}





