#include "Matriu.h"
#include <cmath>

void Matriu::clear()
{
    m_nFiles = 0;
    m_nColumnes = 0;

    if (m_matriu)
    {
        for (int i = 0; i < m_nFiles; i++)
            delete[] m_matriu[i];
        delete[] m_matriu;
        m_matriu = nullptr;
    }
}

void Matriu::resize(int nFiles, int nColumnes)
{

	float** novaMatriu = nullptr;
	if (nFiles >= 0 && nColumnes >= 0) {
		novaMatriu = new float* [nFiles];
		for (int i = 0; i < nFiles; ++i) {
			novaMatriu[i] = new float[nColumnes];
			for (int j = 0; j < nColumnes; ++j) {
				novaMatriu[i][j] = 0;
			}
		}
	}

    int min_files, min_columnes;

    if (m_nFiles < nFiles)
        min_files = m_nFiles;
    else
        min_files = nFiles;
    
    if (m_nColumnes < nColumnes)
        min_columnes = m_nColumnes;
    else
        min_columnes = nColumnes;

	for (int i = 0; i < min_files; ++i) {
		for (int j = 0; j < min_columnes; ++j) {
			if (novaMatriu) {
				novaMatriu[i][j] = m_matriu[i][j];
			}
		}
	}

	clear();

	m_nFiles = nFiles;
	m_nColumnes = nColumnes;
	m_matriu = novaMatriu;
}

void Matriu::transpose()
{
    if (m_nColumnes == 0 || m_nFiles == 0)
        return;

    Matriu transposada(m_nColumnes, m_nFiles);

    for (int i = 0; i < m_nFiles; i++)
        for (int j = 0; j < m_nColumnes; j++)
            transposada.setValor(j, i, m_matriu[i][j]);

    *this = transposada;
}

Matriu& Matriu::operator=(const Matriu& m)
{
    if (this == &m)
        return *this;

    clear();
    resize(m.m_nFiles, m.m_nColumnes);

    for (int i = 0; i < m_nFiles; i++)
        for (int j = 0; j < m_nColumnes; j++)
            m_matriu[i][j] = m.m_matriu[i][j];

    return *this;
}

void Matriu::initValor(float valor)
{
    for (int i = 0; i < m_nFiles; i++)
        for (int j = 0; j < m_nColumnes; j++)
            m_matriu[i][j] = valor;
}

void Matriu::setValor(int fila, int columna, float valor)
{
    if (fila < 0 || fila >= m_nFiles || columna < 0 || columna >= m_nColumnes)
        return;

    m_matriu[fila][columna] = valor;
}

Matriu Matriu::operator+(const Matriu& m)
{
    if (m_nFiles != m.m_nFiles || m_nColumnes != m.m_nColumnes)
        return Matriu();

    Matriu suma(m_nFiles, m_nColumnes);

    for (int i = 0; i < m_nFiles; i++)
        for (int j = 0; j < m_nColumnes; j++)
            suma.setValor(i, j, m_matriu[i][j] + m.m_matriu[i][j]);

    return suma;
}

Matriu Matriu::operator+(float s)
{
    Matriu suma(m_nFiles, m_nColumnes);

    for (int i = 0; i < m_nFiles; i++)
        for (int j = 0; j < m_nColumnes; j++)
            suma.setValor(i, j, m_matriu[i][j] + s);

    return suma;
}

bool Matriu::operator==(const Matriu& m)
{
    if (m_nFiles != m.m_nFiles || m_nColumnes != m.m_nColumnes)
        return false;

    for (int i = 0; i < m_nFiles; i++)
        for (int j = 0; j < m_nColumnes; j++)
            if (m_matriu[i][j] != m.m_matriu[i][j])
                return false;

    return true;
}

float Matriu::getValor(int fila, int columna) const
{
    if (fila < 0 || fila >= m_nFiles || columna < 0 || columna >= m_nColumnes)
        return 0;

    return m_matriu[fila][columna];
}