#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Figura.h"
using namespace std;


class Triangle : public Figura
{
public:
	Triangle() {}
	Triangle(const Triangle& t);
	Triangle(const int m[3][2]);
	~Triangle() {}
	Triangle* clone() override;
	float getPerimetre() override;
	float getArea() override;
	void mostra() override;
private:
	Punt m_vertexs[3];
	float m_costats[3];
};


#endif  //TRIANGLE_H
