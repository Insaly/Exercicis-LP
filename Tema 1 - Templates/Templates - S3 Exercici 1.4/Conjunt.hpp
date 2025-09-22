#pragma once
#include <iostream>
using namespace std;

template <class T>
class Conjunt
{
public:
	Conjunt();
	~Conjunt();
	bool afegeix(const T& valor);
	bool elimina(const T& valor); 
	bool existeix(const T& valor) const;
	bool esBuit() const { return (m_nElements == 0); }
	void mostra() const;
private:
	T *m_elements;
	int m_maxElements;
	int m_nElements;
	static const int MAX_ELEMENTS = 5;

	int cercaElement(const T& valor) const;
};

template <class T>
Conjunt<T>::Conjunt()
{
	m_maxElements = MAX_ELEMENTS;
	m_elements = new T[m_maxElements];
	m_nElements = 0;
}

template <class T>
Conjunt<T>::~Conjunt()
{
	delete[] m_elements;
}

template <class T>
bool Conjunt<T>::existeix(const T& valor) const
{
	int posicio = cercaElement(valor);
	if (posicio >= 0)	return true;
	return false;
}

template <class T>
int Conjunt<T>::cercaElement(const T& valor) const
{
	int posicio = 0;
	while (posicio < m_nElements)
	{
		if (m_elements[posicio] == valor)
			return posicio;
		else
			posicio++;
	}
	return -1;
}

template <class T>
void Conjunt<T>::mostra() const
{
	cout << "Elements del conjunt: " << endl;
	for (int i = 0; i < m_nElements; i++)
		cout << m_elements[i] << endl;
}

template <class T>
bool Conjunt<T>::afegeix(const T &valor)
{
	if (cercaElement(valor) == -1)
	{
		if (m_nElements == m_maxElements)
		{
			T* aux = new T[m_maxElements * 2];
			for (int i = 0; i < m_maxElements; i++)
				aux[i] = m_elements[i];
			delete[]m_elements;
			m_elements = aux;
			m_maxElements *= 2;
		}
		m_elements[m_nElements] = valor;
		m_nElements++;
		return true;
	}
	return false;
}

template <class T>
bool Conjunt<T>::elimina(const T& valor)
{
	int posicio = cercaElement(valor);

	if (posicio >= 0)
	{
		for (int i = posicio; i < (m_nElements - 1); i++)
			m_elements[i] = m_elements[i + 1];

		m_nElements--;
		return true;
	}
	return false;
}
