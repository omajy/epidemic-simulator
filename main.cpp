#include <iostream>
#include "Population.h"
#include "Disease.h"

int main() {

    Population population(696969, 420);

    std::cout << population.getInfected() << " "
              << population.getPerished() << " "
              << population.getRecovered() << " "
              << population.getSusceptible()
              << std::endl;

    Disease disease("corona", 0.77666, 0.69, 0.001);

    std::cout << disease.getMortalityRate() << " "
              << disease.getName() << " "
              << disease.getRecoveryProbability() << " "
              << disease.getTransmissionProbability()
              << std::endl;

    return 0;
}