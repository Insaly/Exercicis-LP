#include <iostream>
#include "Hash.h"
using namespace std;

void imprimirvect(vector<pair<string, string> >&  vSol)
{
	for (int i = 0; i < vSol.size(); i++)
	{
		if (vSol[i].first != "")
		{
			cout << "Comment :=>> POS: " << i << "  CLAU: " << vSol[i].first << "  VALOR: " << vSol[i].second << endl; 
		}
	}
}

bool Iguals(Hash& h, vector<pair<string, string> >&  vSol)
{
	int i = 0;
	bool diferents = false;
	while ((i < vSol.size()) && !diferents)
	{
		if (vSol[i].first != "" && vSol[i].second != h[vSol[i].first])
		{
			diferents = true;
		}
		i++;
	}
	return !diferents;
}

int main()
{
		float grade = 0.0;
		Hash h;
		string definicio="";
	try
	{
		vector<pair<string, string> > vSol;
		vSol.resize(15,pair<string,string>("",""));
		vSol[0] = std::make_pair("Adeu", "Es un comiat.");
		vSol[1] = std::make_pair("Setmana", "Es un periode de 7 dies.");
		vSol[2] = std::make_pair("Hola", "Es una salutacio.");
		vSol[3] = std::make_pair("", "");
		vSol[4] = std::make_pair("Mes", "Es un periode de entre 28 i 31 dies.");
		vSol[5] = std::make_pair("Any", "Es un periode de 12 mesos.");
		vSol[6] = std::make_pair("", "");
		vSol[7] = std::make_pair("ornitorinc", "Animal.");
		
		const int MAXELEMENTS = 6;
		pair<string, string> vEntrada[MAXELEMENTS] = {
			pair<string,string>("Hola", "Es una salutacio."),
			pair<string,string>("Adeu","Es un comiat."),
			pair<string,string>("Dia", "Es un periode de 24 hores."),
			pair<string,string>("Mes", "Es un periode de entre 28 i 31 dies."),
			pair<string,string>("Any", "Es un periode de 12 mesos."),
			pair<string,string>("ornitorinc", "Animal."),
		};

		for (int i = 0; i < MAXELEMENTS; i++)
		{
			h.insert(vEntrada[i].first, vEntrada[i].second);			
		}

		cout << "Comment :=>> =====DICCIONARI=====" << endl;
		cout << h << endl;

		cout << "Comment :=>> Definicio de caleidoscopi es: " << h["caleidoscopi"] <<endl;
		cout << "Comment :=>> Definicio d'eina es: " << h["eina"] <<endl;

		cout << "Comment :=>> =====DICCIONARI DESPRES CERCA=====" << endl;
		cout << h << endl;
		cout << "Comment :=>> Definicio de Any es: " << h["Any"] << endl;

		cout << "Comment :=>> Trobem Setmana?: " << h.find("Setmana", definicio) << endl;
		
		cout << "Comment :=>> =====DICCIONARI DESPRES FIND=====" << endl;
		cout << h << endl;
		if (h.find("Setmana",definicio) == 0) grade += 2.5;

		
		cout << "Comment :=>> =====DICCIONARI DESPRES OPERATOR[]=====" << endl;
		cout << h << endl;

		cout << "Comment :=>> =====INSERT SETMANA=====" << endl;
		h.insert("Setmana", "Es un periode de 7 dies.");
		cout << "Comment :=>> Trobem Setmana?: " << h.find("Setmana",definicio) << endl;
		cout << "Comment :=>> Definicio de Setmana es: " << h["Setmana"] << endl;
		if (h.find("Setmana",definicio) == 1) grade += 2.5;

		cout << "Comment :=>> =====DICCIONARI DESPRES insert=====" << endl;
		cout << h << endl;

		cout << "Comment :=>> =====ESBORREM dia=====" << endl;
		h.esborra("Dia");
		cout << "Comment :=>> =====DICCIONARI DESPRES esborrar=====" << endl;
		cout << h << endl;

		if (Iguals(h, vSol))
		{
			grade += 5;
		}
		else 
		{
			cout << "Comment :=>> ERROR RESULTAT FINAL....................... " << endl;
			cout << "Comment :=>> DICCIONARI OBTINGUT     ....................... " << endl;
			cout << h << endl;
			cout << "Comment :=>> DICCIONARI ESPERAT     ....................... " << endl;
			imprimirvect(vSol);	
		}


		if (grade == 10)
			cout << "Comment :=>> Final del test sense errors" << endl;
		else
			cout << "Comment :=>> El resultat no es correcte" << endl;


		cout << endl << "Grade :=>> " << grade << endl;
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	catch (std::out_of_range)
	{
		cout << "Comment :=>> Intentes accedir a una posicio fora del vector";
	}
	return 0;
}