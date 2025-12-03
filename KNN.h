#ifndef KNN_H
#define KNN_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <utility>
using namespace std;

template <typename T>
class KNN {
protected:
    int k;  // nombre de proches voisins

public:
    // Constructeurs
    KNN();  // Constructeur par défaut
    KNN(int kValue);  // Constructeur paramétré
    
    // Getter pour k (seulement un getter demandé)
    int getK() const;
    
    // Fonction pour trouver les k plus proches voisins
    vector<int> findNearestNeighbours(const vector<T>& trainData, const T& target) const;
    
    // Fonction virtuelle pure pour la mesure de similarité
    virtual double similarityMeasure(const T& a, const T& b) const = 0;
    
    // Destructeur virtuel
    virtual ~KNN();
};


template <typename T>
KNN<T>::KNN() : k(3) {}  // k=3 par défaut

template <typename T>
KNN<T>::KNN(int kValue) : k(kValue) {}

template <typename T>
int KNN<T>::getK() const {
    return k;
}

template <typename T>
vector<int> KNN<T>::findNearestNeighbours(const vector<T>& trainData, const T& target) const {
    vector<int> neighbors;
    vector<pair<double, int>> distances;  // (distance, index)
    
    // Calculer les distances pour chaque élément d'entraînement
    for (size_t i = 0; i < trainData.size(); i++) {
        double dist = similarityMeasure(trainData[i], target);
        distances.push_back(make_pair(dist, i));
    }
    
    // Trier par distance croissante
    sort(distances.begin(), distances.end(), 
         [](const pair<double, int>& a, const pair<double, int>& b) {
             return a.first < b.first;
         });
    
    // Prendre les k premiers (ou moins si pas assez de données)
    for (int i = 0; i < min(k, (int)distances.size()); i++) {
        neighbors.push_back(distances[i].second);
    }
    
    return neighbors;
}

template <typename T>
KNN<T>::~KNN() {}

#endif