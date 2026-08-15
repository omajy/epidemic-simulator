#include<string>
#ifndef DISEASE_H
#define DISEASE_H

class Disease{
    private:
        std::string name;
        double transmission_probability;
        double mortality_rate;
        int infectious_duration;
        int immunity_duration;
    
    public:
        Disease(std::string diseaseName,
                double transmissionProbability,
                int infectiousDuration, 
                int immunityDuration,
                double mortalityRate);
        
        std::string getName() const;
        double getTransmissionProbability() const;
        double getMortalityRate() const;
        int getInfectiousDuration() const;
        int getImmunityDuration() const;
};

#endif 