#include <iostream>
#include "Llibre.h"
#include "Electrodomestic.h"
using namespace std;

int main()
{
	bool valid = true;
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de les classes Productes, Llibres i Electrodomestics" << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>>  " << endl << endl;


	Producte p;
	p.setCodi("CODI_1");
	p.setPreu(10);
	p.mostra();
	grade += 2;

	Llibre l;
	l.setCodi("CODI_2");
	l.setPreu(20);
	l.setTitol("TITOL_1");
	l.setAutor("AUTOR_1");
	l.setnPagines(100);
	cout << endl << "Comment :=>> Dades Llibre: " << endl;
	l.mostra();
	grade += 2;

	float preu = l.calculaPreu(10);
	cout << "Comment :=>> El preu del llibre es: " << preu << endl;
	grade += 2;

	Electrodomestic e;
	e.setCodi("CODI_3");
	e.setPreu(300);
	e.setMarca("MARCA_1");
	e.setModel("MODEL_1");
	e.setVolum(50);
	cout << endl << "Comment :=>> Dades Electrodomestic: " << endl;
	e.mostra();
	grade += 2;

	preu = e.calculaPreu(10);
	cout << "Comment :=>> El preu de l'electrodomestic es: " << preu << endl;
	grade += 2;

	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << endl << "Grade :=>> " << grade << endl;

	return 0;

}

//////CODI QUE NECESSITAREU
/*
	//Constructors i desptructors per defecte
	Producte() {}
	~Producte() {}
	Llibre() {}
	~Llibre() {}

	//Getters i setters
	void setCodi(const string& codi){ m_codi=codi;}
	void setPreu(float preu){m_preu=preu;}
	string getCodi() { return m_codi; }
	float getPreu() { return m_preu; }
	void setTitol(const string& titol) { m_titol = titol; }
	string getTitol() { return m_titol; }
	void setAutor(const string& autor) { m_autor = autor; }
	string getAutor() { return m_autor; }
	void setnPagines(const int nPagines) { m_nPagines = nPagines; }
	int getNPagines() { return m_nPagines; }

	// Atributs que necessiteu mireu a quina classe van
	string m_codi;
	float m_preu;
	string m_titol;
	string m_autor;
	int m_nPagines;

*/

