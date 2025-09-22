#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "Graf.h"
#include "GrafPonderat.h"


bool comparaCicle(std::string cicleEsperat[], std::vector<std::vector<int>>& ciclesGraf, std::vector<std::string>& noms_nodes, int posCicle)
{
    bool iguals = true;
    int i = 0;
    while (iguals && (i < 3))
    {
        int j = 0;
        iguals = false;
        while (!iguals && (j < 3))
        {
            if (cicleEsperat[i] == noms_nodes[ciclesGraf[posCicle][j]])
                iguals = true;
            else
                j++;
        }
        i++;
    }
    return iguals;
}

bool comparaCicles(std::string ciclesEsperats[][3], std::vector<std::vector<int>>& ciclesGraf, std::vector<std::string>& noms_nodes, int nCiclesEsperats)
{
    bool iguals = (ciclesGraf.size() == nCiclesEsperats);
    int i = 0;
    while (iguals && (i < nCiclesEsperats))
    {
        int j = 0;
        iguals = false;
        while (!iguals && (j < ciclesGraf.size()))
        {
            if (comparaCicle(ciclesEsperats[i], ciclesGraf, noms_nodes, j))
                iguals = true;
            else
                j++;
        }
        i++;
    }
    return iguals;
}

bool comparaGrafPonderat(const std::string& mostraEstudiant)  {

    std::vector<int> sumaPesos = {
            624,
            1506,
            3642,
            2696,
            4053,
            3187,
            2224,
            3429,
            2096,
            1453,
            2172,
            2730,
            1680,
            3140,
            4185,
            1141,
            5274,
            3401,
            2143,
            3830,
            2092,
            894,
            1068,
            1588,
            3494,
            2928,
            2235,
            4123,
            2350,
            3955,
            998,
            597,
            1509,
            1821,
            637,
            1262,
            1426,
            839,
            2689,
            3204,
            2548,
            4560,
            1451,
            2163,
            2726,
            3300,
            1633,
            647,
            2105,
            1482,
            2546,
            3032,
            1912
    };

    std::istringstream si(mostraEstudiant);
    std::string line;

    int i = -1;
    while (std::getline(si, line, '\n')) {
        bool skip = true;
        std::istringstream sii(line);
        std::string number;
        std::string name;
        unsigned int sumaPesosResultat = 0;
        while(sii >> number) {
            if (skip) {
                name = number;
                skip = false;
            } else {
                sumaPesosResultat += std::atol(number.c_str());
            }
        }
        if (i > -1) {
            // Skip primer per tema formateig del mostra()
            if (sumaPesosResultat != sumaPesos[i]) {
                return false;
            }
        }

        i++;
    }

    return true;
}


int main()
{
    float grade = 0.0;
    bool valid = true;

    int numNodes = 53;

    std::vector<std::string> noms_nodes;
    noms_nodes.resize(numNodes);
    noms_nodes = {"Pl. Sants","Hostafr.","Esp.","Roc.","Urgell","Univ.","Cat.",
                  "Urq.","Triomf","Marina","Glories","Clot","Navas","Sagrera",
                  "Paral·lel","St. Ant.","Pg. Gracia","Tetuan","Monumental",
                  "S. Familia","Encants","Bac Roda","Sant Marti","La Pau",
                  "Sants Est.","Tarragona","Poble Sec","Drassanes","Liceu",
                  "Diagonal","Besos","Besos Mar","El Maresme","Selva Mar",
                  "Poblenou","Llacuna","Bogatell","Ciutadella","Barcelone.",
                  "Jaume I","Girona","Verdaguer","Joanic","Alfons X",
                  "Guinardo","Maragall","Llucmajor","Via Julia",
                  "Entença","H. Clinic","Sant Pau","Camp Arpa","Congres"};

    std::vector<std::vector<int>> parells_parades;
    
    parells_parades = { {0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},
                        {9,10},{10,11},{11,12},{12,13},{14,15},{15,5},{5,16},
                        {16,17},{17,18},{18,19},{19,20},{20,11},{11,21},{21,22},
                        {22,23},{24,25},{25,2},{2,26},{26,14},{14,27},{27,28},
                        {28,6},{6,16},{16,29},{23,30},{30,31},{31,32},{32,33},
                        {33,34},{34,35},{35,36},{36,37},{37,38},{38,39},{39,7},
                        {7,16},{16,40},{40,41},{41,42},{42,43},{43,44},{44,45},
                        {45,46},{46,47},{0,24},{24,48},{48,49},{49,29},{29,41},
                        {41,19},{19,50},{50,51},{51,13},{13,52},{52,45}};

    std::vector<int> pesos = {511,995,425,2271,1782,787,375,1603,493,960,1212,499,1181,
                         647,494,124,1794,1607,536,1781,311,708,186,882,1796,1132,
                         1090,1145,2393,1730,620,442,1654,706,292,305,1204,617,20,
                         1242,184,655,2034,1170,281,979,1569,990,461,1702,1024,986,
                         647,113,1585,520,962,1339,662,851,1695,1337,622,1290 }; //64 pesos
    
    Graf g(noms_nodes, parells_parades);

    g.mostra();
    std::cout << "Comment :=>> ==============================================" << std::endl;
    std::cout << "Comment :=>> Graf creat                                    " << std::endl;
    std::cout << "Comment :=>> ==============================================" << std::endl;

    //std::cout << "PAUSE" << std::endl;
    //std::cin.get();

    // TEST CICLES DEL GRAF
    std::cout << "Comment :=>> " << std::endl;
    std::cout << "Comment :=>> ==============================================" << std::endl;
    std::cout << "Comment :=>> Test del metode per trobar els cicles del graf" << std::endl;

    std::vector<std::vector<int>> cicles = g.cicles();
    for (size_t i = 0; i < cicles.size(); i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << noms_nodes[cicles[i][j]] << " ";
        }
        std::cout << std::endl;
    }

    const int MAX_CICLES = 2;
    std::string ciclesEsperats[MAX_CICLES][3] =
    {
      {"Univ.","Cat.","Pg. Gracia"},
      {"Cat.","Urq.","Pg. Gracia"}
    };

    std::cout << "Comment :=>> Resultat esperat: " << std::endl;
    for (int i = 0; i < MAX_CICLES; i++)
        std::cout << "Comment : = >> " << ciclesEsperats[i][0] << ", " << ciclesEsperats[i][1] << ", " << ciclesEsperats[i][2] << std::endl;
    std::cout << "Comment :=>> ---" << std::endl;
    std::cout << "Comment :=>> Resultat obtingut: " << std::endl;
    for (size_t i = 0; i < cicles.size(); i++)
        std::cout << "Comment : = >> " << noms_nodes[cicles[i][0]] << ", "
             << noms_nodes[cicles[i][1]] << ", " << noms_nodes[cicles[i][2]] << std::endl;

    bool correcte = comparaCicles(ciclesEsperats, cicles, noms_nodes, MAX_CICLES);

    if (correcte) {
        std::cout << "Comment :=>> CORRECTE" << std::endl;
        grade += 5.0;
    }
    else
    {
        std::cout << "Comment :=>> ERROR" << std::endl;
        valid = false;
    }
    std::cout << "Comment :=>> " << std::endl;
    std::cout << "Comment :=>> ==============================================" << std::endl;

    //std::cout << "PAUSE" << std::endl;
    //std::cin.get();
    GrafPonderat gP(noms_nodes, parells_parades, pesos);
    // Acquire buffer
    std::stringstream  buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    gP.mostra();
    std::string resultEstudiant = buffer.str();
    std::cout.rdbuf(old);
    // Reset buffer
    gP.mostra();
    if ( comparaGrafPonderat(resultEstudiant) ) {
        grade += 5;
    } else {
        std::cout << "Comment :=>> ERROR" << std::endl;
        valid = false;
    }
    std::cout << "Comment :=>> ==============================================" << std::endl;
    std::cout << "Comment :=>> Graf ponderat creat                           " << std::endl;
    std::cout << "Comment :=>> ==============================================" << std::endl;

    std::cout << "Comment :=>> ==================================================================" << std::endl;
    if (valid)
        std::cout << "Comment :=>> Final del test sense errors" << std::endl;

    std::cout << "Comment :=>> " << std::endl << "Grade :=>> " << grade << std::endl;

    return 0;
}
