#include "Cercle.h"

Cercle::Cercle(const Cercle& c)
{
	m_radi = c.m_radi;
	m_centre.x = c.m_centre.x;
	m_centre.y = c.m_centre.y;
}

Cercle::Cercle(float r, float x, float y)
{
	m_radi = r;
	m_centre.x = x;
	m_centre.y = y;
}

Cercle* Cercle::clone()
{
	return new Cercle(*this);
}

float Cercle::getPerimetre()
{
	return (2 * PI * m_radi);
}

float Cercle::getArea()
{
	return (PI * m_radi * m_radi);
}

void Cercle::mostra()
{
	cout << "Dades del Cercle" << endl;
	cout << "Centre del cercle: ";
	cout << "(" << m_centre.x << ", " << m_centre.y << ")" << endl;
	cout << "Longitud del radi: ";
	cout << m_radi << endl;
}
