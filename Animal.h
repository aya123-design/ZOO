#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    string color;
    string diet;
    string habitat;
    string sounds;
    bool isPet;
    int age;
    double weight;
    double height;

public:
    // Constructeurs
    Animal();
    Animal(string n, string c, string d, string h, string s, bool pet, 
           int a, double w, double ht);
    Animal(const Animal& other);
    
    // Getters
    string getName() const;
    string getColor() const;
    string getDiet() const;
    string getHabitat() const;
    string getSounds() const;
    bool getIsPet() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;
    
    // Setters
    void setName(const string& n);
    void setColor(const string& c);
    void setDiet(const string& d);
    void setHabitat(const string& h);
    void setSounds(const string& s);
    void setIsPet(bool pet);
    void setAge(int a);
    void setWeight(double w);
    void setHeight(double h);
    
    // Méthodes
    void make_sound() const;
    virtual void printInfo() const;
    
    // Destructeur
    virtual ~Animal();
};

#endif