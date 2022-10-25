
#include <iostream>
#include <vector>
#include <array>
#include <set>

std::string sDebugTree = "|   ";

bool bDebug = false;

float HueToRgb(float p, float q, float t)
{
    if (t < 0.0f) t += 1.0f;
    if (t > 1.0f) t -= 1.0f;
    if (t < 1.0f / 6.0f) return p + (q - p) * 6.0f * t;
    if (t < 1.0f / 2.0f) return q;
    if (t < 2.0f / 3.0f) return p + (q - p) * (2.0f / 3.0f - t) * 6.0f;
    return p;
}

std::array<int,4> HslToRgba(float h, float s, float l, float a = 1)
{
    float r, g, b;

    if (s == 0.0f)
        r = g = b = l;

    else
    {
        double q = l < 0.5f ? l * (1.0f + s) : l + s - l * s;
        double p = 2.0f * l - q;
        r = HueToRgb(p, q, h + 1.0f / 3.0f);
        g = HueToRgb(p, q, h);
        b = HueToRgb(p, q, h - 1.0f / 3.0f);
    }

    return std::array<int,4>{(int)(r * 255), (int)(g * 255), (int)(b * 255), (int)(a * 255)};
}

std::string operator * (std::string a, unsigned int b) {
    std::string output = "";
    while (b--) {
        output += a;
    }
    return output;
}

void PrintColorIndent(int m, int iIndentLevel,bool endl = false) {
    for(int i = 0; i < iIndentLevel; i++) {
        std::array<int,4> color = HslToRgba(((float)360/(m+1)*i)/360,1,0.5);
        std::cout << "\033[38;2;"<< abs(color[0]-1) <<";" << abs(color[1]-1) << ";" << abs(color[2]-1) << "m" << sDebugTree;            
    }
    std::array<int,4> color = HslToRgba(((float)360/(m+1)*(iIndentLevel))/360,1,0.5);
    std::cout << "\033[38;2;"<< abs(color[0]-1) <<";" << abs(color[1]-1) << ";" << abs(color[2]-1) << "m";            
    

    if(endl) std::cout << std::endl;

}

/// \param n Le nombre de points
/// \param m Le nombre de tuyaux
/// \param k Le nombre de degrés minimum de refroidissement
/// \param a Le point de départ
/// \param b Le point d'arrivée
/// \param tuyaux Les tuyaux orientés (point de départ, point d'arrivée, refroidissement)

std::array<int,2> refroidissement(int n, int m, int k, int a, int b, std::vector<std::vector<int>>& tuyaux, int iIndentLevel = 0) {
    /* TODO Afficher le nombre de tuyaux minimal à utiliser pour satisfaire les
    conditions ou, -1 si ce n'est pas possible. */
    int iBestLenght = INT32_MAX;
    int iCooling = -1;
    int iPipeCount = 0;
    std::set<std::vector<int>> s(tuyaux.cbegin(), tuyaux.cend());
    tuyaux = std::vector<std::vector<int>>(s.cbegin(), s.cend());
    if(a == b || k < 0 || iIndentLevel > 2000) return std::array<int,2>{0,0};
    int c = 0;
    for(auto &i : tuyaux) {
        if(i[0] == a && i[1] == b) {
            if(bDebug) {
                PrintColorIndent(m,iIndentLevel);
                std::cout << "Reached end point testing path from " << a << " to " << b << " doing -" << i[2];
            }
            if(i[2] >= k && 1 < iBestLenght) {
                if(bDebug) std::cout << " and is satisfying" << std::endl; 
                return std::array<int,2>{i[2],1}; 
            }
            if(bDebug) std::cout << std::endl;
        }
        if(i[0] == a) {
            std::vector<std::vector<int>> vecAvailableTuyaux = tuyaux;
            if(bDebug) {
                PrintColorIndent(m,iIndentLevel);
                std::cout << "Testing path from " << i[0] << " to " << i[1] << " path must do -" << k <<  std::endl; 
            }

            std::array<int,2> arrScore = refroidissement(n,m,k-i[2],i[1],b,vecAvailableTuyaux,iIndentLevel+1); 
            if(arrScore[0]+i[2] >= k && arrScore[1] < iBestLenght) {
                if(bDebug) {
                    PrintColorIndent(m,iIndentLevel);
                    std::cout << "--->Path " << i[0] << " to " << i[1] << " satisfied requirement -" << k << " with length of " << arrScore[1]+1 << std::endl; 
                }
                iBestLenght = arrScore[1];
                iCooling = i[2]+arrScore[0];
            }
        }
        c++;
    }

    
    if(bDebug) { 
        PrintColorIndent(m,iIndentLevel);
        std::cout << "--->Best path for " << a << " to " << b << " found did -" << iCooling << " in " << iBestLenght+1 << std::endl;
        PrintColorIndent(m,iIndentLevel,true);
    }

    return (iBestLenght == INT32_MAX) ? std::array<int,2>{-1,-1} : std::array<int,2>{iCooling,iBestLenght+1};
}

int main() {
    // std::cout << "\033[38;2;192;192;192m";
    int n; ///< Le nombre de points
    std::cin >> n;
    int m; ///< Le nombre de tuyaux
    std::cin >> m;
    int k; ///< Le nombre de degrés minimum de refroidissement
    std::cin >> k;
    int a; ///< Le point de départ
    std::cin >> a;
    int b; ///< Le point d'arrivée
    std::cin >> b;
    std::vector<std::vector<int>> tuyaux(m); ///< Les tuyaux orientés (point de départ, point d'arrivée, refroidissement)
    for (std::vector<int>& i : tuyaux) {
        i.resize(3);
        for (int& j : i)
            std::cin >> j;
    }
    std::cout << refroidissement(n, m, k, a, b, tuyaux)[1] << std::endl;
}
