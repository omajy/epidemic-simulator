#include "Person.h"

Person::Person(int age, double susceptibility)
    : age(age),
      vaccinated(false),
      susceptibility(susceptibility),
      health(HealthStatus::Susceptible)
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