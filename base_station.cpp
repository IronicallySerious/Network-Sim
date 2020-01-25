#include "base_station.h"
#include "user.h"

#include <iostream>

int BaseStation::s_Count = 0;

BaseStation::BaseStation()
	:m_ID(s_Count++)
{
}

bool BaseStation::serve(User* user)
{
	auto&& findIt = std::find(m_ServedUsers.begin(), m_ServedUsers.end(), user);
	if (findIt == m_ServedUsers.end())
	{
		if (!user->getServingBaseStation())
		{
			m_ServedUsers.push_back(user);
			user->setServingBaseStation(this);
			return true;
		}
		else
		{
			std::cout << "Cannot serve user " << user->getID() << ": Already being served by another base station" << std::endl;
			return false;
		}
	}
	std::cout << "Cannot serve user " << user->getID() << ": Already being served" << std::endl;
	return false;
}
