#include <iostream>

using namespace std;

#include "Poligon.h"
#include "Punt.h"

const int COSTATSPOL = 10;

void omplirPoligon (Poligon &p)
{
	float vx[COSTATSPOL] = {3,5,7,9,10,12,15,25,36,42};
	float vy[COSTATSPOL] = {2,6,12,35,67,89,90,32,56,32};
    for (int i = 0; i < p.getNCostats(); i++)
    {
        cout << "Llegint coordenades del vertexIntrodueix coordenades del vertex " << i << ": ";
        Punt v(vx[i],vy[i]);
        p.afegeixVertex(v);
    }
}

void mostrarPoligon(Poligon &p,float& grade, bool& valid)
{
	float resx[COSTATSPOL]= { 3,5,7,9,10,12,15,25,36,42 };
	float resy[COSTATSPOL]= { 2,6,12,35,67,89,90,32,56,32 };
	for (int i = 1; i <= p.getNCostats(); i++)
	{
		Punt v;
		p.getVertex(i, v);
		float xRes, yRes;
		xRes=v.getX();
		yRes = v.getY();
		if (xRes == resx[i-1] and yRes == resy[i-1])
		{
			cout << "Comment :=>> Coordenades del vertex " << i << " CORRECTES I SON: " << xRes << ", " << yRes << endl;
			grade = grade + 0.26;
		}
		else
		{
			cout << "Comment :=>> Coordenades del vertex " << i << " INCORRECTES I SON: " << xRes << ", " << yRes << endl <<" Haurien de ser: " << resx[i-1] << ", " << resy[i-1] <<endl;
		}
		
	}
	float perimetre = p.calculaPerimetre();
	float ResPerimetre = 250.351;
	
	if (abs(perimetre - ResPerimetre) < 1e-4) 
	{
		cout << "Comment :=>> El perimetre del poligon es CORRECTE I VAL: " << perimetre << endl;
		grade = grade + 0.75;
	}
	else
	{
		cout << "Comment :=>> El perimetre del poligon es ERRONI VAL: " << perimetre << " I HAURIA DE VALER: " << ResPerimetre << endl;
		valid = false;
	}

}

int main()
{
	bool valid = true;
	float grade = 0.0;

    cout << "Comment :=>> Introduim el numero de costats del poligon: ";
    int nCostats;
    nCostats= COSTATSPOL;

    Poligon p(nCostats);

	if (nCostats == p.getNCostats())
	{
		omplirPoligon(p);
		mostrarPoligon(p,grade,valid);

	}
	else
		cout << "Comment :=>> ERROR" << endl;


	cout << endl << endl;
	cout << "Comment :=>> ====================================================" << endl;
	cout << "Comment :=>> COPIA DEL POLIGON" << endl;
	Poligon pCopia(p);
	mostrarPoligon(pCopia,grade,valid);



	cout << endl << endl;
	cout << "Comment :=>> ====================================================" << endl;
	cout << "Comment :=>> ASIGNACIO DEL POLIGON" << endl;
	Poligon pAssignacio;
	pAssignacio = p;
	mostrarPoligon(pAssignacio,grade,valid);

	if (grade < 0)
		grade = 0.0;
	
	if (grade > 10)
		grade = 10;

	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << endl << "Grade :=>> " << grade << endl;

    return 0;
}