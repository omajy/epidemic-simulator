#include "Person.h"

Person::Person(int age, double susceptibility)
    : age(age),
      vaccinated(false),
      susceptibility(susceptibility),
      health(HealthStatus::Susceptible),
      days_infected(0)
{
}

void Person::setHealthStatus(HealthStatus value){
    this->health = value;
}

int Person::getAge() const
{
    return age;
}

HealthStatus Person::getHealthState() const
{
    return health;
}

bool Person::isVaccinated() const
{
    return vaccinated;
}

double Person::getSusceptibility() const
{
    return susceptibility;
}

void Person::incrementDaysInfected() {
    this->days_infected = days_infected + 1;
}

int Person::getDaysInfected() const{
    return days_infected;
}
