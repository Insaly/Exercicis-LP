#include "Exercici.h"
#include <fstream>
using namespace std;

void Exercici::inicialitzaEstudiants(const string& fitxerEstudiants)
{
    ifstream fitxer(fitxerEstudiants);

    if (fitxer.is_open())
    {
        fitxer >> m_nEstudiants;
        m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];

        string niu;
        
        for (int i = 0; i < m_nEstudiants; ++i)
        {
            fitxer >> niu;
            m_lliuraments[i].setNiu(niu);
        }

        fitxer.close();
    }
}

bool Exercici::afegeixTramesa(const string& niu, const string& fitxer, const string& data)
{
    for (int i = 0; i < m_nEstudiants; ++i)
    {
        if (m_lliuraments[i].getNiu() == niu)
        {
            m_lliuraments[i].afegeixTramesa(fitxer, data);
            return true;
        }
    }

    return false;
}

bool Exercici::consultaTramesa(const string& niu, const string& data, string& fitxer)
{
    for (int i = 0; i < m_nEstudiants; ++i)
    {
        if (m_lliuraments[i].getNiu() == niu)
        {
            return m_lliuraments[i].consultaTramesa(data, fitxer);
        }
    }

    return false;
}

bool Exercici::eliminaTramesa(const string& niu, const string& data)
{
    for (int i = 0; i < m_nEstudiants; ++i)
    {
        if (m_lliuraments[i].getNiu() == niu)
        {
            return m_lliuraments[i].eliminaTramesa(data);
        }
    }

    return false;
}

Exercici& Exercici::operator=(const Exercici& e)
{
    if (this != &e)
    {
        m_descripcio = e.m_descripcio;
        m_dataLimit = e.m_dataLimit;

        if (m_lliuraments != nullptr)
            delete[] m_lliuraments;

        if (e.m_lliuraments != nullptr)
        {
            m_lliuraments = new LliuramentsEstudiant[e.m_nEstudiants];
            m_nEstudiants = e.m_nEstudiants;

            for (int i = 0; i < m_nEstudiants; ++i)
                m_lliuraments[i] = e.m_lliuraments[i];
        }

        else
            m_lliuraments = nullptr;
    }

    return *this;
}

Exercici::Exercici(const Exercici& e)
{
    m_descripcio = e.m_descripcio;
    m_dataLimit = e.m_dataLimit;

    if (e.m_lliuraments != nullptr)
    {
        m_lliuraments = new LliuramentsEstudiant[e.m_nEstudiants];
        m_nEstudiants = e.m_nEstudiants;

        for (int i = 0; i < m_nEstudiants; ++i)
            m_lliuraments[i] = e.m_lliuraments[i];
    }

    else
        m_lliuraments = nullptr;
}

Exercici::~Exercici()
{
    delete[] m_lliuraments;
    m_lliuraments = nullptr;
    m_nEstudiants = 0;
}

