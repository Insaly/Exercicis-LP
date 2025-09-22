#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include "Figura.h"
using namespace std;

const float PI = 3.141592;

class Cercle : public Figura
{
public:
	Cercle() {}
	Cercle(const Cercle& c);
	Cercle(float r, float x, float y);
	~Cercle() {}	
	Cercle* clone() override;
	float getPerimetre() override;
	float getArea() override;
	void mostra() override;
private:
	float m_radi;
	Punt m_centre;
};

#endif  //CERCLE_H
