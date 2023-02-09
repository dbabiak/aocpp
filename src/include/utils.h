#ifndef AOCPP_UTILS_H
#define AOCPP_UTILS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

//const char *lines = R"EOF(1721
//979
//366
//299
//675
//1456
//)EOF";

vector<int> parse(const vector<string> &xs);

// https://stackoverflow.com/a/46931770
vector<string> split(const string &s, char delim);

vector<string> read_file(const string& path);

int pow_n(int base, int exp);
#endif //AOCPP_UTILS_H
