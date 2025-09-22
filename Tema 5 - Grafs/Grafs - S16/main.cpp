#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include "graf.h"


using namespace std;

bool comparaTasques(vector<string>& resultatEsperat, vector<string>& resultatObtingut)
{

	bool iguals = (resultatEsperat.size() == resultatObtingut.size());
	int i = 0;
	while (iguals && (i < resultatEsperat.size()))
	{
		int j = 0;
		iguals = false;
		while (!iguals && (j < resultatObtingut.size()))
		{
			if (resultatEsperat[i] == resultatObtingut[j])
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
	size_t numNodes;

	vector<string> nomsNodes;
	vector<vector<size_t>> arestes;
	vector<int> pesos;
	queue<string> recorregut;
	stack<string> ordre;

	float grade = 0.0;
	bool valid = true;

	cout << endl << endl;
	cout << "Comment :=>>            Iniciant test dels exercicis sessio 16                 " << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	
	/**************************************/
	//GRAF PROVA DIJKSTRA
	/**************************************/
	numNodes = 6;
	nomsNodes.resize(numNodes);
	nomsNodes = { "x", "b", "d", "g", "e", "z"};

	arestes = { { 0,1 },{ 0,2 }, { 1,2 },{ 1,3 },{2,3},{2,4},{ 3,4 },{ 3,5 },{4,5}};
	pesos = {4,2,1,5,8,10,2,6,2};
	Graf gDijkstraPonderat(nomsNodes, arestes,pesos, false);

	// Dijkstra
	cout << "algorisme de DIJKSTRA en un graf simetric no ponderat:" << endl;

	cout << "mostra les distancies finals:" << endl;
	vector<int> vDist;
	vector<size_t> anterior;

	gDijkstraPonderat.dijkstra(0,vDist, anterior); // 0::3::2::8::10::12
	for (size_t i = 0; i < vDist.size(); i++)
	{
		cout << vDist[i] << "::";
	}
	cout << endl;
	vector<int> resultatEsperat = { 0, 3, 2, 8, 10, 12 };
	cout << "Comment :=>> Resultat esperat: " << endl;
	for (size_t i = 0; i < resultatEsperat.size(); i++)
	{
		cout << resultatEsperat[i] << "::";
	}
	cout << endl;
	cout << "Comment :=>> ---" << endl;
	if (vDist == resultatEsperat){
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
	}
	else {
		cout << "Comment :=>> ERROR" << endl;
		valid = false;
	}
	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;
	system("PAUSE");

	cout << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "mostra els nodes anteriors:" << endl;
	for (size_t i = 0; i < anterior.size(); i++) //0::2::0::1::3::4
	{
		cout << "::" << anterior[i];
	}
	cout << endl;
	vector<size_t> resultatEsperatAnt = { 0, 2, 0, 1, 3, 4 };
	cout << "Comment :=>> Resultat esperat node anterior: " << endl;
	for (size_t i = 0; i < resultatEsperatAnt.size(); i++)
	{
		cout << resultatEsperatAnt[i] << "::";
	}
	cout << endl;
	cout << "Comment :=>> ---" << endl;
	if (anterior == resultatEsperatAnt) {
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 2.5;
	}
	else {
		cout << "Comment :=>> ERROR" << endl;
		valid = false;
	}
	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	system("PAUSE");
	
	
	/**************************************/
	//GRAF DE METRO
	/**************************************/
	numNodes = 53;
	nomsNodes.resize(numNodes);
	nomsNodes = { "Pl. Sants","Hostafr.","Esp.","Roc.","Urgell","Univ.","Cat.","Urq.","Triomf","Marina","Glòries","Clot","Navas","Sagrera",
		"Paral·lel","St. Ant.","Pg. Gràcia","Tetuan","Monumental","S. Família","Encants","Bac Roda","Sant Martí","La Pau",
		"Sants Est.","Tarragona","Poble Sec","Drassanes","Liceu","Diagonal",
		"Besòs","Besòs Mar","El Maresme","Selva Mar","Poblenou","Llacuna","Bogatell","Ciutadella","Barcelone.","Jaume I","Girona","Verdaguer","Joanic","Alfons X",
		"Guinardó","Maragall","Llucmajor","Via Júlia",
		"Entença","H. Clínic","Sant Pau","Camp Arpa","Congrés" };

	arestes = { { 0,1 },{ 1,2 },{ 2,3 },{ 3,4 },{ 4,5 },{ 5,6 },{ 6,7 },{ 7,8 },{ 8,9 },{ 9,10 },{ 10,11 },{ 11,12 },{ 12,13 },{ 14,15 },{ 15,5 },{ 5,16 },{ 16,17 },{ 17,18 },{ 18,19 },{ 19,20 },{ 20,11 },{ 11,21 },{ 21,22 },
	{ 22,23 },{ 24,25 },{ 25,2 },{ 2,26 },{ 26,14 },{ 14,27 },{ 27,28 },{ 28,6 },{ 6,16 },{ 16,29 },{ 23,30 },{ 30,31 },{ 31,32 },{ 32,33 },{ 33,34 },{ 34,35 },{ 35,36 },{ 36,37 },{ 37,38 },{ 38,39 },{ 39,7 },{ 7,16 },{ 16,40 },{ 40,41 },
	{ 41,42 },{ 42,43 },{ 43,44 },{ 44,45 },{ 45,46 },{ 46,47 },{ 0,24 },{ 24,48 },{ 48,49 },{ 49,29 },{ 29,41 },{ 41,19 },{ 19,50 },{ 50,51 },{ 51,13 },{ 13,52 },{ 52,45 } };

	pesos.resize(numNodes);
	pesos = { 511,995,425,2271,1782,787,375,1603,493,960,1212,499,1181,647,494,124,1794,1607,536,1781,311,708,186,882,1796,1132,1090,1145,2393,1730,620,442,1654,706,292,305,1204,
		617,20,1242,184,655,2034,1170,281,979,1569,990,461,1702,1024,986,647,113,1585,520,962,1339,662,851,1695,1337,622,1290 }; //64 pesos


	Graf gMetroNoDirigit(nomsNodes, arestes, false);

	cout << "Comment :=>> =====================================================================" << endl;
	cout << "Comment :=>> Graf de Metro no dirigit creat                                       " << endl;
	cout << "Comment :=>> =====================================================================" << endl;
		
	// Camí més curt
	cout << "Comment :=>> Mostra el cami minim amb DIJKSTRA en un graf simetric no ponderat: " << endl;
	cout << "Comment :=>> =====================================================================" << endl;

	stack<string> cami;
	vector<string> resultatCami;
	gMetroNoDirigit.camiMesCurt("Sants Est.", "Diagonal", cami); 
	
	while (!cami.empty()) //Sants Est.--> Entenþa--> H. ClÝnic--> Diagonal-->
	{
		cout << cami.top() << " --> ";
		resultatCami.push_back(cami.top());
		cami.pop();
	}
	cout << endl;
	vector<string> resultatEsperatCami = { "Sants Est.", "Entença", "H. Clínic", "Diagonal"};
	cout << "Comment :=>> Resultat esperat cami mes curt: " << endl;
	for (size_t i = 0; i < resultatEsperatCami.size(); i++)
	{
		cout << resultatEsperatCami[i] << " --> ";
	}

	cout << endl;
	cout << "Comment :=>> ---" << endl;

	if (comparaTasques(resultatEsperatCami, resultatCami)) {
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 5;
	}
	else {
		cout << "Comment :=>> ERROR" << endl;
		valid = false;
	}

	cout << "Comment :=>> =====================================================================" << endl;
	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;

	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;

	system("pause");

	return 0;
}