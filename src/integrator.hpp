#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP

#include <vector>
#include "body.hpp"

struct SimParams {
    double G = 1.0;
    double theta = 0.5;
    double softening = 1e-2;
    double dt = 1e-3;
    unsigned numThreads = 4;
};

void computeAcceleration(std::vector<Body>& bodies, const SimParams& p);
void stepLeapfrog(std::vector<Body>& bodies, const SimParams& p);
double totalEnergy(const std::vector<Body>& bodies, double G);
#endif