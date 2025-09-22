#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Publicacio
{
public:
    Publicacio() { m_titol = "null"; m_codi = "null"; m_tipus = "null"; }

    Publicacio(string titol, string codi, string tipus) {
        m_titol = titol;
        m_codi = codi;
        m_tipus = tipus;
    }

    virtual void printPublicacio()
    {
        cout << m_tipus << " " << m_codi << " " << m_titol << " ";
    }

    virtual int getPrestat(int exemplar) const { return -1; }
    virtual void setPrestat(int num, int exemplar) {}
    virtual int getNDiesPrestat() const { return -1; }
    virtual int getNCopies() const { return -1; }

    string getTipus() { return m_tipus; }
    string getCodi() { return m_codi; }

private:
    string m_titol;
    string m_codi;
    string m_tipus;
};

class Revista : public Publicacio
{
public:
    Revista()
    {
        m_periodicitat = "";
        m_nExemplars = 0;
        m_prestat.resize(m_nExemplars);
        for (int i = 0; i < m_nExemplars; i++)
            m_prestat[i] = false;
    }

    Revista(string titol, string codi, string tipus, string periodicitat, int nExemplars, vector<int> exemplars) : Publicacio(titol, codi, tipus), m_periodicitat(periodicitat), m_nExemplars(nExemplars)
    {
        m_prestat.resize(m_nExemplars);
        m_vExemplars.resize(m_nExemplars);

        for (int i = 0; i < m_nExemplars; i++)
        {
            m_prestat[i] = false;
            m_vExemplars[i] = exemplars[i];
        }
    }

    void printPublicacio()
    {
        Publicacio::printPublicacio();
        cout << m_periodicitat << " " << m_nExemplars << " -> ";
        for (int i = 0; i < m_nExemplars; i++)
            cout << m_vExemplars[i] << " ";
        cout << endl << endl;
    }

    void setPrestat(int resultat, int exemplar)
    {
        for (int i = 0; i < m_nExemplars; i++)
        {
            if (exemplar == m_vExemplars[i])
                m_prestat[i] = (resultat != 0);
        }
    }

    int getPrestat(int exemplar) const
    {
        for (int i = 0; i < m_nExemplars; i++)
        {
            if (exemplar == m_vExemplars[i])
                return m_prestat[i] ? 1 : 0;
        }
        return -1;
    }

private:
    int m_nExemplars;
    string m_periodicitat;
    vector<bool> m_prestat;
    vector<int> m_vExemplars;
};

class Llibre : public Publicacio
{
public:
    Llibre() : m_autor(""), m_nCopies(0), m_nDies(0), m_copiesPrestades(0) {}
    Llibre(string titol, string codi, string tipus, const string& autor, int nCopies, int nDies) :
        Publicacio(titol, codi, tipus), m_autor(autor), m_nCopies(nCopies), m_nDies(nDies), m_copiesPrestades(0) {}

    void printPublicacio()
    {
        Publicacio::printPublicacio();
        cout << m_autor << " " << m_nCopies << " " << m_nDies << endl << endl;
    }
    int getPrestat(int exemplar) const { return m_copiesPrestades; }
    void setPrestat(int num, int exemplar) { m_copiesPrestades += num; }
    int getNDiesPrestat() const { return m_nDies; }
    int getNCopies() const { return m_nCopies; }

private:
    int m_copiesPrestades;
    int m_nDies;
    int m_nCopies;
    string m_autor;
};

