#pragma once
#include <iostream>
#include <string>
#include "Data.h"
using namespace std;

class Prestec
{
public:
    Prestec() { m_numExemplar = 0; }

    Prestec(string idUsuari, string codiPublicacio, Data dataPrestec, Data dataRetorn, int numExemplar = 0)
    {
        m_dataRetorn = dataRetorn;
        m_dataPrestec = dataPrestec;
        m_idUsuari = idUsuari;
        m_codiPublicacio = codiPublicacio;
        m_numExemplar = numExemplar;
    }

    Data getDataRetorn() const { return m_dataRetorn; }
    Data getDataPrestec() const { return m_dataPrestec; }
    string getidUsuari() const { return m_idUsuari; }
    string getCodiPublicacio() const { return m_codiPublicacio; }
    int getnExemplar() const { return m_numExemplar; }

private:
    Data m_dataRetorn;
    Data m_dataPrestec;
    string m_idUsuari;
    string m_codiPublicacio;
    int m_numExemplar;
};
