#pragma once
#include "Game.h"
#include "MainMenu.h"
#include "DifMenu.h"

class StateMachine
{
private:
	Scene* currentScene;
	
public:
	sf::RenderWindow* window;
	Scene* newScene;
	
	StateMachine(sf::RenderWindow* aWindow);

	~StateMachine();

	//functions

	void Update(sf::Time dt);

	void FixedUpdate(sf::Time dt);

	void Draw();

	void CheckChange();

	
};

