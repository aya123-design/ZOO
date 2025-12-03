#include "Bird.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructeur par défaut
Bird::Bird() : Animal(), wingspan(0.0) {}

// Constructeur paramétré
Bird::Bird(string n, string c, string d, string h, string s, bool pet, 
           int a, double w, double ht, double ws)
    : Animal(n, c, d, h, s, pet, a, w, ht), wingspan(ws) {}

// Constructeur de copie
Bird::Bird(const Bird& other)
    : Animal(other), wingspan(other.wingspan) {}

// Getter pour wingspan
double Bird::getWingspan() const {
    return wingspan;
}

// Setter pour wingspan
void Bird::setWingspan(double ws) {
    wingspan = ws;
}

// Override de printInfo
void Bird::printInfo() const {
    cout << "Animal of type Bird:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
    cout << "Wingspan : " << fixed << setprecision(1) << wingspan << "cm" << endl;
}

// Destructeur
Bird::~Bird() {}