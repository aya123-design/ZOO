#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"
#include <iostream>
#include <string>
using namespace std;

class Reptile : public Animal {
private:
    string scalePattern;  // Motif d'écailles

public:
    // Constructeurs
    Reptile();
    Reptile(string n, string c, string d, string h, string s, bool pet, 
            int a, double w, double ht, string pattern);
    Reptile(const Reptile& other);
    
    // Getter/Setter pour scalePattern
    string getScalePattern() const;
    void setScalePattern(const string& pattern);
    
    // Override de printInfo
    void printInfo() const override;
    
    // Destructeur
    ~Reptile();
};

#endif