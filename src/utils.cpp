#include "include/utils.h"

vector<int> parse(const vector<string> &xs) {
    vector<int> ys;
    for (const auto& x : xs) {
        ys.push_back(stoi(x));
    }
    return ys;
}

// https://stackoverflow.com/a/46931770
vector<string> split(const string &s, char delim) {
    vector<string> xs;
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        xs.push_back(item);
    }
    return xs;
}

vector<string> read_file(const string& path) {
    std::ifstream file(path);
    string line;
    vector<string> lines;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

int pow_n(int base, int exp) {
    int acc = 1;
    for (int i = 0; i < exp; i++)
        acc *= base;
    return acc;
}
