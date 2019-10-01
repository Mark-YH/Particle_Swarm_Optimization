//
// Created by Mark Hsu on 2019-10-01.
//

#ifndef PSO_PSO_H
#define PSO_PSO_H

#include "Particle.h"

#define POPULATION 1000
#define ROUND 50
#define KNAPSACK_SIZE 275
#define C1 1
#define C2 1.5

#define DEBUG_MODE 0

const char name[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
const int weight[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const int value[10] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

class PSO {
private:
    Particle particle[POPULATION];
    int gBestFitness;
    int gBestLocation[BIT_SIZE];

    void calcFitness();

    void update();

    void move();

public:
    PSO();

    ~PSO();

    void run();

    void prtResult();
};

#endif //PSO_PSO_H
