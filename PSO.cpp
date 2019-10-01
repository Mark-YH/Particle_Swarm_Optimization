//
// Created by Mark Hsu on 2019-10-01.
//

#include "PSO.h"
#include <iostream>
#include <random>

using namespace std;

int myRandom(int start, int end);

PSO::PSO() {
    // Initialize
    for (int i = 0; i < POPULATION; i++) {
        for (int j = 0; j < BIT_SIZE; j++) {
            particle[i].setVelocity(j, myRandom(-10, 10));
            particle[i].setLastVelocity(j, myRandom(-10, 10));
            particle[i].setLocation(j, myRandom(0, 10));
            particle[i].setLastLocation(j, myRandom(0, 10));
        }
    }
}

PSO::~PSO() {
    cout << "end of pso" << endl;
}

void PSO::run() {
    for (int i = 0; i < ROUND; i++) {
        calcFitness();
        update();
        move();
    }
}

void PSO::calcFitness() {
    for (int i = 0; i < POPULATION; i++) {
        int w = 0, v = 0;

        for (int j = 0; j < BIT_SIZE; j++) {
            w += particle[i].getLocation()[j] * weight[j];
            v += particle[i].getLocation()[j] * value[j];
        }

        if (w > KNAPSACK_SIZE) {
            particle[i].setFitness(v * (0.9 - ((w - KNAPSACK_SIZE) / (double) (2 * KNAPSACK_SIZE))));
        } else {
            particle[i].setFitness(v);
        }

#if DEBUG_MODE
        cout << "weight: " << w << endl;
        cout << "value: " << v << endl;
        cout << "fitness: " << particle[i].getFitness() << endl;
#endif

        // Check if it need to update pBest
        if (particle[i].getFitness() > particle[i].getPBestFitness()) {
            particle[i].setPBestFitness(particle[i].getFitness());
            for (int j = 0; j < BIT_SIZE; j++) {
                particle[i].setPBestLocation(j, particle[i].getLocation()[j]);
            }
        }
        // Check if need to update gBest
        if (particle[i].getPBestFitness() > this->gBestFitness) {
            this->gBestFitness = particle[i].getPBestFitness();
            for (int j = 0; j < BIT_SIZE; j++) {
                this->gBestLocation[j] = particle[i].getPBestLocation()[j];
            }
        }
    }
}

void PSO::update() {
    for (int i = 0; i < POPULATION; i++) {
        for (int j = 0; j < BIT_SIZE; j++) {
            particle[i].setVelocity(j, particle[i].getLastVelocity()[j] +
                                       C1 * (myRandom(0, 10) / 10.0) *
                                       (particle[i].getPBestLocation()[j] - particle[i].getLocation()[j]) +
                                       C2 * (myRandom(0, 10) / 10.0) *
                                       (gBestLocation[j] - particle[i].getLocation()[j]));
        }
    }
}

void PSO::move() {
    for (int i = 0; i < POPULATION; i++) {
        for (int j = 0; j < BIT_SIZE; j++) {
            particle[i].setLocation(j, particle[i].getLocation()[j] + particle[i].getVelocity()[j]);
            if (particle[i].getLocation()[j] > 10) {
                particle[i].setLocation(j, 10);
            } else if (particle[i].getLocation()[j] < 0) {
                particle[i].setLocation(j, 0);
            }
            // update location and velocity of next round
            particle[i].setLocation(j, particle[i].getLastLocation()[j]);
            particle[i].setVelocity(j, particle[i].getLastVelocity()[j]);
        }
    }
}

void PSO::prtResult() {
    cout << "gBest fitness: " << this->gBestFitness << endl;
}

int myRandom(int start, int end) {
    random_device rd;
    static default_random_engine gen = default_random_engine(rd());
    uniform_int_distribution<int> dis(start, end);
    return dis(gen);
}
