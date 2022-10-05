#ifndef AOCPP_D03
#define AOCPP_D03

#include "utils.h"
#include <cmath>
#include <utility>

enum BitCriteria {MOST_COMMON, LEAST_COMMON};

const char *d03_lines = R"D03(00100
11110
10110
10111
10101
01111
00111
11100
10000
11001
00010
01010)D03";

void log_bit_vector(const vector<int>& xs) {
    for (auto x : xs)
        cout << x;
    cout << '\n';
}


vector<int> get_counts(const vector<string>& lines) {
    vector<int> xs(lines[0].size());

    for (string line : lines)
        for(int i = 0; i < line.size(); i++)
            if (line[i] == '1')
                xs[i]++;
    return xs;
}

vector<int> get_epsilon_rate(const vector<int>& gamma) {
    vector<int> epsilon;

    for (auto x : gamma)
        epsilon.push_back((x + 1) % 2);

    return epsilon;
}

int bit_vector_to_decimal(const vector<int>& bits) {
    int acc = 0;
    for (int i = 0; i < bits.size(); i++) {
        acc += (bits[bits.size() - i - 1] * pow_n(2, i));
    }
    return acc;
}

int d03_p1(const vector<string>& lines) {
    vector<int> counts = get_counts(lines);
    vector<int> bit_vector;

    uint half = lines.size() / 2;

    for (auto x: counts) {
        int n =  (half <= x) ? 1 : 0;
        bit_vector.push_back(n);
    }

    vector<int> gamma_rate = bit_vector;
    vector<int> epsilon_rate = get_epsilon_rate(gamma_rate);

    int gamma = bit_vector_to_decimal(gamma_rate);
    int epsilon = bit_vector_to_decimal(epsilon_rate);
    return gamma * epsilon;
}

char get_most_common(const vector<string>& xs, int i) {
    int n = 0;

    for (auto x : xs)
        if (x[i] == '1')
            n++;

    int half = round(xs.size()/2.0);
    char result = (half <= n) ? '1' : '0';
    return result;
}


string apply_bit_criteria(vector<string> xs, BitCriteria bit_criteria) {
    // - Keep only numbers selected by the bit criteria for the type of rating value for which you are searching. Discard numbers which do not match the bit criteria.
    // - If you only have one number left, stop; this is the rating value for which you are searching.
    // - Otherwise, repeat the process, considering the next bit to the right
    size_t n = xs[0].size();
    for (int i = 0; i < n; i++) {
        vector<string> filtered;

        char target_bit = get_most_common(xs, i);

        if (LEAST_COMMON == bit_criteria)
            target_bit = (target_bit == '0') ? '1' : '0';

        for (auto x : xs)
            if (x[i] == target_bit)
                filtered.push_back(x);

        if (filtered.size() == 1)
            return filtered[0];

        xs = filtered;
    }
    cerr << "get_co2_rating failed" << '\n';
    exit(1);
}

string get_oxygen_rating(vector<string> xs) {
    return apply_bit_criteria(std::move(xs), MOST_COMMON);
}

string get_co2_rating(vector<string> xs) {
    return apply_bit_criteria(std::move(xs), LEAST_COMMON);
}

vector<int> bs_to_bv(const string& s) {
    vector<int> bv(s.size());

    for (char c : s)
        bv.push_back(c - '0');

    return bv;
}

int d03_p2(const vector<string>& xs) {
    auto co2 = get_co2_rating(xs);
    auto co2_rating = bit_vector_to_decimal(bs_to_bv(co2));


    auto o2 = get_oxygen_rating(xs);
    auto o2_rating = bit_vector_to_decimal(bs_to_bv(o2));

    return o2_rating * co2_rating;
}


void d03() {
//    vector<string> lines = split(d03_lines, '\n');
    vector<string> lines = read_file("/Users/dmb/o_o/aocpp/data/d03.data");
    auto p1 = d03_p1(lines);

    cout << p1 << '\n' ;

    auto p2 = d03_p2(lines);
    cout << p2 << '\n' ;
}

#endif // AOCPP_D03