#include "Conjunt.hpp"
#include "Racional.h"
#include <iostream>
using namespace std;

int main()
{
	bool valid = true;
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la classe CONJUNT AMB INT" << endl;
	cout << "Comment :=>> ==========================================" << endl;
	cout << "Comment :=>>  " << endl << endl;
	Conjunt<int> c;
	grade += 0.5;

	cout << "Comment :=>> Inicialitzant Conjunt ....................... " << endl;
	for (int i = 0; i < 10; i++)
		c.afegeix(i);
	grade +=1;

	cout << "Comment :=>> Mostrant Comnjunt despres d'Inicialitzar ....................... " << endl;
	c.mostra();
	grade +=1;

	cout << "Comment :=>> Verificant si elements existeixen al Conjunt ....................... " << endl;
	for (int i = 0; i < 10; i++)
		if ( c.existeix(i))  grade += 0.1;

	cout << "Comment :=>> Eliminant 4 i 5 al Conjunt ....................... " << endl;
	c.elimina(4);
	c.elimina(6);
	grade += 1;

	cout << "Comment :=>> Mostrant Comnjunt despres d'eliminar elements 4 i 5 ....................... " << endl;
	c.mostra();
	grade += 1;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la classe CONJUNT AMB RACIONAL" << endl;
	cout << "Comment :=>> ===============================================" << endl;
	cout << "Comment :=>>  " << endl << endl;
	Conjunt<Racional> cRacionals;
	grade += 0.5;

	Racional r;
	r.setNumerador(1);
	r.setDenominador(2);
	cout << "Comment :=>> Afegint Racional al Conjunt ....................... " << endl;
	cRacionals.afegeix(r);
	grade += 1;

	cout << "Comment :=>> Mirant si Existeix Element al Conjunt i eliminant....................... " << endl;
	if (cRacionals.existeix(r))
		cRacionals.elimina(r);
	grade += 1;

	cout << "Comment :=>> Afegint un conjunt de racionals al Conjunt....................... " << endl;
	for (int i = 2; i < 10; i++)
	{
		r.setDenominador(i);
		cRacionals.afegeix(r);
	}
	grade += 1;

	cout << "Comment :=>> Mostrant Comnjunt despres d'Inicialitzar ....................... " << endl;
	cRacionals.mostra();
	grade += 1;

	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << endl << "Grade :=>> " << grade << endl;

	return 0;	
}