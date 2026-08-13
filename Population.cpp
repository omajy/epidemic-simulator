#include "Population.h"
#include<random>
#include<iostream>

Population::Population(int populationSize, int initialInfections)
{
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distr(1, 99); 
    std::uniform_real_distribution<double> distrib(0.5, 1); 

    int infected = 0;
    
    for(int count = 0; count < populationSize; count++) {

        int age = distr(gen);
        double susceptibility = distrib(gen);

        Person person(age, susceptibility);

        if(infected < initialInfections){
            person.setHealthStatus(HealthStatus::Infected);
            infected++;
        }

        people.push_back(person);
    }
}

int Population::getInfected() const {
    int count = 0;
    for (const Person& person : people) {
        if (person.getHealthState() == HealthStatus::Infected) {
            count++;
        }
    }
    return count;
}

int Population::getSusceptible() const{
    int count = 0;
    for (const Person& person : people) {
        if (person.getHealthState() == HealthStatus::Susceptible) {
            count++;
        }
    }
    return count;
}

int Population::getRecovered() const{
    int count = 0;
    for (const Person& person : people) {
        if (person.getHealthState() == HealthStatus::Recovered) {
            count++;
        }
    }
    return count;
}

int Population::getDeceased() const{
    int count = 0;
    for (const Person& person : people) {
        if (person.getHealthState() == HealthStatus::Deceased) {
            count++;
        }
    }
    return count;
}

int Population::getPopulationSize() const {
    return people.size();
}

std::vector<Person>& Population::getPeople(){
    return people;
}

void Population::display() const {
    
    for (const Person& person : people)
    {
        std::cout << "Age: " << person.getAge() 
                  << ", Susceptibility: " << person.getSusceptibility()
                  << ", Status: ";

        switch (person.getHealthState())
        {
            case HealthStatus::Susceptible:
                std::cout << "Susceptible";
                break;

            case HealthStatus::Infected:
                std::cout << "Infected";
                break;

            case HealthStatus::Recovered:
                std::cout << "Recovered";
                break;

            case HealthStatus::Deceased:
                std::cout << "Deceased";
                break;
        }

        std::cout << '\n';
    }
}