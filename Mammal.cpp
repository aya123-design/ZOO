#include "Mammal.h"
#include <iostream>
using namespace std;

// Constructeur par défaut
Mammal::Mammal() : Animal(), furColor("Unknown") {}

// Constructeur paramétré
Mammal::Mammal(string n, string c, string d, string h, string s, bool pet, 
               int a, double w, double ht, string fur)
    : Animal(n, c, d, h, s, pet, a, w, ht), furColor(fur) {}

// Constructeur de copie
Mammal::Mammal(const Mammal& other)
    : Animal(other), furColor(other.furColor) {}

// Getter pour furColor
string Mammal::getFurColor() const {
    return furColor;
}

// Setter pour furColor
void Mammal::setFurColor(const string& fur) {
    furColor = fur;
}

// Override de printInfo
void Mammal::printInfo() const {
    cout << "Animal of type Mammal:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;
    cout << "Fur Color : " << furColor << endl;
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
}

// Destructeur
Mammal::~Mammal() {}