#include "Zoo.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <map>
using namespace std;

// Initialisation de la capacité maximale
int Zoo::MAX_CAPACITY = 100;

// Constructeur par défaut
Zoo::Zoo() : name("Unknown Zoo") {}

// Constructeur paramétré
Zoo::Zoo(string zooName) : name(zooName) {}

// Constructeur de copie
Zoo::Zoo(const Zoo& other) : name(other.name) {
    for (Animal* animal : other.animals) {
        // NOTE: Ceci est une copie superficielle
        // Pour une vraie copie profonde, il faudrait cloner chaque animal
        animals.push_back(animal);
    }
}

// Destructeur
Zoo::~Zoo() {
    for (Animal* animal : animals) {
        delete animal;
    }
    animals.clear();
}

// Getters/Setters
string Zoo::getName() const {
    return name;
}

void Zoo::setName(const string& zooName) {
    name = zooName;
}

int Zoo::getMaxCapacity() {
    return MAX_CAPACITY;
}

void Zoo::setMaxCapacity(int capacity) {
    MAX_CAPACITY = capacity;
}

int Zoo::getCurrentCount() const {
    return animals.size();
}

// listAnimals
void Zoo::listAnimals() const {
    cout << "Zoo: " << name << endl;
    cout << "Animals (" << animals.size() << "/" << MAX_CAPACITY << "):" << endl;
    cout << "======================================" << endl;
    
    for (size_t i = 0; i < animals.size(); i++) {
        cout << "Animal #" << (i + 1) << ":" << endl;
        animals[i]->printInfo();
        cout << endl;
    }
}

// addAnimal avec lower_bound comme demandé
bool Zoo::addAnimal(Animal* animal) {
    // Vérifier la capacité
    if (animals.size() >= MAX_CAPACITY) {
        cout << "Cannot add " << animal->getName() << ": Zoo is at full capacity!" << endl;
        return false;
    }
    
    string animalName = animal->getName();
    
    // Utiliser lower_bound pour trouver où insérer (ordre alphabétique)
    auto it = lower_bound(animals.begin(), animals.end(), animalName,
        [](Animal* a, const string& name) {
            return a->getName() < name;
        });
    
    // Vérifier si l'animal existe déjà
    if (it != animals.end() && (*it)->getName() == animalName) {
        cout << "Cannot add " << animalName << ": An animal with this name already exists!" << endl;
        return false;
    }
    
    // Insérer à la position trouvée
    animals.insert(it, animal);
    cout << "Successfully added " << animalName << " to the zoo!" << endl;
    return true;
}

// searchAnimalByName avec lower_bound (complexité O(log n))
int Zoo::searchAnimalByName(const string& animalName) const {
    // Utiliser lower_bound pour la recherche binaire
    auto it = lower_bound(animals.begin(), animals.end(), animalName,
        [](Animal* a, const string& name) {
            return a->getName() < name;
        });
    
    // Vérifier si l'animal a été trouvé
    if (it != animals.end() && (*it)->getName() == animalName) {
        return distance(animals.begin(), it);
    }
    
    return -1; // Non trouvé
}

// removeAnimalByName
bool Zoo::removeAnimalByName(const string& animalName) {
    int index = searchAnimalByName(animalName);
    
    if (index == -1) {
        cout << "Animal '" << animalName << "' not found in the zoo!" << endl;
        return false;
    }
    
    // Libérer la mémoire
    delete animals[index];
    
    // Supprimer du vecteur
    animals.erase(animals.begin() + index);
    
    cout << "Successfully removed " << animalName << " from the zoo!" << endl;
    return true;
}

// averageAgeForType
double Zoo::averageAgeForType(const string& type) const {
    int count = 0;
    int totalAge = 0;
    
    for (Animal* animal : animals) {
        // Déterminer le type réel de l'animal
        Mammal* mammal = dynamic_cast<Mammal*>(animal);
        Bird* bird = dynamic_cast<Bird*>(animal);
        Reptile* reptile = dynamic_cast<Reptile*>(animal);
        
        string animalType = "Unknown";
        if (mammal) animalType = "Mammal";
        else if (bird) animalType = "Bird";
        else if (reptile) animalType = "Reptile";
        else animalType = "Animal";
        
        // Comparaison insensible à la casse
        string typeLower = type;
        string animalTypeLower = animalType;
        transform(typeLower.begin(), typeLower.end(), typeLower.begin(), ::tolower);
        transform(animalTypeLower.begin(), animalTypeLower.end(), animalTypeLower.begin(), ::tolower);
        
        if (typeLower == animalTypeLower) {
            count++;
            totalAge += animal->getAge();
        }
    }
    
    if (count == 0) {
        return 0.0;
    }
    
    return static_cast<double>(totalAge) / count;
}

// Opérateur d'affectation
Zoo& Zoo::operator=(const Zoo& other) {
    if (this != &other) {
        // Libérer l'ancienne mémoire
        for (Animal* animal : animals) {
            delete animal;
        }
        animals.clear();
        
        // Copier le nom
        name = other.name;
        
        // Copie des animaux (copie superficielle)
        for (Animal* animal : other.animals) {
            animals.push_back(animal);
        }
    }
    return *this;
}


// FONCTIONS AJOUTÉES POUR LA QUESTION 4 (KNN)

// Fonction helper pour déterminer le type d'un animal
string Zoo::getAnimalType(Animal* animal) const {
    Mammal* mammal = dynamic_cast<Mammal*>(animal);
    Bird* bird = dynamic_cast<Bird*>(animal);
    Reptile* reptile = dynamic_cast<Reptile*>(animal);
    
    if (mammal) return "Mammal";
    else if (bird) return "Bird";
    else if (reptile) return "Reptile";
    else return "Animal";  // Type de base
}

// Fonction helper pour voter (méthode privée)
string Zoo::voteForType(const vector<int>& neighbors, const vector<string>& labels) const {
    map<string, int> voteCount;
    
    // Compter les votes
    for (int index : neighbors) {
        if (index >= 0 && index < (int)labels.size()) {
            string type = labels[index];
            voteCount[type]++;
        }
    }
    
    // Trouver le type avec le plus de votes
    string predictedType = "Unknown";
    int maxVotes = 0;
    
    for (const auto& pair : voteCount) {
        if (pair.second > maxVotes) {
            maxVotes = pair.second;
            predictedType = pair.first;
        }
    }
    
    return predictedType;
}

// Question 4: Implémentation de predictTypeWithKNN
string Zoo::predictTypeWithKNN(Animal* unknownAnimal, int k, const string& dataType) {
    if (animals.empty()) {
        cout << "Erreur: Impossible de prédire, le zoo est vide!" << endl;
        return "Unknown";
    }
    
    if (k <= 0) {
        cout << "Erreur: k doit être positif (k=" << k << ")" << endl;
        return "Unknown";
    }
    
    if (k > (int)animals.size()) {
        cout << "Avertissement: k=" << k << " réduit à " << animals.size() 
             << " (nombre d'animaux dans le zoo)" << endl;
        k = animals.size();
    }
    
    cout << "\n=== Prédiction KNN (k=" << k << ", type de données: " << dataType << ") ===" << endl;
    cout << "Animal à classifier: " << unknownAnimal->getName() << endl;
    
    if (dataType == "numerical") {
        // KNN avec données numériques (weight, height) 
        KNNDouble knn(k);
        
        // 1. Préparer les données d'entraînement
        vector<pair<double, double>> trainData;
        vector<string> trainLabels;
        
        for (Animal* animal : animals) {
            // Données: (weight, height)
            trainData.push_back(make_pair(animal->getWeight(), animal->getHeight()));
            // Labels: type de l'animal
            trainLabels.push_back(getAnimalType(animal));
        }
        
        // 2. Préparer la cible (l'animal inconnu)
        pair<double, double> target = make_pair(unknownAnimal->getWeight(), 
                                                unknownAnimal->getHeight());
        
        cout << "Données de l'animal inconnu: weight=" << target.first 
             << "kg, height=" << target.second << "cm" << endl;
        
        // 3. Trouver les k plus proches voisins
        vector<int> neighbors = knn.findNearestNeighbours(trainData, target);
        
        // 4. Afficher les voisins trouvés
        cout << "Voisins les plus proches:" << endl;
        for (int i = 0; i < (int)neighbors.size(); i++) {
            int idx = neighbors[i];
            Animal* neighbor = animals[idx];
            double distance = knn.similarityMeasure(trainData[idx], target);
            cout << "  " << (i+1) << ". " << neighbor->getName() 
                 << " (" << trainLabels[idx] << "), distance: " 
                 << fixed << setprecision(2) << distance << endl;
        }
        
        // 5. Voter pour le type
        string prediction = voteForType(neighbors, trainLabels);
        cout << "Prédiction: " << prediction << endl;
        return prediction;
        
    } else if (dataType == "categorical") {
        //  KNN avec données catégorielles (color, diet, habitat, sound) 
        KNNString knn(k);
        
        // 1. Préparer les données d'entraînement
        vector<vector<string>> trainData;
        vector<string> trainLabels;
        
        for (Animal* animal : animals) {
            // Données: [color, diet, habitat, sound]
            vector<string> attributes;
            attributes.push_back(animal->getColor());
            attributes.push_back(animal->getDiet());
            attributes.push_back(animal->getHabitat());
            attributes.push_back(animal->getSounds());
            
            trainData.push_back(attributes);
            // Labels: type de l'animal
            trainLabels.push_back(getAnimalType(animal));
        }
        
        // 2. Préparer la cible (l'animal inconnu)
        vector<string> target;
        target.push_back(unknownAnimal->getColor());
        target.push_back(unknownAnimal->getDiet());
        target.push_back(unknownAnimal->getHabitat());
        target.push_back(unknownAnimal->getSounds());
        
        cout << "Données de l'animal inconnu:" << endl;
        cout << "  Couleur: " << target[0] << endl;
        cout << "  Régime: " << target[1] << endl;
        cout << "  Habitat: " << target[2] << endl;
        cout << "  Son: " << target[3] << endl;
        
        // 3. Trouver les k plus proches voisins
        vector<int> neighbors = knn.findNearestNeighbours(trainData, target);
        
        // 4. Afficher les voisins trouvés
        cout << "Voisins les plus proches:" << endl;
        for (int i = 0; i < (int)neighbors.size(); i++) {
            int idx = neighbors[i];
            Animal* neighbor = animals[idx];
            double distance = knn.similarityMeasure(trainData[idx], target);
            cout << "  " << (i+1) << ". " << neighbor->getName() 
                 << " (" << trainLabels[idx] << "), distance: " 
                 << fixed << setprecision(2) << distance << endl;
        }
        
        // 5. Voter pour le type
        string prediction = voteForType(neighbors, trainLabels);
        cout << "Prédiction: " << prediction << endl;
        return prediction;
        
    } else {
        cout << "Erreur: Type de données invalide. Choisir 'numerical' ou 'categorical'" << endl;
        return "Unknown";
    }
}