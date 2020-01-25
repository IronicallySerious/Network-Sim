#include "user.h"

int User::s_Count = 0;

User::User()
	: m_ID(s_Count++), m_ServingBaseStation(nullptr)
{
}
