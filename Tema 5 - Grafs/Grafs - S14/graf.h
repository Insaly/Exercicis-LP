#pragma once
#include <vector>
#include <list>
#include <string>
#include <cstdio>
using namespace std;

class Graf
{
public:
	Graf();
	Graf(const vector<string>& nodes, const vector<vector<size_t>> parellesNodes, bool dirigit);
	Graf(const vector<string>& nodes, const vector<vector<size_t>> parellesNodes, const vector<int> pesos, bool dirigit);
	~Graf();

	vector<vector<size_t>> cicles();
	void mostra();
	size_t grauOutNode(string node);
	size_t grauInNode(string node);
	void camins(string node1, string node2,	vector<list<string>>& camins_out); //par�metre per testejar al caronte

private:
	vector<string> m_nodes;
	vector<vector<int>> m_matriuAdj;
	size_t m_numNodes;
	size_t m_numArestes;
	bool m_dirigit;

	void crearMatriu(const vector<vector<size_t>> parelles);
	void crearMatriu(const vector<vector<size_t>> parelles, const vector<int> pesos);
	void printTotsCaminsFins(size_t pos1, size_t pos2, vector<bool> visited, list<size_t> paths,
		vector<list<string>>& camins_out); //par�metre per testejar al caronte
};

