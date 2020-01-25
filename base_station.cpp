#include "base_station.h"
#include "user.h"

#include <iostream>

const float BaseStation::s_BandWidthPerConnection = 20 MHz;
int BaseStation::s_Count = 0;

BaseStation::BaseStation(OutputPower totalPower, Vector2D position)
	: m_ID(s_Count++), m_TotalPower(totalPower), m_Position(position)
{
}

bool BaseStation::serve(User* user, float powerBias)
{
	auto&& findIt = m_ServedUserAddresses.find(user->getID());
	if (findIt == m_ServedUserAddresses.end())
	{
		if (!user->getServingBaseStation())
		{
			m_ServedUsers.insert({ user->getID(), powerBias * m_TotalPower / (m_ServedUsers.size() + 1) });
			m_ServedUserAddresses[user->getID()] = user;
			user->setServingBaseStation(this);
			resetPowerOutputs();
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

void BaseStation::resetPowerOutputs()
{
	for (auto& [user, outputPower] : m_ServedUsers)
	{
		outputPower = m_TotalPower / m_ServedUsers.size();
	}
}

void BaseStation::broadcast()
{
	for (auto& [user, outputPower] : m_ServedUsers)
	{
		m_ServedUserAddresses[user]->receive(outputPower, this);
	}
}

bool operator==(std::pair<UserID, OutputPower> left, std::pair<UserID, OutputPower> right)
{
	return left.first == right.first && left.second == right.second;
}
