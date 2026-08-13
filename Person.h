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
        int days_infected;
    
    public:
        Person(int age, double susceptibility);

        int getAge() const;
        HealthStatus getHealthState() const;
        bool isVaccinated() const;
        double getSusceptibility() const;
        void setHealthStatus(HealthStatus value);
        void incrementDaysInfected();
        int getDaysInfected() const;
};

#endif 