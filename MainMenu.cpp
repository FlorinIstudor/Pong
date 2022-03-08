#include "MainMenu.h"
#include "StateMachine.h"
#include "DifMenu.h"

MainMenu::MainMenu() : SinglePlayerButton(Button(sf::Text() , sf::RectangleShape(sf::Vector2f(360.f, 30.f)))), MultiPlayerButton(Button(sf::Text(), sf::RectangleShape(sf::Vector2f(360.f, 30.f)))), ExitButton(Button(sf::Text(), sf::RectangleShape(sf::Vector2f(360.f, 30.f))))
{

	MenuFont.loadFromFile("PressStart2P-Regular.ttf");

	SinglePlayerButtonText.setFont(MenuFont);
	MultiPlayerButtonText.setFont(MenuFont);
	ExitButtonText.setFont(MenuFont);
	TitleText.setFont(MenuFont);

	SinglePlayerButtonText.setCharacterSize(20);
	MultiPlayerButtonText.setCharacterSize(20);
	ExitButtonText.setCharacterSize(20);
	TitleText.setCharacterSize(50);

	SinglePlayerButtonText.setString("Singleplayer");
	MultiPlayerButtonText.setString("Local multiplayer");
	ExitButtonText.setString("Exit");
	TitleText.setString("P O N G");

	SinglePlayerButtonText.setFillColor(sf::Color(0,0,0));
	MultiPlayerButtonText.setFillColor(sf::Color(0,0,0));
	ExitButtonText.setFillColor(sf::Color(0,0,0));

	SinglePlayerButtonText.setOrigin(sf::Vector2f(120.f,10.f));
	MultiPlayerButtonText.setOrigin(sf::Vector2f(170.f,10.f));
	ExitButtonText.setOrigin(sf::Vector2f(40.f, 10.f));

	TitleText.setOrigin(sf::Vector2f(175.f, 25.f));

	SinglePlayerButton.ButtonText = SinglePlayerButtonText;
	MultiPlayerButton.ButtonText = MultiPlayerButtonText;
	ExitButton.ButtonText = ExitButtonText;

	SinglePlayerButton.SetPosition(sf::Vector2f(512.f, 300.f));
	MultiPlayerButton.SetPosition(sf::Vector2f(512.f, 340.f));
	ExitButton.SetPosition(sf::Vector2f(512.f, 380.f));
	TitleText.setPosition(sf::Vector2f(512.f,200.f));
}

MainMenu::~MainMenu()
{
}

void MainMenu::Draw(StateMachine* StateManager)
{
	StateManager->window->clear();
	
	StateManager->window->draw(TitleText);
	
	SinglePlayerButton.Draw(StateManager->window);

	MultiPlayerButton.Draw(StateManager->window);

	ExitButton.Draw(StateManager->window);

	StateManager->window->display();
}

void MainMenu::Update(sf::Time dt, StateMachine* StateManager)
{
	if (SinglePlayerButton.IsButtonPressed(StateManager->window))
	{
		StateManager->newScene = new DifMenu();
	}

	if (MultiPlayerButton.IsButtonPressed(StateManager->window))
	{
		StateManager->newScene = new Game('M');
	}

	if (ExitButton.IsButtonPressed(StateManager->window))
	{
		StateManager->window->close();
		exit(0);
	}
}

void MainMenu::FixedUpdate(sf::Time dt, StateMachine* StateManager)
{
}
