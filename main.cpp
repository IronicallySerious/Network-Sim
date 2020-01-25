#include <iostream>

#include "base_station.h"
#include "user.h"

int main()
{
	User kaustubh;
	User bhavye;
	User twarit;

	BaseStation airtel;
	BaseStation jio;
	BaseStation vodafone;

	airtel.serve(&twarit);
	airtel.serve(&kaustubh);
	airtel.serve(&bhavye);
	vodafone.serve(&twarit);
}
