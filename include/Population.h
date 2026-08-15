#include<vector>
#include "Person.h"
#ifndef POPULATION_H
#define POPULATION_H

class Population{
    private:
        std::vector<Person> people;
    
    public:
        Population(int populationSize, int initialInfections);

        int getSusceptible() const;
        int getInfected() const;
        int getRecovered() const;
        int getDeceased() const;
        int getPopulationSize() const;
        std::vector<Person>& getPeople();
        void display() const;
        int getUnvaccinated() const;
        int getVaccinated() const;
};

#endif 