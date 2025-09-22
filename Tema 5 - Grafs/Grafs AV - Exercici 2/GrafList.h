#ifndef GRAF_LIST
#define GRAF_LIST
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

class Graf
{
public:
	Graf(bool dirigit);
	Graf(const vector<string>& nodes, const vector<vector<int>>& parellesNodes, bool dirigit);
	Graf(const vector<string>& nodes, const vector<vector<int>>& parellesNodes, const vector<int>& pesos, bool dirigit);
	~Graf();
	int getNumNodes() { return m_numNodes; }

	void inserirAresta(int posNode1, int posNode2);
	void inserirAresta(int posNode1, int posNode2, int pes);
	void eliminarAresta(int posNode1, int posNode2);

	void afegirNode(const string& node);
	void eliminarNode(const string& node);
	bool esVei(string node1, string node2);
	bool esVei(int node1, int node2);
	bool obtenirIndex(string node, int& index);

	vector<vector<string>> cicles();
	int grauOutNode(string node);
	int grauInNode(string node);

	void mostra();

private:
	//Aqui a string podem posar TNode per tenir nodes de qualsevol tipus
	vector<list<pair<int,int>>> m_veins;
	vector<string> m_nodes;
	int m_numNodes;
	int m_numArestes;
	bool m_dirigit;
};

#endif
