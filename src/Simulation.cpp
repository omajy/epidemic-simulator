#include "Simulation.h"
#include "Population.h"
#include<random>
#include<iostream>
#include<algorithm>
#include <fstream>

Simulation::Simulation(Population population, Disease disease, int dailyContacts, std::optional<Vaccine> vaccine)
    : population(population),
      disease(disease),
      daily_contacts(dailyContacts),
      current_day(0),
      vaccine(vaccine)
      {
        DailyStats initial;

        initial.day = current_day;
        initial.susceptible = this->population.getSusceptible();
        initial.infected = this->population.getInfected();
        initial.recovered = this->population.getRecovered();
        initial.deceased = this->population.getDeceased();
        initial.vaccinated = this->population.getVaccinated();

        history.push_back(initial);
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
        
        if (person.getHealthState() == HealthStatus::Recovered){
            person.incrementDaysRecovered();

            if (person.getDaysRecovered() >= disease.getImmunityDuration()){
                person.resetDaysRecovered();
                person.setHealthStatus(HealthStatus::Susceptible);
            }
        }

        if (person.getHealthState() == HealthStatus::Infected){

            person.incrementDaysInfected();

            double mortality_odds = disease.getMortalityRate();

            if (person.isVaccinated() && vaccine.has_value() && vaccine->getTargetDisease() == disease.getName())
            {
                mortality_odds *= (1.0 - vaccine->getMortalityReduction());
            }

            if (person.getDaysInfected() > disease.getInfectiousDuration())
            {
                double roll = probability(gen);

                if (roll < mortality_odds)
                {
                    person.setHealthStatus(HealthStatus::Deceased);
                }
                else
                {
                    person.setHealthStatus(HealthStatus::Recovered);
                    person.resetDaysInfected();
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

                    if (randomPerson.isVaccinated() && vaccine.has_value() && vaccine->getTargetDisease() == disease.getName())
                    {
                        transmission_odds *= (1.0 - vaccine->getInfectionReduction());
                    }

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

    DailyStats stats;

    stats.day = current_day;
    stats.susceptible = population.getSusceptible();
    stats.infected = population.getInfected();
    stats.recovered = population.getRecovered();
    stats.deceased = population.getDeceased();
    stats.vaccinated = population.getVaccinated();

    history.push_back(stats);
 }

 void Simulation::simulate(int days) {
    for(int count = 0; count < days; count++){
        simulateDay();
        displayStats();
    }
 }

void Simulation::vaccinatePopulation(double percentage)
{
    std::random_device rd; 
    std::mt19937 gen(rd()); 

    auto& people = population.getPeople();
    std::shuffle(people.begin(), people.end(), gen);

    int vaccination_target =
        population.getUnvaccinated() * percentage;

    int vaccinated_count = 0;
    int index = 0;

    while (vaccinated_count < vaccination_target)
    {
        if (!people[index].isVaccinated())
        {
            people[index].setVaccinated();
            vaccinated_count++;
        }
        index++;
    }
}

 void Simulation::displayStats() {
    std::cout << "---------------------" << std::endl;
    std::cout << "Day: " << getCurrentDay() << std::endl;
    std::cout << "Susceptible: " << population.getSusceptible() << std::endl;
    std::cout << "Infected: " << population.getInfected() << std::endl;
    std::cout << "Recovered: " << population.getRecovered() << std::endl;
    std::cout << "Deceased: " << population.getDeceased() << std::endl;
    std::cout << "Vaccinated: " << population.getVaccinated() << std::endl;
    std::cout << "---------------------" << std::endl;
}

void Simulation::exportCSV() {
    
    std::ofstream file("results/simulation.csv");

    file << "day,susceptible,infected,recovered,deceased,vaccinated\n";

    for (const DailyStats& stats : history)
    {
        file << stats.day << ","
             << stats.susceptible << ","
             << stats.infected << ","
             << stats.recovered << ","
             << stats.deceased << ","
             << stats.vaccinated << "\n";
    }
    file.close();
}