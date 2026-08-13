#include "Population.h"
#include "Disease.h"
#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation{
    private:
        int current_day;
        Population population;
        Disease disease;
        int daily_contacts;

    public:
        Simulation(Population population, Disease disease, int dailyContacts);
        void simulateDay();
        void simulate(int days);
        void displayStats();
        int getCurrentDay();
        void incrementCurrentDay();
};

#endif 