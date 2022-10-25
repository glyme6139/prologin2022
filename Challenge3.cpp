
#include <iostream>
#include <istream>
#include <string>
#include <vector>

/// \param n Le nombre de mots de passe contenus dans le fichier de mots de passe de Raphaël
/// \param mots La liste des mots de passe à décoder

std::string StringReverse(std::string str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        std::swap(str[i], str[n - i - 1]);
    return str;
}
 

void nb_pas_malin_drome(int n, const std::vector<std::string>& mots) {
    /* TODO Afficher le nombre de pas malin-dromes situés dans le fichier de
    mots de passe de Raphaël  */
    int c = 0;
    for(auto i : mots) {
        std::string sNumber = "";
        std::string sUppercase = "";
        std::string sLowercase = "";
        for(char c : i) {
            if (c > 47 && c < 58) sNumber += c;
            if (c > 64 && c < 91) sUppercase += c;
            if (c > 96 && c < 123) sLowercase += c;
        }
        if(StringReverse(sNumber) == sNumber && StringReverse(sUppercase) == sUppercase && StringReverse(sLowercase) == sLowercase) c++;
    }
    std::cout << c << std::endl;
}

int main() {
    int n; ///< Le nombre de mots de passe contenus dans le fichier de mots de passe de Raphaël
    std::cin >> n;
    if(n < 1 or n > 1000) return 0;
    std::vector<std::string> mots(n); ///< La liste des mots de passe à décoder
    for (std::string& i : mots) {
        std::getline(std::cin >> std::ws, i);
    }
    nb_pas_malin_drome(n, mots);
}
