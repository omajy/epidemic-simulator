#include<iostream>
#include "Vaccine.h"

Vaccine::Vaccine(std::string Name, std::string targetDisease, double infectionReduction, double mortalityReduction) 
    : name(Name),
      target_disease(targetDisease),
      infection_reduction(infectionReduction),
      mortality_reduction(mortalityReduction)
      {
      }

std::string Vaccine::getName() const{
    return name;
}

std::string Vaccine::getTargetDisease() const{
    return target_disease;
}

double Vaccine::getInfectionReduction() const{
    return infection_reduction;
}

double Vaccine::getMortalityReduction() const{
    return mortality_reduction;
}