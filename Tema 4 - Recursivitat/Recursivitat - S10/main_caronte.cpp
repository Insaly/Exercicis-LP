#include <iostream>
using namespace std;

float potenciaRec(float x, int n);
float potencia(float x, int n);
int   QueFa(int v[], int n);
int   QueFaIteratiu(int v[], int n);
int   invertirNumero(int n);

int main()
{
	float grade = 0.0;
	bool valid = true;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test dels exercicis Sessio 10 Recursivitat               " << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>>  " << endl << endl;

	cout << "Comment :=>> =============== EXERCICI 1 POTENCIA RECURSIVA ====================" << endl;
	cout << "Comment :=>> RESULTAT POTENCIA 1 de x :" << 5 << " N vegades: " << 3 << " : " << endl;;
	float prec = potenciaRec(5, 3);
	if (prec == 125) {
		cout << "Comment :=>> CORRECTE calcul potencia: " << prec << endl;
		grade += 1.5;
	}
	else {
		cout << "Comment :=>> ERROR RESULTAT FINAL    ....................... " << endl;
		cout << "Comment :=>> Valor obtingut: " << prec << endl;
		cout << "Comment :=>> Valor esperat: 125      ....................... " << endl;
		valid = false;
	}

	cout << "Comment :=>> ==================================================================" << endl;
	float prec1 = potencia(5, -3);
	cout << "RESULTAT POTENCIA 2 de x :" << 5 << " N vegades: " << -3.0 << " : " << prec1 << endl;
	if ((prec1 >= 0.008) && (prec1 <= 0.009)){
		cout << "Comment :=>> CORRECTE calcul potencia: " << prec1 << endl;
		grade += 1.5;
	}
	else {
		cout << "Comment :=>> ERROR RESULTAT FINAL    ....................... " << endl;
		cout << "Comment :=>> Valor obtingut: " << prec1 << endl;
		cout << "Comment :=>> Valor esperat: 0.008    ....................... " << endl;
		valid = false;
	}

	cout << "Comment :=>> ==================================================================" << endl;
	float prec2 = potencia(3, 4);
	cout << "RESULTAT POTENCIA 2 de x :" << 3 << " N vegades: " << 4 << " : " << prec2 << endl;
	if (prec2 == 81) {
		cout << "Comment :=>> CORRECTE calcul potencia: " << prec2 << endl;
		grade += 1.5;
	}
	else {
		cout << "Comment :=>> ERROR RESULTAT FINAL    ....................... " << endl;
		cout << "Comment :=>> Valor obtingut: " << prec2 << endl;
		cout << "Comment :=>> Valor esperat: 81       ....................... " << endl;
		valid = false;
	}

	cout << "Comment :=>>  " << endl << endl;
	cout << "Comment :=>> ==================================================================" << endl;

	cout << "Comment :=>> ============== EXERCICI 2 QUEFA ITERATIU =========================" << endl;
	int v[5] = { 3, 5, 7, 4, 6 };
	int resQueFa = QueFa(v, 5);
	int resQueFai = QueFaIteratiu(v, 5);
	if ((resQueFai == 35746)&&(resQueFai == resQueFa)){
		cout << "Comment :=>> CORRECTE QueFaIteratiu: " << resQueFai << endl;
		grade += 1.5;
	}
	else {
		cout << "Comment :=>> ERROR RESULTAT FINAL    ....................... " << endl;
		cout << "Comment :=>> Valor obtingut: " << resQueFai << endl;
		cout << "Comment :=>> Valor esperat: 35746    ....................... " << endl;
		valid = false;
	}

	cout << "Comment :=>>  " << endl << endl;
	cout << "Comment :=>> ==================================================================" << endl;

	cout << "Comment :=>> ============== EXERCICI 3 INVERTIR NUMERO RECURSIU ===============" << endl;
	int res = invertirNumero(3456);
	if (res == 6543){
		cout << "Comment :=>> CORRECTE calcul invertir n�mero: " << res << endl;
		grade += 4.0;
	}
	else {
		cout << "Comment :=>> ERROR RESULTAT FINAL    ....................... " << endl;
		cout << "Comment :=>> Valor obtingut: " << res << endl;
		cout << "Comment :=>> Valor esperat: 6543     ....................... " << endl;
		valid = false;
	}

	cout << "Comment :=>>  " << endl << endl;
	cout << "Comment :=>> ==================================================================" << endl;

	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl;


	return 0;
}