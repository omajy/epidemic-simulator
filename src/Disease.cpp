#include "Disease.h"

Disease::Disease(std::string diseaseName, double transmissionProbability, int infectiousDuration, int immunityDuration, double mortalityRate)
    : name(diseaseName),
      transmission_probability(transmissionProbability),
      infectious_duration(infectiousDuration),
      immunity_duration(immunityDuration),
      mortality_rate(mortalityRate)
{
}

std::string Disease::getName() const{
    return name;
}

double Disease::getTransmissionProbability() const{
    return transmission_probability;
}

int Disease::getInfectiousDuration() const{
    return infectious_duration;
}

int Disease::getImmunityDuration() const{
    return immunity_duration;
}
double Disease::getMortalityRate() const{
    return mortality_rate;
}