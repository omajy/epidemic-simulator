#include "Population.h"
#include "Disease.h"
#include "Vaccine.h"
#include <optional>

#ifndef SIMULATION_H
#define SIMULATION_H

struct DailyStats {
    int day;
    int susceptible;
    int infected;
    int recovered;
    int deceased;
    int vaccinated;
};

class Simulation {
private:
    int current_day;
    Population population;
    Disease disease;
    std::optional<Vaccine> vaccine;
    int daily_contacts;
    std::vector<DailyStats> history;

public:
    Simulation(
        Population population,
        Disease disease,
        int dailyContacts,
        std::optional<Vaccine> vaccine = std::nullopt
    );

    void simulateDay();
    void simulate(int days);
    void displayStats();
    int getCurrentDay();
    void incrementCurrentDay();
    void vaccinatePopulation(double percentage);

    void exportCSV();
};

#endif