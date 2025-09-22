#include "graf.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

const int Graf::DISTMAX{ numeric_limits<int>::max() };

Graf::Graf()
{
    m_numNodes = 0;
    m_numArestes = 0;
    m_dirigit = false;
}

Graf::Graf(const vector<string>& nodes, const vector<vector<size_t>>& parellesNodes, bool dirigit)
{
    m_nodes = nodes;
    m_numNodes = m_nodes.size();
    m_numArestes = parellesNodes.size();
    m_dirigit = dirigit;
    crearMatriu(parellesNodes);
}

Graf::Graf(const vector<string>& nodes, const vector<vector<size_t>>& parellesNodes, const vector<int>& pesos, bool dirigit)
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

void Graf::crearMatriu(const vector<vector<size_t>>& parelles)
{
    m_matriuAdj.resize(m_numNodes);
    for (size_t i=0; i<m_numNodes;i++)
    {
        m_matriuAdj[i].resize(m_numNodes,0);
    }

    for (size_t i = 0; i < parelles.size(); i++)
    {
        m_matriuAdj[parelles[i][0]][parelles[i][1]] = 1;
        if (!m_dirigit)
            m_matriuAdj[parelles[i][1]][parelles[i][0]] = 1;
    }
}

void Graf::crearMatriu(const vector<vector<size_t>>& parelles,const vector<int>& pesos)
{
    m_matriuAdj.resize(m_numNodes);
    for (auto &it : m_matriuAdj)
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


void Graf::mostra()
{
    int mida_c = 4;
    // imprimim el nom dels vèrtexs
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


size_t Graf::minDistance(const vector<int>& dist, const vector<bool>& visitat) const
{
    // Initialize min value
    int min = DISTMAX;
    size_t minIndex = -1;

    for (size_t posVei = 0; posVei < m_numNodes; posVei++)
    {
        if (visitat[posVei] == false && dist[posVei] <= min)
        {
            min = dist[posVei];
            minIndex = posVei;
        }
    }

    return minIndex;
}

void Graf::dijkstra(size_t node, vector<int>& dist)
{
    dist.resize(m_numNodes, DISTMAX);
    vector<bool> visitat;
    visitat.resize(m_numNodes, false);
    dist[node] = 0;

    for (size_t count = 0; count < m_numNodes - 1; count++)
    {
        size_t u = minDistance(dist, visitat);

        visitat[u] = true;

        for (size_t v = 0; v < m_numNodes; v++)
        {
            if (!visitat[v] && m_matriuAdj[u][v] && dist[u] != DISTMAX && dist[u] + m_matriuAdj[u][v] < dist[v])
            {
                dist[v] = dist[u] + m_matriuAdj[u][v];
            }
        }
    }
}

void Graf::dijkstra(size_t node,vector<int>& dist,
                    vector<size_t>& anterior) //paràmetre nou exercici 2
{
    dist.resize(m_numNodes, DISTMAX);
    vector<bool> visitat;
    visitat.resize(m_numNodes, false);
    anterior.resize(m_numNodes, -1);

    dist[node] = 0;
    anterior[node] = node;

    for (size_t count = 0; count < m_numNodes - 1; count++)
    {
        size_t u = minDistance(dist, visitat);

        visitat[u] = true;

        for (size_t v = 0; v < m_numNodes; v++)
        {
            if (!visitat[v] && m_matriuAdj[u][v] && dist[u] != DISTMAX && dist[u] + m_matriuAdj[u][v] < dist[v])
            {
                dist[v] = dist[u] + m_matriuAdj[u][v];
                anterior[v] = u;
            }
        }
    }
}

void Graf::camiMesCurt(const string& node1, const string& node2, stack<string>& cami)
{
    size_t posNode1 = find(m_nodes.begin(), m_nodes.end(), node1) - m_nodes.begin();
    size_t posNode2 = find(m_nodes.begin(), m_nodes.end(), node2) - m_nodes.begin();

    vector<int> dist;
    vector<size_t> anterior;
    dijkstra(posNode1, dist, anterior);

    size_t actual = posNode2;

    cami.push(node2);

    while (actual != posNode1)
    {
        actual = anterior[actual];
        cami.push(m_nodes[actual]);
    }
}

void Graf::dijkstraModif(size_t node1, size_t node2, vector<int>& dist, vector<size_t>& anterior)
{
    //OMPLIR

}
