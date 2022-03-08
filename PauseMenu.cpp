#include "PauseMenu.h"
#include "StateMachine.h"
#include "MainMenu.h"

PauseMenu::PauseMenu() : ResumeButton(Button(sf::Text(), sf::RectangleShape(sf::Vector2f(130.f, 25.f)))), MenuButton(Button(sf::Text(), sf::RectangleShape(sf::Vector2f(130.f, 25.f)))), ExitButton(Button(sf::Text(), sf::RectangleShape(sf::Vector2f(130.f, 25.f))))
{
	isPaused = false;

	PauseMenuFont.loadFromFile("PressStart2P-Regular.ttf");

	ResumeButtonText.setFont(PauseMenuFont);
	MenuButtonText.setFont(PauseMenuFont);
	ExitButtonText.setFont(PauseMenuFont);
	PauseMenuText.setFont(PauseMenuFont);

	ResumeButtonText.setCharacterSize(20);
	MenuButtonText.setCharacterSize(20);
	ExitButtonText.setCharacterSize(20);
	PauseMenuText.setCharacterSize(30);

	ResumeButtonText.setString("Resume");
	MenuButtonText.setString("Menu");
	ExitButtonText.setString("Exit");
	PauseMenuText.setString("PAUSED");

	ResumeButtonText.setFillColor(sf::Color(0, 0, 0));
	MenuButtonText.setFillColor(sf::Color(0, 0, 0));
	ExitButtonText.setFillColor(sf::Color(0, 0, 0));

	ResumeButtonText.setOrigin(sf::Vector2f(60.f, 10.f));
	MenuButtonText.setOrigin(sf::Vector2f(40.f, 10.f));
	ExitButtonText.setOrigin(sf::Vector2f(40.f, 10.f));

	PauseMenuText.setOrigin(sf::Vector2f(90.f, 15.f));

	ResumeButton.ButtonText = ResumeButtonText;
	MenuButton.ButtonText = MenuButtonText;
	ExitButton.ButtonText = ExitButtonText;

	ResumeButton.SetPosition(sf::Vector2f(512.f, 256.f));
	MenuButton.SetPosition(sf::Vector2f(512.f, 286.f));
	ExitButton.SetPosition(sf::Vector2f(512.f, 316.f));

	PauseMenuText.setPosition(sf::Vector2f(512.f, 225.f));
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::Draw(StateMachine* StateManager)
{
	StateManager->window->draw(PauseMenuText);
	ResumeButton.Draw(StateManager->window);
	MenuButton.Draw(StateManager->window);
	ExitButton.Draw(StateManager->window);
}

void PauseMenu::Update(sf::Time dt, StateMachine* StateManager)
{
	if (ResumeButton.IsButtonPressed(StateManager->window))
	{
		isPaused = false;
	}

	if (MenuButton.IsButtonPressed(StateManager->window))
	{
		StateManager->newScene = new MainMenu();
	}
	
	if (ExitButton.IsButtonPressed(StateManager->window))
	{
		StateManager->window->close();
		exit(0);
	}
}

