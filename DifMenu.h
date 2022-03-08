#pragma once
#include "Scene.h"
#include "Button.h"
#include "Game.h"

class StateMachine;
class MainMenu;

class DifMenu : public Scene
{
private:
	sf::Font DifMenuFont;

	Button EasyButton, HardButton, BackButton;

	sf::Text currentText, EasyButtonText, HardButtonText, BackButtonText;

public:
	DifMenu();

	~DifMenu();

//functions

	void Draw(StateMachine* StateManager) override;

	void Update(sf::Time dt, StateMachine* StateManager) override;

	void FixedUpdate(sf::Time dt, StateMachine* StateManager) override;
};

