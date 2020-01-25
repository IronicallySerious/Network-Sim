#include "user.h"

#include <iostream>

#include "base_station.h"

int User::s_Count = 0;
const float User::s_Noise = 1e-6;

User::User(Vector2D position)
	: m_ID(s_Count++), m_ServingBaseStation(nullptr), m_Position(position)
{
}

void User::assign(BaseStation* station, float powerBias)
{
	station->serve(this, powerBias);
}

void User::receive(OutputPower sentPower, const BaseStation const * sender)
{
	Vector2D distance;
	Vector2D::Subtract(sender->getPosition(), this->getPosition(), distance);
	float d = Vector2D::Length(distance);
	float receivedPower = sentPower / (d * d);

	std::cout << "User " << m_ID << " received broadcast:" <<
		"\n\tSender: " << "\t" << sender->getID() <<
		"\n\tDistance: " << "\t" << d << " m"
		"\n\tSent P: " << "\t" << sentPower << " W"
		"\n\tReceived P: " << "\t" << receivedPower << " W"
		"\n\tB: " << "\t\t" << BaseStation::s_BandWidthPerConnection * log2f(1 + (receivedPower / s_Noise)) / 1000.0f << " kbps" <<
		std::endl;
}
