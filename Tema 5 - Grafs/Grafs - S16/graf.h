#ifndef GRAF_H
#define GRAF_H

#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstdio>
#include <limits>

using namespace std;

class Graf
{
public:
    Graf();
    Graf(const vector<string>& nodes, const vector<vector<size_t>>& parellesNodes, bool dirigit);
    Graf(const vector<string>& nodes, const vector<vector<size_t>>& parellesNodes, const vector<int>& pesos, bool dirigit);
    ~Graf();


    void mostra();
    void dijkstra(size_t node, vector<int>& dist);
    void dijkstra(size_t node, vector<int>& dist, vector<size_t>& anterior);
    void camiMesCurt(const string& node1, const string& node2, stack<string>& cami);

    static const int DISTMAX;

private:
    vector<string> m_nodes;
    vector<vector<int>> m_matriuAdj;
    size_t m_numNodes;
    size_t m_numArestes;
    bool m_dirigit;

    void crearMatriu(const vector<vector<size_t>>& parelles);
    void crearMatriu(const vector<vector<size_t>>& parelles, const vector<int>& pesos);
    size_t minDistance(const vector<int>& dist, const vector<bool>& visitat) const;
    void dijkstraModif(size_t node1, size_t node2, vector<int>& dist, vector<size_t>& anterior);
};



#endif   // GRAF_H
