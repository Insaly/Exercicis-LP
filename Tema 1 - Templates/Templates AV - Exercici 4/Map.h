#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

template<class TClau, class TValor>
class Map
{
public:

    Map() {}
    Map(const Map& m) { m_elements = m.m_elements; }
    ~Map() {}

    int longitud() const { return m_elements.size(); }
    bool esBuit() const { return m_elements.empty(); }

    TValor& operator[](const TClau& clau) { return buscarValor(clau, 0, longitud() - 1); };
    const TValor& operator[](const TClau& clau) const { return buscarValor(clau, 0, longitud() - 1); };
    TClau& operator[](const int& posicio);
    const TClau& operator[](const int& posicio) const;

    void afegeix(const TClau& clau, const TValor& valor);
    Map<TClau, TValor>& operator=(const Map<TClau, TValor>& m);

private:

    vector<pair<TClau, TValor>> m_elements;
    TClau m_clau;
    TValor m_valor;

    TValor& buscarValor(const TClau& clau, int esquerra, int dreta);
    const TValor& buscarValor(const TClau& clau, int esquerra, int dreta) const;
    void sort();
};

template<class TClau, class TValor>
TClau& Map<TClau, TValor>::operator[](const int& posicio)
{
    if (posicio < 0 || posicio >= longitud())
    {
        return m_clau;
    }

    return m_elements[posicio].first;
}

template<class TClau, class TValor>
const TClau& Map<TClau, TValor>::operator[](const int& posicio) const
{
    if (posicio < 0 || posicio >= longitud())
    {
        return m_clau;
    }

    return m_elements[posicio].first;
}

template<class TClau, class TValor>
void Map<TClau, TValor>::afegeix(const TClau& clau, const TValor& valor)
{
    int i = 0;
    bool existeix = false;

    while (!existeix && i < longitud())
    {
        if (m_elements[i].first == clau)
        {
            m_elements[i].second = valor;
            existeix = true;
        }
        else
        {
            i++;
        }
    }

    if (!existeix)
    {
        typename vector<pair<TClau, TValor>>::iterator it = m_elements.begin();
        m_elements.insert(it, make_pair(clau, valor));
        sort();
    }
}

template<class TClau, class TValor>
Map<TClau, TValor>& Map<TClau, TValor>::operator=(const Map<TClau, TValor>& m) {
    if (this != &m) {
        if (m_elements != NULL) {
            m_elements = m.m_elements;
        }
    }
    return *this;
}

template<class TClau, class TValor>
TValor& Map<TClau, TValor>::buscarValor(const TClau& clau, int esquerra, int dreta)
{
    if (esquerra > dreta)
    {
        return m_valor;
    }

    int centre = (esquerra + dreta) / 2;

    if (m_elements[centre].first < clau)
    {
        return buscarValor(clau, centre + 1, dreta);
    }
    else if (m_elements[centre].first > clau)
    {
        return buscarValor(clau, esquerra, centre - 1);
    }
    else
    {
        return m_elements[centre].second;
    }
}

template<class TClau, class TValor>
const TValor& Map<TClau, TValor>::buscarValor(const TClau& clau, int esquerra, int dreta) const
{
    if (esquerra > dreta)
    {
        return m_valor;
    }

    int centre = (esquerra + dreta) / 2;

    if (m_elements[centre].first < clau)
    {
        return buscarValor(clau, centre + 1, dreta);
    }
    else if (m_elements[centre].first > clau)
    {
        return buscarValor(clau, esquerra, centre - 1);
    }
    else
    {
        return m_elements[centre].second;
    }
}

template<class TClau, class TValor>
void Map<TClau, TValor>::sort()
{
    for (int i = 0; i < longitud(); i++)
    {
        for (int j = 0; j < longitud(); j++)
        {
            if (m_elements[i].first < m_elements[j].first)
            {
                pair<TClau, TValor> aux = m_elements[i];
                m_elements[i] = m_elements[j];
                m_elements[j] = aux;
            }
        }
    }
}