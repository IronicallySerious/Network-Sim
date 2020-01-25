#pragma once

#include <vector>

class User;

typedef int BaseStationID;

class BaseStation
{
	static int s_Count;
	BaseStationID m_ID;
	std::vector<User*> m_ServedUsers;

public:
	BaseStation();
	BaseStation(BaseStation&) = delete;
	~BaseStation() = default;

	bool serve(User* user);
};
