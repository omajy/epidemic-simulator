#include "Simulation.h"
#include "Population.h"
#include<random>
#include<iostream>

Simulation::Simulation(Population population, Disease disease, int dailyContacts)
    : population(population),
      disease(disease),
      daily_contacts(dailyContacts),
      current_day(0)
      {
      }

int Simulation::getCurrentDay(){
    return current_day;
}

void Simulation::incrementCurrentDay() {
    this->current_day = current_day + 1;
}

void Simulation::simulateDay(){

    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distr(0, population.getPopulationSize() - 1); 
    std::uniform_real_distribution<double> probability(0.0, 1.0);
    std::vector<Person*> newlyInfected;
    
    for (Person& person : population.getPeople()){

        if (person.getHealthState() == HealthStatus::Infected){

               person.incrementDaysInfected();

            if (person.getDaysInfected() > disease.getInfectiousDuration())
            {
                double roll = probability(gen);

                if (roll < disease.getMortalityRate())
                {
                    person.setHealthStatus(HealthStatus::Deceased);
                }
                else
                {
                    person.setHealthStatus(HealthStatus::Recovered);
                }
                continue;
            }

            for(int contacts = 0; contacts < daily_contacts; contacts++){

                int random_index = distr(gen);

                Person& randomPerson = population.getPeople()[random_index];

                if (randomPerson.getHealthState() != HealthStatus::Susceptible)
                {
                    continue;
                }
                else
                {
                    double transmission_odds = randomPerson.getSusceptibility() * disease.getTransmissionProbability();

                    double roll = probability(gen);

                    if (roll < transmission_odds)
                    {
                        newlyInfected.push_back(&randomPerson);
                    }
                }
            }
        }
    }
    for (Person* person : newlyInfected)
        {
            person->setHealthStatus(HealthStatus::Infected);
        }
    incrementCurrentDay();
 }

 void Simulation::simulate(int days) {
    for(int count = 0; count < days; count++){
        simulateDay();
        displayStats();
    }
 }

 void Simulation::displayStats() {
    std::cout << "---------------------" << std::endl;
    std::cout << "Day: " << getCurrentDay() << std::endl;
    std::cout << "Susceptible: " << population.getSusceptible() << std::endl;
    std::cout << "Infected: " << population.getInfected() << std::endl;
    std::cout << "Recovered: " << population.getRecovered() << std::endl;
    std::cout << "Deceased: " << population.getDeceased() << std::endl;
    std::cout << "---------------------" << std::endl;
}