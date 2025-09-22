#include "Triangle.h"
#include <math.h>

Triangle::Triangle(const int m[3][2])
{
	float dx, dy;
	for (int i = 0; i < 3; i++)
	{
		m_vertexs[i].x = m[i][0];
		m_vertexs[i].y = m[i][1];
	}
	for (int i = 0; i < 3; i++)
	{
		dx = m_vertexs[(i + 1) % 3].x - m_vertexs[i].x;
		dy = m_vertexs[(i + 1) % 3].y - m_vertexs[i].y;
		m_costats[i] = sqrt(dx * dx + dy * dy);
	}
	dx = m_vertexs[0].x - m_vertexs[2].x;
	dy = m_vertexs[0].y - m_vertexs[2].y;
	m_costats[2] = sqrt(dx * dx + dy * dy);
}

Triangle::Triangle(const Triangle& t)
{
	for (int i = 0; i < 3; i++)
	{
		m_vertexs[i].x = t.m_vertexs[i].x;
		m_vertexs[i].y = t.m_vertexs[i].y;
		m_costats[i] = t.m_costats[i];
	}
}


Triangle* Triangle::clone()
{
	return new Triangle(*this);
}

float Triangle::getPerimetre()
{
	float perimetre = 0;
	for (int i = 0; i < 3; i++)
		perimetre += m_costats[i];
	return perimetre;
}

float Triangle::getArea()
{
	float s = getPerimetre() / 2;
	float area = s;
	for (int i = 0; i < 3; i++)
		area *= (s - m_costats[i]);
	area = sqrt(area);
	return area;
}

void Triangle::mostra()
{
	cout << "Dades del triangle" << endl;
	cout << "Vertexs: ";
	for (int i = 0; i < 3; i++)
		cout << "(" << m_vertexs[i].x << ", " << m_vertexs[i].y << ")" << endl;
}

