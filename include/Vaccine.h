#include<iostream>
#ifndef VACCINE_H
#define VACCINE_H

class Vaccine{
    private:
        std::string name;
        std::string target_disease;
        double infection_reduction;
        double mortality_reduction;

    public:
        Vaccine(std::string Name, std::string targetDisease, double infectionReduction, double mortalityReduction);

        std::string getName() const;
        std::string getTargetDisease() const;
        double getInfectionReduction() const;
        double getMortalityReduction() const;
};

#endif