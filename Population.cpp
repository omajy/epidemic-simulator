#include "Population.h"

Population::Population(int populationSize, int initialInfections)
    : susceptible(populationSize - initialInfections),
      infected(initialInfections),
      recovered(0),
      perished(0)
{
}

int Population::getInfected() const{
    return infected;
}

int Population::getSusceptible() const{
    return susceptible;
}

int Population::getRecovered() const{
    return recovered;
}

int Population::getPerished() const{
    return perished;
}