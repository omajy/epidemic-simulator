#include "Population.h"
#include "Disease.h"
#include "Vaccine.h"
#include "Simulation.h"

int main()
{
    Population population(100, 5);

    Disease disease(
        "Test Virus",
        0.08,
        5,
        5,
        0.0
    );

    Vaccine vaccine(
        "Test Vaccine",
        "Test Virus",
        0.80,
        0.90
    );

    Simulation simulation(
        population,
        disease,
        8,
        vaccine
    );

    simulation.simulate(10);

    simulation.vaccinatePopulation(0.25);

    simulation.simulate(10);

    simulation.vaccinatePopulation(0.25);

    simulation.simulate(20);

    return 0;
}