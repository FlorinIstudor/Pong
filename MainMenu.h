#pragma once
#include "Scene.h"
#include "Button.h"
#include "Game.h"

class StateMachine;
class DifMenu;

class MainMenu : public Scene
{
private:
	Button SinglePlayerButton, MultiPlayerButton, ExitButton;

	sf::Text TitleText, SinglePlayerButtonText, MultiPlayerButtonText, ExitButtonText;

	sf::Font MenuFont;

public:
	MainMenu();

	~MainMenu();

	//functions

	void Draw(StateMachine* StateManager) override;

	void Update(sf::Time dt, StateMachine* StateManager) override;

	void FixedUpdate(sf::Time dt, StateMachine* StateManager) override;
};

