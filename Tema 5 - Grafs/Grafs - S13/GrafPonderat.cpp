#include "GrafPonderat.h"
#include <iostream>
#include <iomanip>


GrafPonderat::GrafPonderat()
{
    m_numNodes = 0;
    m_numArestes = 0;
}

GrafPonderat::GrafPonderat(const std::vector<std::string>& nodes, const std::vector<std::vector<int>>& parelles_nodes, const std::vector<int>& pesos)
{
    m_nodes = nodes;
    m_numNodes = m_nodes.size();
    m_numArestes = parelles_nodes.size();

    crearMatriu(parelles_nodes, pesos);
}

GrafPonderat::~GrafPonderat()
{
}

void GrafPonderat::crearMatriu(const std::vector<std::vector<int>>& parelles, const std::vector<int>& pesos)
{
    m_matriuAdj.resize(m_numNodes);
    for (size_t i = 0; i < m_numNodes; i++)
    {
        m_matriuAdj[i].resize(m_numNodes, 0);
    }

    for (size_t i = 0; i < m_numArestes; i++)
    {
        m_matriuAdj[parelles[i][0]][parelles[i][1]] = pesos[i];
        m_matriuAdj[parelles[i][1]][parelles[i][0]] = pesos[i];
    }
}
