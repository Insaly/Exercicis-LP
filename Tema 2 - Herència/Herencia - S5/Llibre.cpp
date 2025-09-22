#include "Llibre.h"

float Llibre::calculaDespesesEnviament()
{
    float despeses = Producte::calculaDespesesEnviament();

    if (m_nPagines > 500)
        despeses += 1.0;
    return despeses;
}

float Llibre::calculaPreu(int nUnitats)
{
    float preu = m_preu * nUnitats;
    preu += calculaDespesesEnviament();

    if (nUnitats > 100)
        return (preu - 0.1 * preu);

    if (nUnitats > 5)
        return (preu - 0.05 * preu);

    return preu;
}

void Llibre::mostra()
{
    Producte::mostra();
    cout << "Titol: " << m_titol << endl;
    cout << "Autor: " << m_autor << endl;
    cout << "Nº Pagines: " << m_nPagines << endl;
}