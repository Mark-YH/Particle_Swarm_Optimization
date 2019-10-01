#include <iostream>
#include "PSO.h"

#define STATISTIC_ROUND 1

int main() {
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < STATISTIC_ROUND; i++) {
        PSO PSO;
        PSO.run();
        PSO.prtResult();
    }

    auto end = std::chrono::steady_clock::now();
    std::cout << "Time taken: " << std::chrono::duration<double>(end - start).count() << "s" << std::endl;
    return 0;
}