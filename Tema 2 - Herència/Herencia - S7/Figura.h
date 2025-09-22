#ifndef FIGURA_H
#define FIGURA_H

typedef struct
{
	int x, y;
} Punt;


class Figura
{
public:
	Figura() {};
	virtual ~Figura() {};
	virtual Figura* clone() = 0;
	virtual float getPerimetre() = 0;
	virtual float getArea() = 0;
	virtual void mostra() = 0;
};


#endif  //FIGURA_H
