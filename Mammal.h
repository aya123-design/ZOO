#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"
#include <iostream>
#include <string>
using namespace std;

class Mammal : public Animal {
private:
    string furColor;

public:
    // Constructeurs
    Mammal();
    Mammal(string n, string c, string d, string h, string s, bool pet, 
           int a, double w, double ht, string fur);
    Mammal(const Mammal& other);
    
    // Getter/Setter pour furColor
    string getFurColor() const;
    void setFurColor(const string& fur);
    
    // Override de printInfo
    void printInfo() const override;
    
    // Destructeur
    ~Mammal();
};

#endif