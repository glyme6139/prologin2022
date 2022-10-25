#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include<algorithm>
#include<set>


/// \param adore liste des noms du film adoré de chaque personne
/// \param deteste liste des noms du film détesté de chaque personne
void nombre_films(const std::vector<std::string>& adore, const std::vector<std::string>& deteste) {
    /* TODO Afficher, sur une ligne, le nombre de films qui sont uniquement
    adorés. *///     
    std::set<std::string> s(adore.cbegin(), adore.cend());
    const std::vector<std::string>& vecNewAdore = std::vector<std::string>(s.cbegin(), s.cend());
    int c = vecNewAdore.size();
    for(auto &i : vecNewAdore) {
        if(std::find(deteste.begin(), deteste.end(), i) != deteste.end()) c--;
    }
    std::cout << c << std::endl;

}

int main() {
    std::vector<std::string> adore(6); ///< liste des noms du film adoré de chaque personne
    for (std::string& i : adore) {
        std::getline(std::cin >> std::ws, i);
    }
    std::vector<std::string> deteste(6); ///< liste des noms du film détesté de chaque personne
    for (std::string& i : deteste) {
        std::getline(std::cin >> std::ws, i);
    }
    nombre_films(adore, deteste);
}
