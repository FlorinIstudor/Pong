#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <functional>

class StateMachine;

class Scene
{

public:

//functions
	virtual void Update(sf::Time dt, StateMachine* StateManager) {};
	virtual void FixedUpdate(sf::Time dt, StateMachine* StateManager) {};
	virtual void Draw(StateMachine* StateManager) {};
};

