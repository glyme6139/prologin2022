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
    if(accroches.size() < 4) return;
    std::vector<std::vector<Stabilisateur>> vecStabilisateurs;
    sort(accroches.begin(), accroches.end());
    int c = 0;
    for(int i = 0; i < k; i++) {
        // vecStabilisateurs.push_back(std::vector<Stabilisateur>());
        std::cout << "-----> Stabilisateur n°" << i << " <-----" << std::endl;
        for(int j = 0; j < accroches.size()-3; j++) {
            std::vector<int> vecAvailableAccroches = accroches;

            int r = p-pow(accroches[j+3]-accroches[j],2);
            std::cout << "Testing for " << accroches[j] << "," << accroches[j+1] << "," << accroches[j+2] << "," << accroches[j+3] << " Score is " << r << std::endl;
            for(int o = 0; o < 4;o++) {
                vecAvailableAccroches.erase(vecAvailableAccroches.begin()+j);
            }
            for(int m = i+1; m < k; m++) {
                int iBest = 0;
                int iBestIndex = -1;
                for(int n = 0; n < vecAvailableAccroches.size()-3; n++) {
                    int value = p-pow(vecAvailableAccroches[n+3]-vecAvailableAccroches[n],2);
                    std::cout << "|-> Testing for " << accroches[n] << "," << accroches[n+1] << "," << accroches[n+2] << "," << accroches[n+3] << " Score is " << r << std::endl;
                    if(value > iBest) {
                        iBest = value;
                        iBestIndex = n;
                    }
                }
            }




            
            // vecStabilisateurs[i].push_back(Stabilisateur{{accroches[j],accroches[j+1],accroches[j+2],accroches[j+3]},r,j});
        }
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
        std::cout << "> " << i << " ";
        for(auto &j : accroches) {
            if(j == i) std::cout << "X";
            else std::cout << "-";
        }
        std::cout << std::endl;
    }
    stabilite_maximale(n, k, p, accroches);
}
