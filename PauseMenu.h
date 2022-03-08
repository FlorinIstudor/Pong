#pragma once
#include "Scene.h"
#include "Button.h"

class StateMachine;

class PauseMenu : public Scene
{
private:

	Button ResumeButton, MenuButton, ExitButton;
	sf::Text ResumeButtonText, MenuButtonText, ExitButtonText;
	sf::Text PauseMenuText;
	sf::Font PauseMenuFont;

public:

	bool isPaused;

	PauseMenu();
	~PauseMenu();

	void Draw(StateMachine* StateManager) override;
	void Update(sf::Time dt, StateMachine* StateManager) override;
};

