#ifndef LLIBRE_H
#define LLIBRE_H

#include <string>
#include "Producte.h"

using namespace std;

class Llibre : public Producte
{
public:

    Llibre() : Producte(), m_titol(""), m_autor(""), m_nPagines(0) {}
    Llibre(const Llibre& l) : Producte(l), m_titol(l.m_titol), m_autor(l.m_autor), m_nPagines(l.m_nPagines) {}
    Llibre(const string& codi, float preu, const string& titol, const string& autor, int nPagines) : Producte(codi, preu), m_titol(titol), m_autor(autor), m_nPagines(nPagines) {}
    ~Llibre() {}

    void setTitol(const string& titol) { m_titol = titol; }
    void setAutor(const string& autor) { m_autor = autor; }
    void setnPagines(const int nPagines) { m_nPagines = nPagines; }

    string getTitol() { return m_titol; }
    string getAutor() { return m_autor; }
    int getnPagines() { return m_nPagines; }

    float calculaDespesesEnviament();
    float calculaPreu(int nUnitats);
    void mostra();

private:

    string m_titol;
    string m_autor;
    int m_nPagines;
};


#endif // LLIBRE_H