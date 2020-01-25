#pragma once

#include <unordered_map>

#include "vector2d.h"

class User;

typedef int BaseStationID;
typedef int UserID;
typedef float OutputPower;

#define MHz * 1e6

bool operator==(std::pair<UserID, OutputPower> left, std::pair<UserID, OutputPower> right);

class BaseStation
{
	static int s_Count;
	
	BaseStationID m_ID;
	OutputPower m_TotalPower;
	Vector2D m_Position;
	std::unordered_map<UserID, User*> m_ServedUserAddresses;
	std::unordered_map<UserID, OutputPower> m_ServedUsers;

public:
	static const float s_BandWidthPerConnection;
	
	BaseStation(OutputPower totalPower, Vector2D position);
	~BaseStation() = default;

	bool serve(User* user, float powerBias = 1.0f);
	void resetPowerOutputs();
	void broadcast();

	Vector2D getPosition() const { return m_Position; }
	BaseStationID getID() const { return m_ID; }
};
