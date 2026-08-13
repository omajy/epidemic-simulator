#ifndef PERSON_H
#define PERSON_H

enum class HealthStatus{
    Susceptible,
    Infected,
    Recovered,
    Deceased
};

class Person{
    private:
        int age;
        bool vaccinated;
        double susceptibility;
        HealthStatus health;
    
    public:
        Person(int age, double susceptibility);

        int getAge() const;
        HealthStatus getHealthState() const;
        bool isVaccinated() const;
        double getSusceptibility() const;
        void setHealthStatus(HealthStatus value);
};

#endif 