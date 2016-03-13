//
// Created by Samantha on 3/4/2016.
//

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::iostream;
using std::ifstream;

string validateArg1(string arg);
string validateArg2(string arg);
string validateArg3(string arg2, string arg3);
void tokenize(string line);
int getFileNumLines(string path);

int ctoi(char character);
void search(ifstream file, string arg3);
void sort(ifstream file, string arg3);
void count(string arg1, const int num_lines);
