#include "Population.h"
#include "Disease.h"
#include "Vaccine.h"
#include "Simulation.h"

int main()
{
    Population adelaide(1000000, 20000);

    Disease corona(
    "corona",
    0.03,
    10,
    18,
    0.001
    );

    Vaccine pfizer("pfizer", "corona", 0.6, 0.7);

    Simulation simulation(adelaide, corona, 10, pfizer);

    simulation.simulate(90);

    simulation.vaccinatePopulation(0.5);

    simulation.simulate(90);

    simulation.exportCSV();

    return 0;
}