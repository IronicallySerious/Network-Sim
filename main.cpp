#include <iostream>
#include <vector>

#include "base_station.h"
#include "user.h"

int main()
{
	std::vector<User> users;
	const int numUsers = 100;
	users.reserve(numUsers);

	for (int i = 0; i < numUsers; i++)
	{
		users.emplace_back(User(Vector2D(rand() % 100, rand() % 100)));
	}

	std::vector<BaseStation> baseStations;
	const int numStations = 10;
	users.reserve(numStations);
	
	baseStations.emplace_back(BaseStation(400, Vector2D(10, 10)));
	baseStations.emplace_back(BaseStation(400, Vector2D(10, 20)));
	baseStations.emplace_back(BaseStation(400, Vector2D(10, 30)));
	baseStations.emplace_back(BaseStation(400, Vector2D(10, 40)));
	baseStations.emplace_back(BaseStation(400, Vector2D(10, 50)));

	baseStations.emplace_back(BaseStation(400, Vector2D(90, 10)));
	baseStations.emplace_back(BaseStation(400, Vector2D(90, 20)));
	baseStations.emplace_back(BaseStation(400, Vector2D(90, 30)));
	baseStations.emplace_back(BaseStation(400, Vector2D(90, 40)));
	baseStations.emplace_back(BaseStation(400, Vector2D(90, 50)));

	for (auto&& user : users)
	{
		user.assign(&baseStations[rand() % baseStations.size()], 1.0f);
	}

	std::cout << "Press ENTER to broadcast" << std::endl;
	while (true)
	{
		std::cin.get();
		for (auto&& baseStation : baseStations)
		{
			baseStation.broadcast();
		}
	}
}
