#include "Hash.h"
#include <math.h>
using namespace std;

Hash::Hash(int sizeIni, float factorCarrega, const string& descripcioDefecte)
{
	m_maxElements = sizeIni;
	m_descripcioDefecte=descripcioDefecte;
	m_factorCarrega = factorCarrega;
	
	m_diccionari.resize(m_maxElements,pair<string,string>("",""));
	int init = LLIURE;
	m_estat.resize(m_maxElements, init);
	m_numOcupats = 0;
}

Hash::~Hash()
{
}

string& Hash::operator[](const string& clau)
{
    int index = cerca(clau);
    if ((m_diccionari[index].first == clau) && (m_estat[index] == OCUPAT))
        return m_diccionari[index].second;
    else
        return m_descripcioDefecte;
}

void Hash::insert(const string& clau, const string& descripcio)
{
	int index=codi(clau);
	if (m_diccionari[index].first == clau)
	    m_diccionari[index].second = descripcio;
	else
		insertIntern(clau, descripcio);
}

bool Hash::find(const string& clau, string& definicio) const
{
	int index = codi(clau);
	bool trobat = false;

    if ((m_diccionari[index].first == clau) && (m_estat[index] == OCUPAT))
    {
        trobat = true;
        definicio = m_diccionari[index].second;
    }
    else { definicio = ""; }
    return trobat;
}

int Hash::codi(string s) const
{
	unsigned long valor = 0;
	for (int i = 0; i < s.size(); i++)
	{
		valor+= (s[i]*pow(2,i));
		valor = valor%m_maxElements;
	}	
	return valor;
}

int Hash::codi2(int index, int vegades) const
{
	return (int)(index + pow(vegades,2)) % m_maxElements;
}

void Hash::resize()
{
    vector<int> estatAux;
    vector<pair<string, string>> diccAux;
    diccAux = m_diccionari;
    estatAux = m_estat;
    int maxelsAux = m_maxElements;

    m_maxElements *= 2;
    m_diccionari.clear();
    m_diccionari.resize(m_maxElements, pair<string, string>("", ""));
    m_estat.clear();
    int init = LLIURE;
    m_estat.resize(m_maxElements, init);
    m_numOcupats = 0;

    for (int i = 0; i < maxelsAux; i++)
    {
        if (estatAux[i] == OCUPAT)
            insertIntern(diccAux[i].first, diccAux[i].second);
    }
}

void Hash::insertIntern(const string& clau, const string& descripcio)
{
    int indexInicial = codi(clau);
    int index = indexInicial;
    int vegades = 1;

    while ((vegades < m_maxElements) && (m_estat[index] == OCUPAT))
    {
        index = codi2(indexInicial, vegades);
        vegades++;
    }

    if (vegades >= m_maxElements)
        throw "COL·LISIO";

    m_diccionari[index].second = descripcio;
    m_diccionari[index].first = clau;
    m_estat[index] = OCUPAT;
    m_numOcupats++;

    if ((m_numOcupats / (float)(m_diccionari.size())) >= m_factorCarrega)
        resize();
}

bool Hash::esborra(const string& clau)
{
	int index = codi(clau);

	if (m_diccionari[index].first == clau)
	{
		m_diccionari[index].first = "";
		m_diccionari[index].second = "";
		m_numOcupats--;
		return true;
	}

	return false;

}

int Hash::cerca(const string& clau) const
{
    int indexInicial = codi(clau);
    int index = indexInicial;
    int vegades = 0;
    bool trobat = false;

    while ((!trobat) && (m_estat[index] != LLIURE))
    {
        if ((m_diccionari[index].first == clau) && (m_estat[index] == OCUPAT))
            trobat = true;
        else
        {
            index = codi2(indexInicial, vegades);
            vegades++;
        }
    }

    return index;
}

ostream& operator<<(ostream& out, const Hash& h)
{
	for (int i = 0; i < h.m_diccionari.size(); i++)
	{
		if (h.m_diccionari[i].first!="")
		{
			out << "POS: " << i <<"  CLAU: " << h.m_diccionari[i].first <<"  VALOR: " << h.m_diccionari[i].second <<endl;
		}		
	}

	return out;
}