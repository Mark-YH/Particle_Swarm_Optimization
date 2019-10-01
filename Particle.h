//
// Created by Mark Hsu on 2019-09-28.
//

#ifndef PSO_PARTICLE_H
#define PSO_PARTICLE_H

#define BIT_SIZE 10

class Particle {
public:
    Particle();

//    int getGBestFitness();
//
//    void setGBestFitness(int gBest);
//
//    int *getGBestLocation();
//
//    void setGBestLocation(int index, int location);

    int getPBestFitness();

    void setPBestFitness(int pBest);

    int *getPBestLocation();

    void setPBestLocation(int index, int location);

    int getFitness();

    void setFitness(int fitness);

    int *getVelocity();

    void setVelocity(int index, int velocity);

    int *getLastVelocity();

    void setLastVelocity(int index, int lastVelocity);

    int *getLocation();

    void setLocation(int index, int location);

    int *getLastLocation();

    void setLastLocation(int index, int lastLocation);

private:
    int fitness;
    int velocity[BIT_SIZE];
    int lastVelocity[BIT_SIZE];
    int location[BIT_SIZE];
    int lastLocation[BIT_SIZE];
    int pBestFitness;
    int pBestLocation[BIT_SIZE];
//    int gBestFitness;
//    int gBestLocation[BIT_SIZE];
};

#endif //PSO_PARTICLE_H
