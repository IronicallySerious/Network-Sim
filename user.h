#pragma once

#include "vector2d.h"

typedef int UserID;
typedef float OutputPower;
typedef float InputPower;

class BaseStation;

class User
{
	static int s_Count;
	static const float s_Noise;

	UserID m_ID;
	BaseStation* m_ServingBaseStation;
	Vector2D m_Position;

public:
	User(Vector2D position);
	~User() = default;

	void assign(BaseStation* station, float powerBias);
	void receive(OutputPower sentPower, const BaseStation const* sender);

	int getID() const { return m_ID; }
	Vector2D getPosition() const { return m_Position; }
	BaseStation* getServingBaseStation() const { return m_ServingBaseStation; }
	
	void setServingBaseStation(BaseStation* servingBaseStation) { m_ServingBaseStation = servingBaseStation; }
};
