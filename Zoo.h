#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "KNN.h"        // ← AJOUTER
#include "KNNDouble.h"  // ← AJOUTER  
#include "KNNString.h"  // ← AJOUTER
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Zoo {
private:
    string name;
    static int MAX_CAPACITY;
    vector<Animal*> animals;

public:
    // Constructeurs
    Zoo();
    Zoo(string zooName);
    Zoo(const Zoo& other);
    
    // Destructeur
    ~Zoo();
    
    // Getters/Setters
    string getName() const;
    void setName(const string& zooName);
    static int getMaxCapacity();
    static void setMaxCapacity(int capacity);
    int getCurrentCount() const;
    
    // Fonctions demandées
    void listAnimals() const;
    bool addAnimal(Animal* animal);
    int searchAnimalByName(const string& animalName) const;
    bool removeAnimalByName(const string& animalName);
    double averageAgeForType(const string& type) const;
    
    // Question 4: Fonction KNN
    string predictTypeWithKNN(Animal* unknownAnimal, int k, const string& dataType);
    
    // Opérateur d'affectation
    Zoo& operator=(const Zoo& other);

private:
    // Fonctions helpers pour KNN
    string getAnimalType(Animal* animal) const;
    string voteForType(const vector<int>& neighbors, const vector<string>& labels) const;
};

#endif