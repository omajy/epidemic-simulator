#include "Disease.h"

Disease::Disease(std::string diseaseName, double transmissionProbability, double recoveryProbability, double mortalityRate)
    : name(diseaseName),
      transmission_probability(transmissionProbability),
      recovery_probability(recoveryProbability),
      mortality_rate(mortalityRate)
{
}

std::string Disease::getName() const{
    return name;
}

double Disease::getTransmissionProbability() const{
    return transmission_probability;
}

double Disease::getRecoveryProbability() const{
    return recovery_probability;
}

double Disease::getMortalityRate() const{
    return mortality_rate;
}