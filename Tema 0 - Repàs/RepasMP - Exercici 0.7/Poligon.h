#ifndef POLIGON_H
#define POLIGON_H

#include "Punt.h"

class Poligon
{
    public:
        Poligon();
        ~Poligon();
        Poligon(int nCostats);

        int getNCostats() const { return m_nCostats; };
        bool afegeixVertex(const Punt &v);
        bool getVertex(int iVertex, Punt &v) const;
        float calculaPerimetre() const;
    private:
        static const int MAX_COSTATS = 30;
        static const int MIN_COSTATS = 3;
        Punt m_vertexs[MAX_COSTATS];
        int m_nCostats;
		int m_nVertexs;
};

class Node
{
    public:
        void setValor( const Punt& pt ) { m_valor = pt; }
        void setNext( Node* next ) { m_next = next; }
        Punt& getValor() const { return m_valor; }
        Node* getNext() const { return m_next; }
    private:
        Punt m_valor;
        Node* m_next;
}

#endif // POLIGON_H
