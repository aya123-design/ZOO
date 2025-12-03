#include "Animal.h"
#include <iostream>
using namespace std;

// Constructeur par défaut
Animal::Animal() : name("Unknown"), color("Unknown"), diet("Unknown"), 
                   habitat("Unknown"), sounds("Unknown"), isPet(false), 
                   age(0), weight(0.0), height(0.0) {}

// Constructeur paramétré
Animal::Animal(string n, string c, string d, string h, string s, bool pet, 
               int a, double w, double ht) 
    : name(n), color(c), diet(d), habitat(h), sounds(s), 
      isPet(pet), age(a), weight(w), height(ht) {}

// Constructeur de copie
Animal::Animal(const Animal& other)
    : name(other.name), color(other.color), diet(other.diet),
      habitat(other.habitat), sounds(other.sounds), isPet(other.isPet),
      age(other.age), weight(other.weight), height(other.height) {}

// Getters
string Animal::getName() const { return name; }
string Animal::getColor() const { return color; }
string Animal::getDiet() const { return diet; }
string Animal::getHabitat() const { return habitat; }
string Animal::getSounds() const { return sounds; }
bool Animal::getIsPet() const { return isPet; }
int Animal::getAge() const { return age; }
double Animal::getWeight() const { return weight; }
double Animal::getHeight() const { return height; }

// Setters
void Animal::setName(const string& n) { name = n; }
void Animal::setColor(const string& c) { color = c; }
void Animal::setDiet(const string& d) { diet = d; }
void Animal::setHabitat(const string& h) { habitat = h; }
void Animal::setSounds(const string& s) { sounds = s; }
void Animal::setIsPet(bool pet) { isPet = pet; }
void Animal::setAge(int a) { age = a; }
void Animal::setWeight(double w) { weight = w; }
void Animal::setHeight(double h) { height = h; }

// Méthode make_sound
void Animal::make_sound() const {
    cout << sounds << endl;
}

// Méthode printInfo
void Animal::printInfo() const {
    cout << "Animal of unkwn type:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
   
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
}

// Destructeur
Animal::~Animal() {}