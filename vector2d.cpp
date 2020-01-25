#include "vector2d.h"

Vector2D::Vector2D(float pX, float pY)
	:x(pX), y(pY)
{
}

void Vector2D::Add(const Vector2D& left, const Vector2D& right, Vector2D& output)
{
	output.x = left.x + right.x;
	output.y = left.y + right.y;
}

void Vector2D::Subtract(const Vector2D& left, const Vector2D& right, Vector2D& output)
{
	output.x = left.x - right.x;
	output.y = left.y - right.y;
}

float Vector2D::Length(const Vector2D& vector)
{
	return sqrt((vector.x * vector.x) + (vector.y * vector.y));
}
