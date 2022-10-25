#include <iostream>
#include <vector>
#include <algorithm>

/// \param n le nombre de cinémas
/// \param redirection le lieu de redirection de chaque cinéma
void trajets_retour(int n, const std::vector<int>& redirection) {
    /* TODO Afficher, sur une ligne et séparé par une espace, le nombre de
    redirections nécessaires en partant de chaque cinéma avant de retomber à
    nouveau sur un cinéma déjà visité.  */
    std::string sOutput = "";
    for(int i = 0; i < n; i++) {
        int c = 0;
        int iCurrentRoom = i;
        std::vector<int> vecVisited;
        // std::cout << "Started at " << i << " and did ";
        while(std::find(vecVisited.begin(), vecVisited.end(), iCurrentRoom) == vecVisited.end())
        {
            vecVisited.push_back(iCurrentRoom);
            if (redirection[iCurrentRoom]-1 == iCurrentRoom) break;
            iCurrentRoom = redirection[iCurrentRoom]-1;
            c++;
            if (redirection[i] > n || redirection[i] < 1) break;
            // std::cout << iCurrentRoom;
        }
        // std::cout << std::endl;
        sOutput += std::to_string(c)+" ";
    }
    std::cout << sOutput.substr(0,sOutput.size()-1) << std::endl;


}

int main() {
    int n; ///< le nombre de cinémas
    std::cin >> n;
    if (n < 2 || n > 1000) return 0;
    std::vector<int> redirection(n); ///< le lieu de redirection de chaque cinéma
    for (int& i : redirection)
        std::cin >> i;
    trajets_retour(n, redirection);
}
