#ifndef AOCPP_D02
#define AOCPP_D02

#include "utils.hpp"

const char *d02_lines = R"D02(1-3 a: abcde
1-3 b: cdefg
2-9 c: ccccccccc)D02";

typedef struct {
    int lo, hi;
    char letter;
    string password;
} Policy;

Policy parse_policy(const string& line) {
    int lo, hi;
    char dash, colon, letter;
    string password;
    std::stringstream ss(line);
    ss >> lo >> dash >> hi >> letter >> colon >> password;

    return Policy {
        .lo = lo,
        .hi = hi,
        .letter = letter,
        .password = password,
    };
}

vector<Policy> parse_lines(const vector<string>& lines) {
    vector<Policy> policies;
    for (const auto& line : lines) {
        Policy p = parse_policy(line);
        policies.push_back(p);
    }
    return policies;
};

void log_policy(const Policy& p) {
    cout << "Policy {"
         << "lo: " << p.lo
         << ", hi: " << p.hi
         << ", letter: " << p.letter
         << ", password: " << p.password
         << "}"
         << '\n'
    ;
}

bool is_valid(const Policy& p) {
    int n = count(p.password.begin(), p.password.end(), p.letter);
    return p.lo <= n && n <= p.hi;
}

uint d02_p1(const vector<Policy>& policies) {
    uint n = 0;
    for (const auto& p : policies)
        if (is_valid(p))
            n++;
    return n;
}

bool is_valid_2(const Policy& p) {
    return p.password[p.lo - 1] == p.letter ^ p.password[p.hi - 1] == p.letter;
}

uint d02_p2(const vector<Policy>& policies) {
    uint n = 0;
    for (const auto& p : policies)
        if (is_valid_2(p))
            n++;
    return n;
}

void d02() {
//    vector<string> lines = split(d02_lines, '\n');

    vector<string> lines = read_file("/Users/dmb/o_o/aocpp/data/d02.data");
    vector<Policy> policies = parse_lines(lines);

    cout << d02_p1(policies) << '\n';
    cout << d02_p2(policies) << '\n';
}
#endif // AOCPP_D02