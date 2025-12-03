#include "Reptile.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructeur par défaut
Reptile::Reptile() : Animal(), scalePattern("Unknown") {}

// Constructeur paramétré
Reptile::Reptile(string n, string c, string d, string h, string s, bool pet, 
                 int a, double w, double ht, string pattern)
    : Animal(n, c, d, h, s, pet, a, w, ht), scalePattern(pattern) {}

// Constructeur de copie
Reptile::Reptile(const Reptile& other)
    : Animal(other), scalePattern(other.scalePattern) {}

// Getter pour scalePattern
string Reptile::getScalePattern() const {
    return scalePattern;
}

// Setter pour scalePattern
void Reptile::setScalePattern(const string& pattern) {
    scalePattern = pattern;
}

// Override de printInfo
void Reptile::printInfo() const {
    cout << "Animal of type Reptile:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
    cout << "Scale Pattern : " << scalePattern << endl;
}

// Destructeur
Reptile::~Reptile() {}