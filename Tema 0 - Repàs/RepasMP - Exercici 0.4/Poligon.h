#ifndef POLIGON_H
#define POLIGON_H

#include "Punt.h"

class Poligon
{
    public:
        Poligon();
        ~Poligon();
        Poligon(int nCostats);
        Poligon(const Poligon& p);
        Poligon& operator= (const Poligon& p);

        int getNCostats() const { return m_nCostats; };
        bool afegeixVertex(const Punt &v);
        bool getVertex(int iVertex, Punt &v) const;
        float calculaPerimetre() const;
    private:
        static const int MIN_COSTATS = 3;
        Punt *m_vertexs;
        int m_nCostats;
		int m_nVertexs;
};

#endif // POLIGON_H
