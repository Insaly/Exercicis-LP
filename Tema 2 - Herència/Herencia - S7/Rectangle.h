#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Figura.h"
using namespace std;

class Rectangle : public Figura
{
public:
	Rectangle() {}
	Rectangle(const Rectangle& r);
	Rectangle(float xtl, float ytl, float xbr, float ybr);
	~Rectangle() {}
	Rectangle* clone() override;
	float getPerimetre() override;
	float getArea() override;
	void mostra() override;
private:
	Punt m_topLeft, m_bottomRight;
	float m_base, m_alcada;
};


#endif   //RECTANGLE_H
