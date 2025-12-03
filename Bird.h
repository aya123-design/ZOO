#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <iostream>
#include <string>
using namespace std;

class Bird : public Animal {
private:
    double wingspan;  // envergure

public:
    // Constructeurs
    Bird();
    Bird(string n, string c, string d, string h, string s, bool pet, 
         int a, double w, double ht, double ws);
    Bird(const Bird& other);
    
    // Getter/Setter pour wingspan
    double getWingspan() const;
    void setWingspan(double ws);
    
    // Override de printInfo
    void printInfo() const override;
    
    // Destructeur
    ~Bird();
};

#endif