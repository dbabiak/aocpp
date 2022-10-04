#include <iostream>
#include <sstream>
#include <vector>
#include "utils.h"
#include <fstream>

using namespace std;

//const char *lines = R"EOF(1721
//979
//366
//299
//675
//1456
//)EOF";

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

int sum(const vector<int>& xs) {
    int acc = 0;
    for (auto x : xs) {
        acc += x;
    }
    return acc;
}

typedef struct {
    int x, y;
} Tuple2;

typedef struct {
    int x, y, z;
} Tuple3;

Tuple2 part_1(vector<int> xs) {
    for (int i = 0; i < xs.size() - 1; i++) {
        for (int j = i + 1; j < xs.size(); j++) {
            if (xs[i] + xs[j] == 2020) {
                return Tuple2 {
                        .x = xs[i],
                        .y = xs[j],
                };
            }
        }
    }
    cout << "wat no answer p1" << std::endl;
    exit(1);
}

Tuple3 part_2(vector<int> xs) {
    for (int i = 0; i < xs.size() - 2; i++) {
        for (int j = i + 1; j < xs.size() - 1; j++) {
            for (int k = j + 1; k < xs.size(); k++) {
                if (xs[i] + xs[j] + xs[k] == 2020) {
                    return Tuple3 {
                        .x = xs[i],
                        .y = xs[j],
                        .z = xs[k],
                    };
                }
            }
        }
    }
    cout << "wat no answer p2" << std::endl;
    exit(2);
}

vector<string> read_file(const string& path) {
    std::ifstream file;
    file.open(path);
    string line;
    vector<string> lines;
    while (file >> line) {
        lines.push_back(line);
    }
    return lines;
}

int main() {

//    vector<string> xs = split(lines, '\n');
    vector<string> xs = read_file("/Users/dmb/o_o/aocpp/data/d01.data");

    vector<int> ys = parse(xs);

    Tuple2 p1 = part_1(ys);

    std::cout << "x: " << p1.x << " y: " << p1.y << std::endl;
    std::cout << p1.x * p1.y << std::endl;

    std::cout << std::endl;

    Tuple3 p2 = part_2(ys);
    std::cout << "x: " << p2.x << " y: " << p2.y << " z: " << p2.z << std::endl;
    std::cout << p2.x * p2.y * p2.z << std::endl;

    return 0;
}
