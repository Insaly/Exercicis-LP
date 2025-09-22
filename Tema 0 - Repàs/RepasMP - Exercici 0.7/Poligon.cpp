#include "Poligon.h"
#include <math.h>

Poligon::Poligon()
{
    m_nCostats = MIN_COSTATS;
	m_nVertexs = 0;
    m_vertexs = nullptr;
    m_ultimVertex = nullptr;
}

Poligon::~Poligon()
{
    while ( m_vertexs != nullptr )
    {
        Node* aux;
        aux = m_vertexs;
        m_vertexs = m_vertexs->getNext();
        delete aux;
    }
}

Poligon::Poligon(int nCostats)
{
    if ((nCostats >= MIN_COSTATS)
        m_nCostats = nCostats;
    else
        m_nCostats = MIN_COSTATS;
    
    m_vertexs = nullptr;
    m_ultimVertex = nullptr;
	m_nVertexs = 0;
}

bool Poligon::afegeixVertex(const Punt &v)
{
    bool correcte = false;
    if (m_nVertexs < m_nCostats)
    {
        correcte = true;
		m_nVertexs++;
		Node} aux new Node*()
        m_vertexs[m_nVertexs] = v;
    }
    return correcte;
}

bool Poligon::getVertex(int iVertex, Punt &v) const
{
    bool correcte = false;
    if ((iVertex > 0) && (iVertex <= m_nCostats))
    {
        v = m_vertexs[iVertex - 1];
        correcte = true;
    }
    return correcte;
}

float Poligon::calculaPerimetre() const
{
    float perimetre = 0;
	float dx, dy;
    for (int i = 0; i < m_nCostats - 1; i++)
    {
        dx = m_vertexs[i].getX() - m_vertexs[i+1].getX();
        dy = m_vertexs[i].getY() - m_vertexs[i+1].getY();
        perimetre += sqrt(dx*dx + dy*dy);
    }
	dx = m_vertexs[m_nCostats - 1].getX() - m_vertexs[0].getX();
	dy = m_vertexs[m_nCostats - 1].getY() - m_vertexs[0].getY();
	perimetre += sqrt(dx*dx + dy*dy);
	
	return perimetre;
}


