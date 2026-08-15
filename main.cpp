#include "Population.h"
#include "Disease.h"
#include "Vaccine.h"
#include "Simulation.h"

int main()
{
    Population population(50000, 100);

    Disease disease(
        "Test Virus",
        0.025,
        10,
        60,
        0.008
    );

    Vaccine vaccine(
        "Test Vaccine",
        "Test Virus",
        0.75,
        0.90
    );

    Simulation simulation(
        population,
        disease,
        12,
        vaccine
    );

    simulation.simulate(30);

    simulation.vaccinatePopulation(0.10);

    simulation.simulate(20);

    simulation.vaccinatePopulation(0.15);

    simulation.simulate(20);

    simulation.vaccinatePopulation(0.20);

    simulation.simulate(110);

    simulation.exportCSV();

    return 0;
}