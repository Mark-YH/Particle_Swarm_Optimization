//
// Created by Mark Hsu on 2019-09-28.
//
#include "Particle.h"

Particle::Particle() {
    setFitness(0);
    setPBestFitness(0);
//    setGBestFitness(0);
    for (int i = 0; i < BIT_SIZE; i++) {
        setVelocity(i, 0);
        setLastVelocity(i, 0);
        setLocation(i, 0);
        setLastLocation(i, 0);
        setPBestLocation(i, 0);
//        setGBestLocation(i, 0);
    }
}

int *Particle::getVelocity() {
    return this->velocity;
}

void Particle::setVelocity(int i, int v) {
    this->velocity[i] = v;
}

int *Particle::getLastVelocity() {
    return this->lastVelocity;
}

void Particle::setLastVelocity(int i, int lv) {
    this->lastVelocity[i] = lv;
}

int *Particle::getLocation() {
    return this->location;
}

void Particle::setLocation(int i, int l) {
    this->location[i] = l;
}

int *Particle::getLastLocation() {
    return this->lastLocation;
}

void Particle::setLastLocation(int i, int ll) {
    this->lastLocation[i] = ll;
}

int Particle::getPBestFitness() {
    return this->pBestFitness;
}

void Particle::setPBestFitness(int p) {
    this->pBestFitness = p;
}

//int Particle::getGBestFitness() {
//    return this->gBestFitness;
//}
//
//void Particle::setGBestFitness(int g) {
//    this->gBestFitness = g;
//}

int *Particle::getPBestLocation() {
    return this->pBestLocation;
}

void Particle::setPBestLocation(int i, int l) {
    this->pBestLocation[i] = l;
}

//int *Particle::getGBestLocation() {
//    return this->pBestLocation;
//}
//
//void Particle::setGBestLocation(int i, int l) {
//    this->pBestLocation[i] = l;
//}

int Particle::getFitness() {
    return this->fitness;
}

void Particle::setFitness(int f) {
    this->fitness = f;
}
