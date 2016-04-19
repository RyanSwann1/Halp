#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <string>
class Vector2D
{
	friend Vector2D& operator +=(Vector2D& v1, const Vector2D& v2);
public:
	Vector2D();
	Vector2D(const int x, const int y);
	~Vector2D();

	Vector2D& operator()(const std::string& message, Vector2D& v) const;

	float m_x;
	float m_y;

private:

};
#endif // !VECTOR2D_H
