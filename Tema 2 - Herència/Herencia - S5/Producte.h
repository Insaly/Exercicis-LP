#ifndef	PRODUCTE_H
#define PRODUCTE_H

#include <string>
#include <iostream>
using namespace std;

class Producte
{
public:

	Producte() : m_codi(""), m_preu(0) {}
	Producte(const Producte& p) : m_codi(p.m_codi), m_preu(p.m_preu) {}
	Producte(const string& codi, float preu) : m_codi(codi), m_preu(preu) {}

	~Producte() {}

	void setCodi(const string& codi) { m_codi = codi; }
	void setPreu(float preu) { m_preu = preu; }

	string getCodi() { return m_codi; }
	float getPreu() { return m_preu; }

	float calculaDespesesEnviament();
	void mostra();

private:

	string m_codi;
	
protected:

	float m_preu;
};

#endif // PRODUCTE_H