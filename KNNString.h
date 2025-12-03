#ifndef KNNSTRING_H
#define KNNSTRING_H

#include "KNN.h"
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

class KNNString : public KNN<vector<string>> {
public:
    // Constructeurs
    inline KNNString() : KNN<vector<string>>() {}
    inline KNNString(int kValue) : KNN<vector<string>>(kValue) {}
    
    // Override de la fonction de similarité
    inline double similarityMeasure(const vector<string>& a, 
                                   const vector<string>& b) const override {
        double totalDistance = 0.0;
        
        for (size_t i = 0; i < min(a.size(), b.size()) && i < 4; i++) {
            totalDistance += levenshteinDistance(a[i], b[i]);
        }
        
        return totalDistance;
    }
    
    inline ~KNNString() override {}
    
private:
    // Fonction helper
    inline int levenshteinDistance(const string& s1, const string& s2) const {
        int m = s1.length();
        int n = s2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        
        return dp[m][n];
    }
};

#endif