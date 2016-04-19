#include "Vector2D.h"

#include <iostream>

Vector2D::Vector2D()
{
}

Vector2D::Vector2D(const int x, const int y)
{
	m_x = x;
	m_y = y;
}


Vector2D::~Vector2D()
{
}

Vector2D & Vector2D::operator()(const std::string & message, Vector2D& v) const
{
	// TODO: insert return statement here
	std::cout << message << "\n";
	return v;
}

Vector2D & operator+=(Vector2D & v1, const Vector2D & v2)
{
	// TODO: insert return statement here
	v1.m_x += v2.m_x;
	v1.m_y += v2.m_y;

	return v1;
}
