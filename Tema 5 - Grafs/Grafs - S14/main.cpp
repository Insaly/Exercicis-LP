#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <string>
#include "graf.h"

using namespace std;

bool comparaCamins(vector<list<string>>& caminsEsperats, vector<list<string>>& camins)
{

	bool iguals = (caminsEsperats.size() == camins.size());
	size_t i = 0;
	while (iguals && (i < caminsEsperats.size()))
	{
		size_t j = 0;
		iguals = false;
		while (!iguals && (j < camins.size()))
		{
			if (caminsEsperats[i] == camins[j])
				iguals = true;
			else
				j++;
		}
		i++;
	}
	return iguals;
}

int main()
{
	float grade = 0.0;
	bool valid = true;

	cout << endl << endl;
	cout << "Comment :=>>            Iniciant test dels exercicis sessio 14                 " << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	size_t numNodes = 11;

	vector<string> nomsNodes;
	nomsNodes.resize(numNodes);
	nomsNodes = { "Tasca 1","Tasca 2","Tasca 3","Tasca 4","Tasca 5","Tasca 6","Tasca 7","Tasca 8","Tasca 9","Tasca 10","Tasca 11" };

	vector<vector<size_t>> arestes;

	arestes = { {0,1},{0,2},{0,3},{2,1},{2,3},{1,4},{1,5},{3,5},{6,3},{5,4},{5,6},{4,7},{4,8},{6,8},{6,9},{7,8},
	{8,9},{7,10},{8,10},{9,10} };

	vector<int> pesos = { 5,5,5,7,7,10,10,4,4,6,6,3,3,9,9,1,8,2,8,4 }; //20 pesos

	Graf g(nomsNodes, arestes, false);

	cout << "mostra graf simetric no ponderat:" << endl;
	g.mostra();

	cout << "Comment :=>> ==============================================" << endl;
	cout << "Comment :=>> Graf simetric no ponderat creat               " << endl;
	cout << "Comment :=>> ==============================================" << endl;

	Graf gP(nomsNodes, arestes, pesos, true);

	cout << "mostra graf dirigit ponderat:" << endl;
	gP.mostra();

	cout << "Comment :=>> ==============================================" << endl;
	cout << "Comment :=>> Graf dirigit ponderat creat                   " << endl;
	cout << "Comment :=>> ==============================================" << endl;

	vector<size_t> graus_in;
	graus_in.resize(numNodes);
	vector<size_t> graus_out;
	graus_out.resize(numNodes);

	for (size_t i = 0; i < numNodes; i++)
	{
		graus_in[i] = gP.grauInNode(nomsNodes[i]);
		graus_out[i] = gP.grauOutNode(nomsNodes[i]);
	}

	// TEST GRAUS IN NODES
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ======================================================" << endl;
	cout << "Comment :=>> Test del metode per trobar grau IN dels nodes del graf" << endl;
	cout << "Comment :=>> Calculant grau IN i OUT per tots els nodes del graf..." << endl;
	cout << "Comment :=>> " << endl;

	for (size_t i = 0; i < numNodes; i++) {
		cout << graus_in[i] << " ";
	}
	cout << endl;

	cout << "Comment :=>> ======================================================" << endl;
	vector<size_t> grausInEsperat = { 0, 2, 1, 3, 2, 2, 1, 1, 3, 2, 3 };
	cout << "Comment :=>> Resultat esperat grau IN : " << endl;
	cout << "Comment :=>> ";
	for (size_t i = 0; i < numNodes; i++)
		cout << grausInEsperat[i] << " ";
	cout << endl;
	cout << "Comment :=>> ---" << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> ";
	for (size_t i = 0; i < numNodes; i++)
		cout << graus_in[i] << " ";
	cout << endl;

	if (grausInEsperat == graus_in) {
		cout << "Comment :=>> CORRECTE: Graus IN dels nodes" << endl;
		grade += 2.5;
	}
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		valid = false;
	}
	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;

	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ======================================================" << endl;

	for (size_t i = 0; i < numNodes; i++) {
		cout << graus_out[i] << " ";
	}
	cout << endl;

	vector< size_t> grausOutEsperat = { 3, 2, 2, 1, 2, 2, 3, 2, 2, 1, 0 };
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> ";
	for (size_t i = 0; i < numNodes; i++)
		cout << grausOutEsperat[i] << " ";
	cout << endl;
	cout << "Comment :=>> ---" << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> ";
	for (size_t i = 0; i < numNodes; i++)
		cout << graus_out[i] << " ";
	cout << endl;

	if (grausOutEsperat == graus_out)
	{
		cout << "Comment :=>> CORRECTE: Graus OUT dels nodes " << endl;
	    grade += 2.5;
    }
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		valid = false;
	}
	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ======================================================" << endl;

	// TEST CAMINS
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ======================================================" << endl;
	cout << "Comment :=>> Test del metode per trobar els camins possibles entre " << endl;
	cout << "Comment :=>> dos nodes del graf                                    " << endl;
	cout << "Comment :=>> " << endl;

	vector<list<string>> camins;
	gP.camins("Tasca 2", "Tasca 9", camins);

	cout << endl;
	cout << "Comment :=>> ---" << endl;

	vector<list<string>> caminsEsperats =
	{
		{ "Tasca 2", "Tasca 5", "Tasca 8", "Tasca 9" },
		{ "Tasca 2", "Tasca 5", "Tasca 9" },
		{ "Tasca 2", "Tasca 6", "Tasca 5", "Tasca 8", "Tasca 9" },
		{ "Tasca 2", "Tasca 6", "Tasca 5", "Tasca 9" },
		{ "Tasca 2", "Tasca 6", "Tasca 7", "Tasca 9" }
	};

	cout << "Comment :=>> Resultat esperat: " << endl;
	for (size_t i = 0; i < caminsEsperats.size(); i++)
	{
		list<string>::iterator it;
		cout << "Comment :=>> ";
		for (it = caminsEsperats[i].begin(); it != caminsEsperats[i].end(); it++)
			cout << (*it) << " ";
		cout << endl;
	}

	cout << endl;
	cout << "Comment :=>> ---" << endl;

	if (comparaCamins(caminsEsperats, camins)) {
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 5;
	}
	else {
		cout << "Comment :=>> ERROR" << endl;
		valid = false;
	}

	cout << "Comment :=>> ==================================================================" << endl;
	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;

	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;

	return 0;
}