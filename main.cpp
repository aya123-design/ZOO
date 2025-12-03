#include "Zoo.h"
#include <iostream>
#include <vector>
using namespace std;

void testAnimauxBasiques() {
    cout << "=== TEST 1: Création d'animaux basiques ===" << endl;
    
    Animal animal1("Flash", "Noir", "Carnivore", "Montagnes", "Rugissement", false, 3, 150.5, 100.0);
    Mammal mammal1("Leo", "Doré", "Carnivore", "Savane", "Rugissement", false, 5, 180.5, 120.0, "Fauve");
    Bird bird1("Aigle", "Marron", "Carnivore", "Montagnes", "Cri", false, 3, 5.0, 75.0, 200.0);
    Reptile reptile1("Python", "Vert", "Carnivore", "Jungle", "Sifflement", false, 2, 2.0, 150.0, "Écailles");
    
    cout << "\nAffichage Animal:" << endl;
    animal1.printInfo();
    
    cout << "\nAffichage Mammal:" << endl;
    mammal1.printInfo();
    
    cout << "\nAffichage Bird:" << endl;
    bird1.printInfo();
    
    cout << "\nAffichage Reptile:" << endl;
    reptile1.printInfo();
}

void testZooFonctionsBasiques() {
    cout << "\n\n=== TEST 2: Fonctions basiques du Zoo ===" << endl;
    
    Zoo zoo("Zoo National");
    
    // Test d'ajout d'animaux
    cout << "\n1. Ajout d'animaux:" << endl;
    zoo.addAnimal(new Mammal("Lion", "Doré", "Carnivore", "Savane", "Rugissement", false, 5, 190.0, 120.0, "Fauve"));
    zoo.addAnimal(new Bird("Aigle", "Marron", "Carnivore", "Montagnes", "Cri", false, 3, 5.0, 75.0, 200.0));
    zoo.addAnimal(new Reptile("Serpent", "Vert", "Carnivore", "Jungle", "Sifflement", false, 2, 2.0, 150.0, "Écailles"));
    zoo.addAnimal(new Mammal("Tigre", "Orange", "Carnivore", "Jungle", "Rugissement", false, 4, 200.0, 110.0, "Rayé"));
    zoo.addAnimal(new Bird("Perroquet", "Vert", "Herbivore", "Forêt", "Parle", true, 2, 0.5, 30.0, 50.0));
    
    // Test: tentative d'ajout avec même nom
    cout << "\n2. Tentative d'ajout avec nom existant:" << endl;
    zoo.addAnimal(new Mammal("Lion", "Blanc", "Carnivore", "Savane", "Rugissement", false, 3, 180.0, 115.0, "Blanc"));
    
    // Liste des animaux
    cout << "\n3. Liste des animaux (ordre alphabétique):" << endl;
    zoo.listAnimals();
    
    // Recherche d'animaux
    cout << "\n4. Recherche d'animaux:" << endl;
    int index1 = zoo.searchAnimalByName("Aigle");
    cout << "   Aigle trouvé à l'index: " << index1 << endl;
    
    int index2 = zoo.searchAnimalByName("Elephant");
    cout << "   Elephant trouvé à l'index: " << index2 << " (non existant)" << endl;
    
    // Âge moyen par type
    cout << "\n5. Âge moyen par type:" << endl;
    cout << "   Âge moyen des Mammals: " << zoo.averageAgeForType("Mammal") << " ans" << endl;
    cout << "   Âge moyen des Birds: " << zoo.averageAgeForType("Bird") << " ans" << endl;
    cout << "   Âge moyen des Reptiles: " << zoo.averageAgeForType("Reptile") << " ans" << endl;
    cout << "   Âge moyen des Inconnus: " << zoo.averageAgeForType("Inconnu") << " ans" << endl;
    
    // Suppression d'un animal
    cout << "\n6. Suppression d'un animal:" << endl;
    zoo.removeAnimalByName("Serpent");
    
    // Liste après suppression
    cout << "\n7. Liste après suppression:" << endl;
    zoo.listAnimals();
    
    // Tentative de suppression d'un animal inexistant
    cout << "\n8. Suppression d'un animal inexistant:" << endl;
    zoo.removeAnimalByName("Dragon");
}

void testKNNPrediction() {
    cout << "\n\n=== TEST 3: Prédiction KNN ===" << endl;
    
    Zoo zoo("Zoo de Recherche");
    
    // Création d'une base de données d'entraînement variée
    cout << "\n1. Création de la base d'entraînement:" << endl;
    zoo.addAnimal(new Mammal("Lion", "Jaune", "Carnivore", "Savane", "Rugissement", false, 5, 190.0, 120.0, "Fauve"));
    zoo.addAnimal(new Mammal("Tigre", "Orange", "Carnivore", "Jungle", "Rugissement", false, 4, 200.0, 110.0, "Rayé"));
    zoo.addAnimal(new Mammal("Ours", "Noir", "Omnivore", "Forêt", "Grognement", false, 10, 300.0, 200.0, "Noir"));
    
    zoo.addAnimal(new Bird("Aigle", "Marron", "Carnivore", "Montagnes", "Cri", false, 3, 5.0, 75.0, 200.0));
    zoo.addAnimal(new Bird("Perroquet", "Vert", "Herbivore", "Forêt", "Parle", true, 2, 0.5, 30.0, 50.0));
    zoo.addAnimal(new Bird("Pigeon", "Gris", "Granivore", "Ville", "Roucoulement", false, 1, 0.3, 25.0, 40.0));
    
    zoo.addAnimal(new Reptile("Serpent", "Vert", "Carnivore", "Jungle", "Sifflement", false, 2, 2.0, 150.0, "Écailles"));
    zoo.addAnimal(new Reptile("Lézard", "Vert", "Insectivore", "Désert", "Silence", false, 1, 0.1, 20.0, "Rugueux"));
    zoo.addAnimal(new Reptile("Tortue", "Marron", "Herbivore", "Forêt", "Silence", false, 20, 5.0, 15.0, "Carapace"));
    
    zoo.listAnimals();
    
    // Test 1: Animal similaire à un oiseau (petit et léger)
    cout << "\n2. Test 1 - Animal similaire à un oiseau:" << endl;
    Animal* unknown1 = new Animal("Mystere1", "Gris", "Granivore", "Ville", "Gazouillis", false, 1, 0.4, 28.0);
    
    cout << "\n   a) Prédiction avec données numériques (k=3):" << endl;
    string pred1_num = zoo.predictTypeWithKNN(unknown1, 3, "numerical");
    
    cout << "\n   b) Prédiction avec données catégorielles (k=3):" << endl;
    string pred1_cat = zoo.predictTypeWithKNN(unknown1, 3, "categorical");
    
    // Test 2: Animal similaire à un mammifère (gros et lourd)
    cout << "\n\n3. Test 2 - Animal similaire à un mammifère:" << endl;
    Animal* unknown2 = new Animal("Mystere2", "Noir", "Omnivore", "Forêt", "Grognement", false, 8, 250.0, 180.0);
    
    cout << "\n   a) Prédiction avec données numériques (k=5):" << endl;
    string pred2_num = zoo.predictTypeWithKNN(unknown2, 5, "numerical");
    
    cout << "\n   b) Prédiction avec données catégorielles (k=5):" << endl;
    string pred2_cat = zoo.predictTypeWithKNN(unknown2, 5, "categorical");
    
    // Test 3: Animal avec k trop grand
    cout << "\n\n4. Test 3 - Animal avec k trop grand:" << endl;
    Animal* unknown3 = new Animal("Mystere3", "Vert", "Carnivore", "Jungle", "Sifflement", false, 3, 1.5, 120.0);
    
    cout << "\n   Prédiction avec k=15 (plus grand que le nombre d'animaux):" << endl;
    string pred3 = zoo.predictTypeWithKNN(unknown3, 15, "numerical");
    
    // Test 4: Zoo vide
    cout << "\n\n5. Test 4 - Prédiction avec zoo vide:" << endl;
    Zoo zooVide("Zoo Vide");
    Animal* unknown4 = new Animal("Test", "Rouge", "Herbivore", "Plaine", "Cri", false, 1, 10.0, 50.0);
    string pred4 = zooVide.predictTypeWithKNN(unknown4, 3, "numerical");
    
    // Nettoyage
    delete unknown1;
    delete unknown2;
    delete unknown3;
    delete unknown4;
}

void testFonctionnalitesAvancees() {
    cout << "\n\n=== TEST 4: Fonctionnalités avancées ===" << endl;
    
    Zoo zoo1("Zoo Principal");
    
    // Test de capacité maximale
    cout << "\n1. Test de capacité maximale:" << endl;
    Zoo::setMaxCapacity(3);  // On réduit la capacité pour le test
    
    zoo1.addAnimal(new Mammal("Animal1", "Couleur1", "Diet1", "Habitat1", "Sound1", false, 1, 10.0, 10.0, "Fur1"));
    zoo1.addAnimal(new Bird("Animal2", "Couleur2", "Diet2", "Habitat2", "Sound2", false, 2, 20.0, 20.0, 30.0));
    zoo1.addAnimal(new Reptile("Animal3", "Couleur3", "Diet3", "Habitat3", "Sound3", false, 3, 30.0, 30.0, "Pattern3"));
    
    cout << "\n   Tentative d'ajout au-delà de la capacité:" << endl;
    zoo1.addAnimal(new Mammal("Animal4", "Couleur4", "Diet4", "Habitat4", "Sound4", false, 4, 40.0, 40.0, "Fur4"));
    
    zoo1.listAnimals();
    
    // Test de constructeur de copie
    cout << "\n2. Test de constructeur de copie:" << endl;
    Zoo zoo2 = zoo1;
    zoo2.setName("Zoo Copie");
    cout << "   Zoo copié - Nom: " << zoo2.getName() << endl;
    cout << "   Nombre d'animaux dans la copie: " << zoo2.getCurrentCount() << endl;
    
    // Réinitialisation de la capacité
    Zoo::setMaxCapacity(100);
}

int main() {
    cout << "==========================================" << endl;
    cout << "     TP ZOO - Système de Gestion         " << endl;
    cout << "     avec Algorithme KNN                 " << endl;
    cout << "==========================================" << endl;
    
    try {
        // Test 1: Animaux basiques
        testAnimauxBasiques();
        
        // Test 2: Fonctions basiques du zoo
        testZooFonctionsBasiques();
        
        // Test 3: Prédiction KNN
        testKNNPrediction();
        
        // Test 4: Fonctionnalités avancées
        testFonctionnalitesAvancees();
        
        cout << "\n\n==========================================" << endl;
        cout << "        Tous les tests sont terminés      " << endl;
        cout << "==========================================" << endl;
        
    } catch (const exception& e) {
        cout << "\nErreur lors de l'exécution: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}