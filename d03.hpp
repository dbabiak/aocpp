#ifndef AOCPP_D03
#define AOCPP_D03

#include "utils.hpp"

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
    // 110011110101
    vector<int> xs(lines[0].size());

    for (string line : lines)
        for (int i = 0; i < line.size(); i++)
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

    log_bit_vector(gamma_rate);
    log_bit_vector(epsilon_rate);

    int gamma = bit_vector_to_decimal(gamma_rate);
    int epsilon = bit_vector_to_decimal(epsilon_rate);
    return gamma * epsilon;
}




void d03() {
//    vector<string> lines = split(d03_lines, '\n');
    vector<string> lines = read_file("/Users/dmb/o_o/aocpp/data/d03.data");
    auto x = d03_p1(lines);
    cout << x << '\n';
}

#endif // AOCPP_D03