#pragma once

#include <math.h>

struct Vector2D
{
	float x;
	float y;

	Vector2D(float pX = 0.0f, float pY = 0.0f);
	~Vector2D() = default;

	static void Add(const Vector2D& left, const Vector2D& right, Vector2D& output);
	static void Subtract(const Vector2D& left, const Vector2D& right, Vector2D& output);
	static float Length(const Vector2D& vector);
};
