//
// Created by Daniel Babiak on 2022-10-04.
//
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#include "utils.h"

vector<int> parse(const vector<string> &xs) {
    vector<int> ys;
    for (const auto& x : xs) {
        ys.push_back(stoi(x));
    }
    return ys;
}
