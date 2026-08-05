#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <string>
#include "body.hpp"
#include "integrator.hpp"

std::vector<Body> makeRandomCluster(int n, double radius, double totalMass, unsigned seed);

void runSimulation(std::vector<Body>& bodies, const SimParams& p, int steps, int writeEvery, const std::string& outpath);
#endif