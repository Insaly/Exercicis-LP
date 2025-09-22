#include "Rectangle.h"

Rectangle::Rectangle(const Rectangle& r)
{
	m_topLeft.x = r.m_topLeft.x;
	m_topLeft.y = r.m_topLeft.y;
	m_bottomRight.x = r.m_bottomRight.x;
	m_bottomRight.y = r.m_bottomRight.y;
	m_base = r.m_base;
	m_alcada = r.m_alcada;
}

Rectangle::Rectangle(float xtl, float ytl, float xbr, float ybr)
{
	m_topLeft.x = xtl;
	m_topLeft.y = ytl;
	m_bottomRight.x = xbr;
	m_bottomRight.y = ybr;
	m_base = m_bottomRight.x - m_topLeft.x;
	m_alcada = m_topLeft.y - m_bottomRight.y;
}

Rectangle* Rectangle::clone()
{
	return new Rectangle(*this);
}

float Rectangle::getPerimetre()
{
	return (2 * m_base + 2 * m_alcada);
}

float Rectangle::getArea()
{
	return m_base * m_alcada;
}

void Rectangle::mostra()
{
	cout << "Dades del Rectangle" << endl;
	cout << "Cantonada superior esquerra: ";
	cout << "(" << m_topLeft.x << ", " << m_topLeft.y << ")" << endl;
	cout << "Cantonada inferior dreta: ";
	cout << "(" << m_bottomRight.x << ", " << m_bottomRight.y << ")" << endl;
}

