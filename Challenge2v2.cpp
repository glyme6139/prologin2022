
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

/// \param n Le nombre de boîtes et de restes
/// \param restes Liste des volumes des restes
/// \param boites Liste des volumes des boîtes
void mise_en_boite(int n, std::unordered_set<int>& restes, std::unordered_set<int>& boites) {
    /* TODO Afficher sur une ligne le nombre maximum de restes que l'on peut
    mettre en boîte. */
    int c = 0;

    for(auto &i : restes) {
        int bf = INT32_MAX;
        int bfi = -1;
        int k = 0;
        for(auto &j : boites) {
            if(i < j && j < bf) {
                bf = j;
                bfi = k;
            }
            k++;
        }
        if (bfi != -1){
            c++;
            boites.erase(bfi);
        } 
    }
    std::cout << c << std::endl;
}

int main() {
    int n; ///< Le nombre de boîtes et de restes
    std::cin >> n;
    std::unordered_set<int> restes(n); ///< Liste des volumes des restes
    for (int i : restes)
        std::cin >> i;
    std::unordered_set<int> boites(n); ///< Liste des volumes des boîtes
    for (int i : boites)
        std::cin >> i;
    std::cout << restes.size() << std::endl;
    std::cout << boites.size() << std::endl;
    mise_en_boite(n, restes, boites);
}
