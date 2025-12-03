#ifndef KNNDOUBLE_H
#define KNNDOUBLE_H

#include "KNN.h"
#include <utility>
#include <cmath>
using namespace std;

class KNNDouble : public KNN<pair<double, double>> {
public:
    // Constructeurs
    inline KNNDouble() : KNN<pair<double, double>>() {}
    inline KNNDouble(int kValue) : KNN<pair<double, double>>(kValue) {}
    
    // Override de la fonction de similarité
    inline double similarityMeasure(const pair<double, double>& a, 
                                   const pair<double, double>& b) const override {
        double dx = a.first - b.first;
        double dy = a.second - b.second;
        return sqrt(dx * dx + dy * dy);
    }
    
    inline ~KNNDouble() override {}
};

#endif