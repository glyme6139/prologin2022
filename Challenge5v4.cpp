#include <iostream>
#include <vector>
#include <bits/stdc++.h>

/// \param n nombre d'accroches
/// \param k nombre de stabilisateurs
/// \param p indice de stabilité parfaite
/// \param accroches hauteur de chaque accroche

int stabilite_maximale(int n, int k, int p, std::vector<int>& accroches) {
    /* TODO Afficher l'indice de stabilité maximal obtenable. */
    if(accroches.size() < 4) return NULL;
    if(k == 0) return NULL;
    sort(accroches.begin(), accroches.end());
    int iBestScore = 0;
    // std::cout << "-----> Stabilisateur n°" << k << " <-----" << std::endl;
    for(int j = 0; j < n-3; j++) { // For each accroche
        std::vector<int> vecAvailableAccroches = accroches;
        int r = p-pow(accroches[j+3]-accroches[j],2);
        // std::cout << "Testing for " << accroches[j] << "," << accroches[j+1] << "," << accroches[j+2] << "," << accroches[j+3] << " Score is " << r << std::endl;
        for(int o = 0; o < 4;o++) {
            vecAvailableAccroches.erase(vecAvailableAccroches.begin()+j);
        }
        int recStabilisateurStability = stabilite_maximale(n-4,k-1,p,vecAvailableAccroches);
        if(r + recStabilisateurStability > iBestScore) {
            iBestScore = r + recStabilisateurStability;
        }
    }
    return iBestScore; 

}

int main() {
    int n; ///< nombre d'accroches
    std::cin >> n;
    int k; ///< nombre de stabilisateurs
    std::cin >> k;
    int p; ///< indice de stabilité parfaite
    std::cin >> p;
    std::vector<int> accroches(n); ///< hauteur de chaque accroche
    for (int& i : accroches)
        std::cin >> i;
    

    // for(int i = *std::max_element(accroches.begin(), accroches.end()); i > *std::min_element(accroches.begin(), accroches.end())-1;i--) {
    //     int c = 0;
    //     std::cout << "> " << i << " ";
    //     for(auto &j : accroches) {
    //         if(j == i) std::cout << "X";
    //         else std::cout << "-";
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << stabilite_maximale(n, k, p, accroches) << std::endl;
}
