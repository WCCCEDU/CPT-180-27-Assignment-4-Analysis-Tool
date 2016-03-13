#include <string.h>
#include "analysis_tool.h"



int main(int argc, char* argv[]) {

  string file_path = "";  // Arg 1
  string method = "";  // method provided
  string query = "";  // additional method provided depending on what method method is called

  // argc will be at least one automatically because arg[0] is equal to executable filepath
  if(argc > 1){
    file_path = static_cast<string>(argv[1]);
    if(argc > 2) {
      method = static_cast<string>(argv[2]);
      if (argc > 3) {
        query = static_cast<string>(argv[3]);
      }
    }
  }
  
  //check arguments for errors
  file_path = validateArg1(file_path);
  method = validateArg2(method);
  query = validateArg3(method, query);
  
  //get the number of lines in the file
  const int num_lines = getFileNumLines(file_path);
  ifstream file(file_path);

  file.seekg(0L, file.beg); // should return the read position to beginning of file

  // run tool depending on user selection
  /*if(method == "search"){
      search(file, query);
  }else if(method == "sort"){
    sort(file, query);
   }else if(method == "count"){
   */ count(file_path, num_lines);
  //}
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
string validateArg3(string method, string query){
  if(method == "search"  || method == "sort") {
    if (method == "search") {
      while (query == "") {
        cout << "Query needed for Search Tool. Enter a string value to search for: ";
        cin >> query;
      }
    } else {    //This else handles query if "sort" is provided
      while (query != "asc" && query != "desc") {
        cout << "Order type needed for Sort Tool. Enter either \"asc\" for ascending or \"desc\" for descending: ";
        cin >> query;
      }
    }
  }
  return query;
}

//void search(ifstream file, string arg){}
//void sort(ifstream file, string arg){}
void count(string file_path, const int num_lines){
  const int SIZE = 36;
  const char digits[SIZE] = {'a','b','c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
  't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int occurances[SIZE];  // parallel to digits
  // Initialize all elements of occurances to the value of zero
  for(int i = 0; i < SIZE; i++ ){
    occurances[i] = 0;
  }

  ifstream file(file_path);
  string line;
  while(getline(file, line)){
    for(int current = 0; current < line.size(); current++){
      bool found;
      int index = 0;
      found = false;
      while(!found && index < SIZE) {
        if(line.at(current) == digits[index]) {
          found = true;
          occurances[index] += 1; //Add one to the number of occurances for found digit
        }
        index++;
      }
    }
  }

  //Still needs file output
  for(int i = 0; i < SIZE; i++){
    cout << digits[i] << "\t\t" << occurances[i] << endl;
  }


/*

  // Store lines of file in array of strings
  string lines[num_lines];
  for(int i = 0; i < num_lines; i++){
    getline(file, lines[i]);
    // lines[i] = tokenize(lines[i]);
  }

*/

  file.close();
}

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