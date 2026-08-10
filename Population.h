#ifndef POPULATION_H
#define POPULATION_H

class Population{
    private:
        int susceptible;
        int infected;
        int recovered;
        int perished;
    
    public:
        Population(int populationSize, int initialInfections);

        int getSusceptible() const;
        int getInfected() const;
        int getRecovered() const;
        int getPerished() const;
};

#endif 