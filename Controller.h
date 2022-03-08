#pragma once
#include "Entity.h"

class Controller
{
private:
	Entity* Pallete;
	sf::RenderWindow Window;

public:

	Controller();

	~Controller();

//functions

	void Decide();
	void HandleMove();
};

