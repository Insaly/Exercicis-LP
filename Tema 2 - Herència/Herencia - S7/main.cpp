#include "Figura.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cercle.h"
#include <list>
#include <iostream>
using namespace std;

int main()
{
	bool valid = true;
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de les classes LLISTA FIGURES VIRTUAL   " << endl;
	cout << "Comment :=>> ======================================================" << endl;
	cout << "Comment :=>>  " << endl << endl;


	cout << "Comment :=>> CREANT LLISTAFIGURES: " << endl;

	list<Figura*> llistaFigures;

	const int puntTriangle[3][3][2] = { {{3,3},{30,30},{30,3}} , {{13,13},{40,40},{53,13}} ,{{23,23},{50,50},{73,23}} };
	int puntCercle[3][3] = { {3,3,6},{30,30,90},{13,13,25} };
	int puntRectangle[3][4] = { {3,10,10,3},{30,50,50,30},{23,73,50,50} };

	cout << "Comment :=>> AFEGINT 3 TRIANGLES 3 RECTANGLES i 3 CERCLES    " << endl;
	cout << "Comment :=>> ==================================================" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Comment :=>> ======== CREANT I AFEGINT TRIANGLE " << i << endl;
		//Triangle t(puntTriangle[i]);
		llistaFigures.push_back(new Triangle(puntTriangle[i]));
		grade += 0.25;
		cout << "Comment :=>> ======== CREANT I AFEGINT CERCLE " << i << endl;
		//Cercle c(puntCercle[i][0], puntCercle[i][1], puntCercle[i][2]);
		llistaFigures.push_back(new Cercle(puntCercle[i][0], puntCercle[i][1], puntCercle[i][2]));
		grade += 0.25;
		cout << "Comment :=>> ======== CREANT I AFEGINT RECTANGLE " << i << endl;
		llistaFigures.push_back(new Rectangle(puntRectangle[i][0], puntRectangle[i][1], puntRectangle[i][2], puntRectangle[i][3]));
		grade += 0.25;
	}

	cout << "Comment :=>> VALIDANT CALCUL PERIMETRE I AREA    " << endl;
	cout << "Comment :=>> ====================================" << endl;
	float resPerimetre[9] = {92.1838,18.8496,28,108.15,188.496,80,123.652,81.6814,100};
	float resArea[9] = {364.5,28.2743,49,540,2827.43,400,675,530.92,621};
	int i = 0;
	list<Figura*>::iterator it;
	for (it = llistaFigures.begin(); it != llistaFigures.end(); it++)
	{
		(*it)->mostra();
		float peri = (*it)->getPerimetre();
		if (abs(resPerimetre[i] - peri) <= 0.01)
		{
			cout << "Comment :=>> ========CORRECTE Perimetre: " << peri << endl;
			grade += 0.2;
		}
		else
		{
			cout << "Comment :=>> ========ERROR Perimetre val: " << peri << " PERIMETRE OK:"<< resPerimetre[i] << endl;
			valid = false;
		}

		float areai = (*it)->getArea();
		if (abs(resArea[i] - areai) <= 0.01)
		{
			cout << "Comment :=>> ========CORRECTE Area: " << areai << endl;
			grade += 0.2;
		}
		else
		{
			cout << "Comment :=>> ========ERROR Area val: " << areai << " AREA OK:" << resArea[i] << endl;
			valid = false;
		}		
		i++;
	}

	cout << "Comment :=>> CLONANT LLISTA" << endl;
	cout << "Comment :=>> ==============" << endl;

	list<Figura*> llistaFigures2;
	for (it = llistaFigures.begin(); it != llistaFigures.end(); it++)
		llistaFigures2.push_back((*it)->clone());
	cout << "Comment :=>> VALIDANT CALCUL PERIMETRE I AREA A LLISTA CLONADA   " << endl;
	cout << "Comment :=>> ====================================================" << endl;
	i=0;
	for (it = llistaFigures2.begin(); it != llistaFigures2.end(); it++)
	{
		(*it)->mostra();
		float peri = (*it)->getPerimetre();
		if (abs(resPerimetre[i] - peri) <= 0.01)
		{
			cout << "Comment :=>> ========CORRECTE Perimetre: " << peri << endl;
			grade += 0.2;
		}
		else
		{
			cout << "Comment :=>> ========ERROR Perimetre val: " << peri << " PERIMETRE OK:" << resPerimetre[i] << endl;
			valid = false;
		}

		float areai = (*it)->getArea();
		if (abs(resArea[i] - areai) <= 0.01)
		{
			cout << "Comment :=>> ========CORRECTE Area: " << areai << endl;
			grade += 0.2;
		}
		else
		{
			cout << "Comment :=>> ========ERROR Area val: " << areai << " AREA OK:" << resArea[i] << endl;
			valid = false;
		}
		i++;
	}

	cout << "Comment :=>> ELIMINANT ELEMENTS LLISTA FIGURES: RECORDEU DESTRUCTOR VIRTUAL " << endl;
	cout << "Comment :=>> ===============================================================" << endl;
	for (it = llistaFigures.begin(); it != llistaFigures.end(); it++)
		delete (*it);
	for (it = llistaFigures2.begin(); it != llistaFigures2.end(); it++)
		delete (*it);

	grade += 0.55;

	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << endl << "Grade :=>> " << grade << endl;


	return 0;
}