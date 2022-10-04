#ifndef AOCPP_D01
#define AOCPP_D01

#include "utils.hpp"

typedef struct {
    int x, y;
} Tuple2;

typedef struct {
    int x, y, z;
} Tuple3;

Tuple2 d01_p1(vector<int> xs) {
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

Tuple3 d01_p2(vector<int> xs) {
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

void d01() {
    vector<string> xs = read_file("/Users/dmb/o_o/aocpp/data/d01.data");

    vector<int> ys = parse(xs);

    Tuple2 p1 = d01_p1(ys);

    std::cout << "x: " << p1.x << " y: " << p1.y << std::endl;
    std::cout << p1.x * p1.y << std::endl;

    std::cout << '\n';

    Tuple3 p2 = d01_p2(ys);
    std::cout << "x: " << p2.x << " y: " << p2.y << " z: " << p2.z << std::endl;
    std::cout << p2.x * p2.y * p2.z << std::endl;
}
#endif //AOCPP_D01
