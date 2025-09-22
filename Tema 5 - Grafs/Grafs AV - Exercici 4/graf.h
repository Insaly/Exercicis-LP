#ifndef GRAF_H
#define GRAF_H
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstdio>
using namespace std;

class Graf
{
public:
	Graf();
	Graf(const vector<string>& nodes, const vector<vector<int>>& parellesNodes, bool dirigit);
	Graf(const vector<string>& nodes, const vector<vector<int>>& parellesNodes, const vector<int>& pesos, bool dirigit);
	~Graf();

	int getNumNodes() { return m_numNodes; }

	void inserirAresta(int posNode1, int posNode2);
	void inserirAresta(int posNode1, int posNode2, int pes);
	void eliminarAresta(int posNode1, int posNode2);

	void afegirNode(const string& node);
	void eliminarNode(const string& node);

	void mostra();
	void BFS(const string& nodeInicial, queue<string>& recorregut);
	int BFS(const string& nodeInicial, const string& nodeFinal, queue<string>& recorregut);
	void BFS(const string& nodeInicial, int distancia, queue<string>& recorregut);
	void BFS(const string& nodeInicial, const string& nodeFinal, queue<string>& recorregut, stack<string>& cami);


private:
	vector<string> m_nodes;
	vector<vector<int>> m_matriuAdj;
	int m_numNodes;
	int m_numArestes;
	bool m_dirigit;

	void crearMatriu(const vector<vector<int>>& parelles);
	void crearMatriu(const vector<vector<int>>& parelles, const vector<int>& pesos);

};

#endif
