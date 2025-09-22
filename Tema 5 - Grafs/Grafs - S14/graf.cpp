#include "graf.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;


Graf::Graf()
{
	m_numNodes = 0;
	m_numArestes = 0;
}

Graf::Graf(const vector<string>& nodes, const vector<vector<size_t>> parellesNodes, bool dirigit)
{
	m_nodes = nodes; 
	m_numNodes = m_nodes.size();
	m_numArestes = parellesNodes.size();
	m_dirigit = dirigit;
	crearMatriu(parellesNodes);
}

Graf::Graf(const vector<string>& nodes, const vector<vector<size_t>> parellesNodes, const vector<int> pesos, bool dirigit)
{
	m_nodes = nodes;
	m_numNodes = m_nodes.size();
	m_numArestes = parellesNodes.size();
	m_dirigit = dirigit;
	crearMatriu(parellesNodes, pesos);
}


Graf::~Graf()
{
}

void Graf::crearMatriu(const vector<vector<size_t>> parelles)
{
	m_matriuAdj.resize(m_numNodes);
	for (size_t i = 0; i < m_numNodes; i++)
	{
		m_matriuAdj[i].resize(m_numNodes, 0);
	}

	for (size_t i = 0; i < parelles.size(); i++)
	{
		m_matriuAdj[parelles[i][0]][parelles[i][1]] = 1;
		if (!m_dirigit)
			m_matriuAdj[parelles[i][1]][parelles[i][0]] = 1;
	}
}

void Graf::crearMatriu(const vector<vector<size_t>> parelles, const vector<int> pesos)
{
	m_matriuAdj.resize(m_numNodes);
	for (auto& it : m_matriuAdj)
	{
		it.resize(m_numNodes);
	}

	for (size_t i = 0; i < parelles.size(); i++)
	{
		m_matriuAdj[parelles[i][0]][parelles[i][1]] = pesos[i];
		if (!m_dirigit)
			m_matriuAdj[parelles[i][1]][parelles[i][0]] = pesos[i];
	}
}


vector<vector<size_t>> Graf::cicles()
{
	vector<vector<size_t>> parades_cicles;
	size_t total_cicles = 0;

	for (size_t fila = 0; fila < m_numNodes; fila++)
	{
		for (size_t col = fila + 1; col < m_numNodes; col++)
		{
			if (m_matriuAdj[fila][col] == 1)
			{
				for (size_t tercerVei = col + 1; tercerVei < m_numNodes; tercerVei++)
				{
					if ((m_matriuAdj[fila][tercerVei] == 1) &&
						(m_matriuAdj[col][tercerVei] == 1))
					{
						total_cicles++;
						parades_cicles.push_back({ fila,col,tercerVei });
					}
				}
			}
		}
	}
	return parades_cicles;
}

void Graf::mostra()
{
	int mida_c = 4;
	// imprimim el nom dels v�rtexs
	cout << setw(mida_c) << " ";
	for (size_t j = 0; j < m_numNodes; j++)
	{

		cout << setw(mida_c) << m_nodes[j] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < m_numNodes; i++)
	{
		cout << setw(10) << m_nodes[i] << " ";
		for (size_t j = 0; j < m_numNodes; j++)
		{
			cout << setw(mida_c) << m_matriuAdj[i][j] << " ";
		}
		cout << endl;
	}
}

size_t Graf::grauOutNode(string node)
{
	size_t grau = 0;
	vector<string>::iterator it = find(m_nodes.begin(), m_nodes.end(), node);

	it = std::find(m_nodes.begin(), m_nodes.end(), node);

	if (it != m_nodes.end())
	{
		size_t pos = std::distance(m_nodes.begin(), it);

		for (size_t i = 0; i < m_numNodes; i++)
		{
			if (m_matriuAdj[pos][i] != 0)
				grau++;
		}
	}

	return grau;
}

size_t Graf::grauInNode(string node)
{
	size_t grau = 0;
	vector<string>::iterator it = find(m_nodes.begin(), m_nodes.end(), node);

	it = std::find(m_nodes.begin(), m_nodes.end(), node);

	if (it != m_nodes.end())
	{
		size_t pos = std::distance(m_nodes.begin(), it);

		for (size_t i = 0; i < m_numNodes; i++)
		{
			if (m_matriuAdj[i][pos] != 0)
				grau++;
		}
	}

	return grau;
}

void Graf::printTotsCaminsFins(size_t pos1, size_t pos2, vector<bool> visited, list<size_t> paths,
	                           vector<list<string>>& camins_out) //par�metre per testejar al caronte
{
	visited[pos1] = true;
	paths.push_back(pos1);

	if (pos1 == pos2)
	{
		list<string> cami;
		for (auto it = paths.begin(); it != paths.end(); it++)
		{
			cami.push_back(m_nodes[*it]);
		}
		camins_out.push_back(cami);
	}
	else
	{
		for (size_t i = 0; i < m_numNodes; i++)
		{
			if (m_matriuAdj[pos1][i] != 0 && !visited[i])
			{
				printTotsCaminsFins(i, pos2, visited, paths, camins_out);
			}
		}
	}

	paths.pop_back();
	visited[pos1] = false;
}

void Graf::camins(string node1, string node2, vector<list<string>>& camins_out)
{
	vector<bool> visited(m_numNodes, false);
	list<size_t> paths;

	vector<string>::iterator it1 = find(m_nodes.begin(), m_nodes.end(), node1);
	vector<string>::iterator it2 = find(m_nodes.begin(), m_nodes.end(), node2);

	if (it1 != m_nodes.end() && it2 != m_nodes.end())
	{
		size_t pos1 = std::distance(m_nodes.begin(), it1);
		size_t pos2 = std::distance(m_nodes.begin(), it2);

		printTotsCaminsFins(pos1, pos2, visited, paths, camins_out);
	}
}

