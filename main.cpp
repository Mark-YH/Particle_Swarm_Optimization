#include "PSO.h"

#define STATISTIC_ROUND 1

void absVersion() {
//    init();
//
//    for (int i = 0; i < 100000; i++) {
//        calcFitness();
//        update();
//        move();
//
//        print();
//        if (isFindBest()) {
//            print(i + 1);
//            break;
//        }
//    }
}

int main() {
    for (int i = 0; i < STATISTIC_ROUND; i++) {
        PSO PSO;
        PSO.run();
        PSO.prtResult();
    }
    return 0;
}