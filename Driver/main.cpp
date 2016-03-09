#include "helper.h"
using namespace helper;
int main(int argc, char *argv[]) {
    string file_path = "";
    if (argv[1]) {
        file_path = static_cast<string>(argv[1]);
    }else{
        cout << "file path was not entered. Good Bye\n";
    }
    if (static_cast<string>(argv[2]) == "search" || static_cast<string>(argv[2]) == "find"  ) {
        if (argv[3]) {
            string word = static_cast<string>(argv[3]);
            searchFunction(file_path, word);
        }
    } else if (static_cast<string>(argv[2]) == "sort") {
        if (static_cast<string>(argv[3]) == "asc") {
            ascending_sort(file_path);
        }
        else if(static_cast<string>(argv[3]) == "desc") {
            descending_sort(file_path);
        }
    } else if (static_cast<string>(argv[2]) == "count") {
        count_num_times(file_path);
    }
    return 0;
}

void searchFunction(string file_path, string word) {
    ifstream search_file;
    search_file.open(file_path);
    string string_holder;
    int position = 0;
    int line_position_holder = 0;
    while (getline(search_file, string_holder)){
        position = string_holder.find(word, 0);
        while (position >= 0) {
            cout << "You asked for us to find | " << word << " | the first occurrence starts on line " <<
                    line_position_holder << " and the position of your word is " << position << '\n';
            position++;
            position = string_holder.find(word, position);
        }
        line_position_holder++;
    }
    search_file.close();

}

void ascending_sort(string file_path) {
    ifstream ascending_sort_file;
    ascending_sort_file.open(file_path);
    string file_strings;
    while (getline(ascending_sort_file, file_strings)) {
        if (isdigit(file_strings[0])) {
            int length = file_strings.size();
            int *numbers = new int[length];
            char *tokens =strtok((char *) file_strings.c_str(), " ");
            int counter = 0;
            while (tokens) {
                numbers[counter++] = char_to_integer_conversion(*tokens);
                tokens = strtok(NULL, " ");
            }
            int startScan, minIndex, minValue;
            for (startScan = 0; startScan < (counter - 1); startScan++) {
                minIndex = startScan;
                minValue = numbers[startScan];
                for (int index = startScan + 1; index < counter; index++) {
                    if (numbers[index] < minValue) {
                        minValue = numbers[index];
                        minIndex = index;
                    }
                }
                numbers[minIndex] = numbers[startScan];
                numbers[startScan] = minValue;
            }
            for (int i = 0; i < counter; i++) {
                cout << numbers[i] << " ";
            }
            delete(numbers);
            delete(tokens);
            cout << '\n';
        } else if (isalpha(file_strings[0])) {
            cout << file_strings << '\n';
        }
    }
    ascending_sort_file.close();

}

void descending_sort(string path) {
    //Declarations for count function
    string descending_string_array;
    ifstream descending_sort_file;
    //end Decs
    descending_sort_file.open(path);

    while (getline(descending_sort_file, descending_string_array)) {
        if (isdigit(descending_string_array[0])) {
            int length = descending_string_array.size();
            int *nums = new int[length];
            char *toks = strtok((char *) descending_string_array.c_str(), " ");
            int counter = 0;
            while (toks) {
                nums[counter++] = char_to_integer_conversion(*toks);
                toks = strtok(NULL, " ");
            }
            int startScan, minIndex, maxValue;
            for (startScan = 0; startScan < (counter - 1); startScan++) {
                minIndex = startScan;
                maxValue = nums[startScan];
                for (int index = startScan + 1; index < counter; index++) {
                    if (nums[index] > maxValue) {
                        maxValue = nums[index];
                        minIndex = index;
                    }
                }
                nums[minIndex] = nums[startScan];
                nums[startScan] = maxValue;
            }
            for (int i = 0; i < counter; i++) {
                cout << nums[i] << " ";
            }
            delete(nums);
            delete(toks);
            cout << '\n';
        } else if (isalpha(descending_string_array[0])) {
            cout << descending_string_array << '\n';
        }
    }
    descending_sort_file.close();

}

int char_to_integer_conversion(char conversion_to_int) {
    return conversion_to_int - '0';
}

void count_num_times(string path) {
    //Declarations for count function
    string string_in_file = "";
    int pos = 0;
    int pos_arr = 0;
    char char1st = '0';
    char char2nd = '0';
    const int SIZE = 106;
    int count = 0;
    char array_chars[SIZE];
    int array_counter[SIZE];
    int start_search_point, index_lowest_vale, maximum_value_possible;
    char maximum_characters;
    ifstream count_num_times_file;
    // End Decs

    count_num_times_file.open(path);
    while (getline(count_num_times_file, string_in_file)) {
        int length = string_in_file.size();
        while (pos < length) {
            if (isalnum(string_in_file[pos])) {
                char1st = string_in_file.at(pos);
                array_chars[pos_arr] = char1st;
                for (int i = pos + 1; i < length; i++) {
                    char2nd = string_in_file.at(i);
                    if (char1st == char2nd) {
                        count++;
                    }
                }
                array_counter[pos_arr] = count;
                pos++;
                pos_arr++;
                count = 0;
            } else {
                pos++;
            }
        }
    }

    for (start_search_point = 0; start_search_point < (SIZE - 1); start_search_point++) {
        index_lowest_vale = start_search_point;

        maximum_value_possible = array_counter[start_search_point];
        for (int index = start_search_point + 1; index < SIZE; index++) {
            if (array_counter[index] > maximum_value_possible) {
                maximum_value_possible = array_counter[index];
                maximum_characters = array_chars[index];
                index_lowest_vale = index;
            }
        }
        array_counter[index_lowest_vale] = array_counter[start_search_point];
        array_chars[index_lowest_vale] = array_chars[start_search_point];
        array_counter[start_search_point] = maximum_value_possible;
        array_chars[start_search_point] = maximum_characters;
    }
    cout << "The most common character is " << array_chars[0] << " it is used " << array_counter[0] << " times\n";
    cout << "The least common character is " << array_chars[105] << "it is used " << array_counter[105] << " times\n";
    count_num_times_file.close();

}