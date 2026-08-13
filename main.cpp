#include "Population.h"
#include "Disease.h"
#include "Simulation.h"

int main()
{
    Population population(500, 3);

    Disease influenza("Influenza", 0.02, 7, 0.0);

    Simulation simulation(population, influenza, 13);

    simulation.simulate(30);
    
    return 0;
}