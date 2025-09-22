#include "Producte.h"

float Producte::calculaDespesesEnviament()
{
    float despeses;

    if (m_preu < 100)
        despeses = 1.0;
    
    else
        despeses = 0.01 * m_preu;

    if (despeses > 5)
        despeses = 5.0;

    return despeses;
}

void Producte::mostra()
{
    cout << "Codi: " << m_codi << endl;
    cout << "Preu: " << m_preu << endl;
}