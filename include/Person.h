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
        int days_recovered;
    
    public:
        Person(int age, double susceptibility);

        int getAge() const;
        HealthStatus getHealthState() const;
        bool isVaccinated() const;
        double getSusceptibility() const;
        void setHealthStatus(HealthStatus value);
        void incrementDaysInfected();
        int getDaysInfected() const;
        void resetDaysInfected();
        void setVaccinated();
        void incrementDaysRecovered();
        int getDaysRecovered() const;
        void resetDaysRecovered();
};

#endif 