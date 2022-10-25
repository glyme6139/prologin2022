#include <iostream>
#include <vector>
#include <bits/stdc++.h>

/// \param n nombre d'accroches
/// \param k nombre de stabilisateurs
/// \param p indice de stabilité parfaite
/// \param accroches hauteur de chaque accroche

struct Stabilisateur {
    std::vector<int> vecAccroches;
    int iStability;
    int iIndexOfAccroche;
};


void stabilite_maximale(int n, int k, int p, std::vector<int>& accroches) {
    /* TODO Afficher l'indice de stabilité maximal obtenable. */
    std::vector<Stabilisateur> vecStabilisateurs;
    sort(accroches.begin(), accroches.end());
    std::vector<int> vecAvailableAccroches = accroches;
    int c = 0;
    for(int i = 0; i < k; i++) {
        int iBestScore = 0;
        Stabilisateur stbBestStabilisateur;
        if(vecAvailableAccroches.size() < 4) break;
        for(int j = 0; j < vecAvailableAccroches.size()-3; j++) {
            int r = p-pow(vecAvailableAccroches[j+3]-vecAvailableAccroches[j],2);
            std::cout << "Testing for " << vecAvailableAccroches[j] << "," << vecAvailableAccroches[j+1] << "," << vecAvailableAccroches[j+2] << "," << vecAvailableAccroches[j+3] << " Score is " << r << std::endl;
            if(r > iBestScore) {
                stbBestStabilisateur = Stabilisateur{{vecAvailableAccroches[j],vecAvailableAccroches[j+1],vecAvailableAccroches[j+2],vecAvailableAccroches[j+3]},r,j};
                iBestScore = r;
            }
        }        
        std::cout << "Best score for stabilisateur n°" << c << " is " << iBestScore << " using ";
        for(auto &j : stbBestStabilisateur.vecAccroches) {
            std::cout << j << ",";
            vecAvailableAccroches.erase(vecAvailableAccroches.begin()+stbBestStabilisateur.iIndexOfAccroche);
        }
        std::cout << std::endl;
        c++;
    }

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
    

    for(int i = *std::max_element(accroches.begin(), accroches.end()); i > *std::min_element(accroches.begin(), accroches.end())-1;i--) {
        int c = 0;
        for(auto &j : accroches) {
            if(j == i) std::cout << "X";
            else std::cout << "-";
        }
        std::cout << std::endl;
    }
    stabilite_maximale(n, k, p, accroches);
}
