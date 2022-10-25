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
    std::vector<std::vector<Stabilisateur>> vecStabilisateurs;
    sort(accroches.begin(), accroches.end());
    int c = 0;
    for(int i = 0; i < k; i++) {
        vecStabilisateurs.push_back(std::vector<Stabilisateur>());
        Stabilisateur stbBestStabilisateur;
        if(accroches.size() < 4) break;
        std::cout << "-----> Stabilisateur n°" << i << " <-----" << std::endl;
        for(int j = 0; j < accroches.size()-3; j++) {
            int r = p-pow(accroches[j+3]-accroches[j],2);
            std::cout << "Testing for " << accroches[j] << "," << accroches[j+1] << "," << accroches[j+2] << "," << accroches[j+3] << " Score is " << r << std::endl;
            vecStabilisateurs[i].push_back(Stabilisateur{{accroches[j],accroches[j+1],accroches[j+2],accroches[j+3]},r,j});
        }
        c++;
    }
    for(auto &i : vecStabilisateurs) {
        for(auto &j : i) {

            std::vector<int> vecAvailableAccroches = accroches;
            
        }
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
