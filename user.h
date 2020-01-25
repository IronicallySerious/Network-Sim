#pragma once

typedef int UserID;

class BaseStation;

class User
{
	static int s_Count;

	UserID m_ID;
	BaseStation* m_ServingBaseStation;

public:
	User();
	User(User&) = delete;
	~User() = default;

	int getID() const { return m_ID; }
	BaseStation* getServingBaseStation() const { return m_ServingBaseStation; }
	
	void setServingBaseStation(BaseStation* servingBaseStation) { m_ServingBaseStation = servingBaseStation; }
};
