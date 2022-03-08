#include "StateMachine.h"

StateMachine::StateMachine(sf::RenderWindow* aWindow) : window(aWindow)
{
	currentScene = new MainMenu();
	newScene = nullptr;
}

StateMachine::~StateMachine()
{
	delete currentScene;
}

void StateMachine::Update(sf::Time dt)
{
	currentScene->Update(dt,this);
	CheckChange();
}

void StateMachine::FixedUpdate(sf::Time dt)
{
	currentScene->FixedUpdate(dt,this);
	CheckChange();
}

void StateMachine::Draw()
{
	currentScene->Draw(this);
}

void StateMachine::CheckChange()
{
	if (newScene!=nullptr)
	{
		delete currentScene;
		currentScene = newScene;
		newScene = nullptr;
	}
}
