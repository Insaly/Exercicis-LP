#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include "graf.h"

using namespace std;

void mostraNodes(std::vector<string> &nodes)
{
	cout << "[";
	if (nodes.size() > 0)
	{
		for (int i = 0; i < nodes.size() - 1; i++)
		{
			cout << nodes[i] << ",";
		}
		cout << nodes[nodes.size() - 1];
	}
	cout << "]";
}

bool igualsLlistaNodes(std::vector<string> &resultat, std::vector<string> &esperat)
{
	bool iguals = (esperat.size() == resultat.size());

	int i = 0;
	while ((i < esperat.size()) && iguals)
	{
		iguals = false;
		int j = 0;
		while ((j < resultat.size()) && !iguals)
		{
			if (resultat[j] == esperat[i])
				iguals = true;
			else j++;
		}
		i++;
	}
	return iguals;
}

bool igualsComponents(const std::vector<std::vector<string>>& resultat, const std::vector<set<string>>& esperat) {
    if (resultat.size() != esperat.size()) {
        return false;
    }

    std::vector<bool> visitat(esperat.size(), false);

    for (int i = 0; i < resultat.size(); i++) {
        for (int j = 0; j < esperat.size(); j++) {
            for (int k = 0; k < resultat[i].size(); k++) {
                if (esperat[j].find(resultat[i][k]) != esperat[j].end() && esperat[j].size() == resultat[i].size() ) {
                    visitat[j] = true;
                }
            }
        }
    }

    for (bool visits: visitat) {
        if (!visits)
            return false;
    }

    return true;
}



float testConjuntConnectats()
{
	float reduccio = 0.0;

	int numNodes;

	vector<int> pesos;

	const int N_PROVES = 2;
	vector<set<string>> resultat[N_PROVES] =
	{
		{  {"A", "B", "C"}, {"E", "D"}},
        {  {"A", "B", "E"}, {"F", "G"}, {"C", "D", "H"}},
	};

    vector<vector<string>> nodes =
    {
        { "A","B","C","D","E"},
        { "A", "B", "C", "D", "E", "F", "G", "H"}
    };

    vector<vector<vector<int>>> arestes =
    {
        { {0, 2}, {2, 0}, {1, 0}, {1, 2}, {2, 1}, {1, 4}, {3, 4}, {4,3} },
        { {0, 1}, {1, 2}, {1, 5}, {1, 4}, {2, 6}, {2, 3}, {3, 2},  {3, 7}, {4, 0}, {4, 5}, {5, 6}, {6, 5}, {7,6}, {7,3} }
    };


	string nodeInicial = "A";


    cout << endl;

    cout << "Comment :=>> Iniciant test de trobar totes les components" << endl;
    cout << "Comment :=>> (TEST NO AVALUABLE) - Tarjan" << endl;
    cout << "Comment :=>> =============================================================" << endl;
    cout << "Comment :=>>" << endl;

    for ( int graf = 0; graf < N_PROVES; graf++ ) {
        cout << "Comment :=>> Inicialitzant el GRAF " << graf + 1 << " ......." << endl;
        cout << "Comment :=>> Nodes: [";
        for (int i = 0; i < nodes[graf].size(); i++) {
            std::cout << nodes[graf][i] << ((i < nodes[graf].size() - 1) ? "," : "]\n");
        }

        cout << "Comment :=>> Arestes: [";
        for (int i = 0; i < arestes[graf].size(); i++) {
            cout << "(" << arestes[graf][i][0] << ", " << arestes[graf][i][1] << "),";
        }

        cout << "(" << arestes[graf][arestes.size() - 1][0] << ", " << arestes[graf][arestes.size() - 1][1] << ")]" << endl;

        Graf gConnexions(nodes[graf], arestes[graf], true);

        cout << "Comment :=>> -----------------------------" << endl;
        cout << "Comment :=>> Graf despres inicialitzacio:" << endl;

        gConnexions.mostra();

        std::vector<std::vector<string>> componentsResultatEstudiant;
        gConnexions.Tarjan(componentsResultatEstudiant);

        std::cout << "Comment :=>> INICI COMPROVACIO COMPONENTS" << std::endl;
        for (int i = 0; i < componentsResultatEstudiant.size(); i++) {
            std::cout << "Comment :=>> Component Resultat " << i+1 << ": " << std::endl;
            std::cout << "Comment :=>> ";
            for (int j = 0; j < componentsResultatEstudiant[i].size(); j++) {
                std::cout << componentsResultatEstudiant[i][j] << ((j < componentsResultatEstudiant[i].size() - 1) ? "," : "");
            }
            std::cout << std::endl;

            std::cout << "Comment :=>> " << "Component Esperat " << i+1 << ": " << std::endl;
            if ( i < resultat[graf].size()) {
                int j = 0;
                std::cout << "Comment :=>> ";
                for (auto it = resultat[graf][i].begin(); it != resultat[graf][i].end(); it++, j++) {
                    std::cout << *it << ((j < resultat[graf][i].size() - 1) ? "," : "");
                }
                std::cout << std::endl;
            } else {
                std::cout << "Comment :=>> ERROR. Numero components resultat mes gran que esperat" << std::endl;
            }
        }

        if (!igualsComponents(componentsResultatEstudiant, resultat[graf])) {
            std::cout << "Comment :=>> ERROR" << std::endl;
        }
    }

    cout << "Comment :=>> Iniciant test de trobar totes les components" << endl;
	cout << "Comment :=>> (TEST AVALUABLE) - Kosaraju" << endl;
	cout << "Comment :=>> =============================================================" << endl;
	cout << "Comment :=>>" << endl;

    for ( int graf = 0; graf < N_PROVES; graf++ ) {
        cout << "Comment :=>> Inicialitzant el GRAF " << graf + 1 << " ......." << endl;
        cout << "Comment :=>> Nodes: [";
        for (int i = 0; i < nodes[graf].size(); i++) {
            std::cout << nodes[graf][i] << ((i < nodes[graf].size() - 1) ? "," : "]\n");
        }

        cout << "Comment :=>> Arestes: [";
        for (int i = 0; i < arestes[graf].size(); i++) {
            cout << "(" << arestes[graf][i][0] << ", " << arestes[graf][i][1] << "),";
        }

        cout << "(" << arestes[graf][arestes.size() - 1][0] << ", " << arestes[graf][arestes.size() - 1][1] << ")]" << endl;

        Graf gConnexions(nodes[graf], arestes[graf], true);

        cout << "Comment :=>> -----------------------------" << endl;
        cout << "Comment :=>> Graf despres inicialitzacio:" << endl;

        gConnexions.mostra();

        std::vector<std::vector<string>> componentsResultatEstudiant;
        gConnexions.Kosaraju(componentsResultatEstudiant);

        std::cout << "Comment :=>> INICI COMPROVACIO COMPONENTS" << std::endl;
        for (int i = 0; i < componentsResultatEstudiant.size(); i++) {
            std::cout << "Comment :=>> Component Resultat " << i+1 << ": " << std::endl;
            std::cout << "Comment :=>> ";
            for (int j = 0; j < componentsResultatEstudiant[i].size(); j++) {
                std::cout << componentsResultatEstudiant[i][j] << ((j < componentsResultatEstudiant[i].size() - 1) ? "," : "");
            }
            std::cout << std::endl;

            std::cout << "Comment :=>> " << "Component Esperat " << i+1 << ": " << std::endl;
            if ( i < resultat[graf].size()) {
                int j = 0;
                std::cout << "Comment :=>> ";
                for (auto it = resultat[graf][i].begin(); it != resultat[graf][i].end(); it++, j++) {
                    std::cout << *it << ((j < resultat[graf][i].size() - 1) ? "," : "");
                }
                std::cout << std::endl;
            } else {
                std::cout << "Comment :=>> ERROR. Numero components resultat mes gran que esperat" << std::endl;
            }
        }

        if (!igualsComponents(componentsResultatEstudiant, resultat[graf])) {
            reduccio += 5;
            std::cout << "Comment :=>> ERROR" << std::endl;
        }
    }

	return reduccio;
}

int main()
{
	float grade = 0.0;
	float reduccio;

	cout << endl;
	cout << "Comment :=>> Iniciant test " << endl;
	cout << "Comment :=>> ==============" << endl;

	cout << endl << "Grade :=>> " << grade << endl << endl;

    reduccio = testConjuntConnectats();
    grade += (10.0 - reduccio);

    if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;
	return 0;
}

#endif
