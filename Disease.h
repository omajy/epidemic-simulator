#include<string>
#ifndef DISEASE_H
#define DISEASE_H

class Disease{
    private:
        std::string name;
        double transmission_probability;
        double recovery_probability;
        double mortality_rate;
    
    public:
        Disease(std::string diseaseName,
                double transmissionProbability,
                double recoveryProbability, 
                double mortalityRate);
        
        std::string getName() const;
        double getTransmissionProbability() const;
        double getRecoveryProbability() const;
        double getMortalityRate() const;
};

#endif 