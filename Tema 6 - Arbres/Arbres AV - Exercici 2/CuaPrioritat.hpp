#pragma once
#include "Heap.hpp"

template <class T>
class CuaPrioritat
{
public:
	CuaPrioritat() {}
	~CuaPrioritat() {}
	CuaPrioritat(const CuaPrioritat<T>& cua);
	CuaPrioritat& operator=(const CuaPrioritat<T>& cua);

	bool esBuida() const;
	int getNElements() const;
	T& top();
	void push(const T& element);
	void pop();
	void remove(const T& element);
private:
	Heap<T> heap;
};

template<class T>
CuaPrioritat<T>::CuaPrioritat(const CuaPrioritat<T>& cua)
{
	heap = cua.heap;
}

template<class T>
CuaPrioritat<T>& CuaPrioritat<T>::operator=(const CuaPrioritat<T>& cua)
{
	if (this != &cua)
	{
		heap = cua.heap;
	}
	return *this;
}

template<class T>
bool CuaPrioritat<T>::esBuida() const
{
	return heap.esBuit();
}

template<class T>
int CuaPrioritat<T>::getNElements() const
{
	return heap.getMida() + 1;
}

template<class T>
T& CuaPrioritat<T>::top()
{
	return heap.getMinim();
}

template<class T>
void CuaPrioritat<T>::push(const T& element)
{
	heap.insereix(element);
}

template<class T>
void CuaPrioritat<T>::pop()
{
	heap.esborraMinim();
}

template<class T>
void CuaPrioritat<T>::remove(const T& element)
{
	heap.esborra(element);
}