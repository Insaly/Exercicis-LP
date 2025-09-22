#include "Electrodomestic.h"
#include "math.h"

float Electrodomestic::calculaDespesesEnviament()
{
    float despeses = Producte::calculaDespesesEnviament();
    despeses += ceil(m_volum / 20);
    return despeses;
}

float Electrodomestic::calculaPreu(int nUnitats)
{
    float preu = m_preu * nUnitats;
    preu += calculaDespesesEnviament();

    if (nUnitats > 1)
        return (preu - 0.1 * preu);
    
    return preu;
}

void Electrodomestic::mostra()
{
    Producte::mostra();
    cout << "Marca: " << m_marca << endl;
    cout << "Model: " << m_model << endl;
    cout << "Volum: " << m_volum << endl;
}