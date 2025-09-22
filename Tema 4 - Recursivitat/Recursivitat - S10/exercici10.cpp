#pragma once

#include <iostream>
using namespace std;


// EXERCICI 1 ////////////////////////////////////////////////////////////////

float potenciaRec(float x, int n)
{
    if (n < 0)
	{
		return (1 / potenciaRec(x, -n));
	}
	else
	{
		if (n == 1)
		{
			return x;
		}
		else
		{
			return (x * potenciaRec(x, n - 1));
		}
	}
}

float potencia(float x, int n)
{
    if (n < 0)
	{
		return (1 / potenciaRec(x, -n));
	}
	else
	{
		if (n == 1)
		{
			return x;
		}
		else
		{
			return (x * potenciaRec(x, n - 1));
		}
	}
}

// EXERCICI 2 ////////////////////////////////////////////////////////////////

int QueFa(int v[], int n)
{
	if (n == 0)
	{
		cout << "RESULTAT queFa n= " << n << " Retorna = " << 0 << endl;
		return 0;
	}
	 
	cout << "RESULTAT queFa n= " << n << " Retorna = QueFa ( ";
	for (int i = 0; i < n; i++)
		cout << v[i];
	cout << " , " << n - 1 << " )  * 10 + " << v[n - 1] << endl;
	return QueFa(v, n - 1) * 10 + v[n - 1]; 	
}

int	QueFaIteratiu(int v[], int n)
{
	int resultat = 0;

    for (int i = 0; i < n; i++)
	{
		resultat = resultat * 10 + v[i];
	}
	
	return resultat;
}

// EXERCICI 3 ////////////////////////////////////////////////////////////////

int invertirNumeroRec(int n, int& potencia)
{
	if (n < 10)
	{
		return n;
	}
	else
	{
		int invertir = invertirNumeroRec(n / 10, potencia);
		potencia *= 10;
		int resultat = (n % 10) * potencia + invertir;
		return resultat;
	}
}

int invertirNumero(int n)
{
    int potencia = 1;
	return invertirNumeroRec(n, potencia);
}
