#include "DifMenu.h"
#include "StateMachine.h"
#include "MainMenu.h"

DifMenu::DifMenu() : EasyButton(Button(sf::Text(), sf::RectangleShape(sf::Vector2f(360.f,30.f)))), HardButton(Button(sf::Text(), sf::RectangleShape(sf::Vector2f(360.f, 30.f)))), BackButton(Button(sf::Text(), sf::RectangleShape(sf::Vector2f(360.f, 30.f))))
{

	DifMenuFont.loadFromFile("PressStart2P-Regular.ttf");

	EasyButtonText.setFont(DifMenuFont);
	HardButtonText.setFont(DifMenuFont);
	BackButtonText.setFont(DifMenuFont);
	currentText.setFont(DifMenuFont);

	EasyButtonText.setCharacterSize(20);
	HardButtonText.setCharacterSize(20);
	BackButtonText.setCharacterSize(20);
	currentText.setCharacterSize(30);

	EasyButtonText.setString("Easy");
	HardButtonText.setString("Hard");
	BackButtonText.setString("Return");
	currentText.setString("Choose a difficulty:");

	EasyButtonText.setFillColor(sf::Color(0, 0, 0));
	HardButtonText.setFillColor(sf::Color(0, 0, 0));
	BackButtonText.setFillColor(sf::Color(0, 0, 0));

	EasyButtonText.setOrigin(sf::Vector2f(40.f,10.f));
	HardButtonText.setOrigin(sf::Vector2f(40.f, 10.f));
	BackButtonText.setOrigin(sf::Vector2f(60.f, 10.f));

	currentText.setOrigin(sf::Vector2f(285.f, 15.f));

	EasyButton.ButtonText = EasyButtonText;
	HardButton.ButtonText = HardButtonText;
	BackButton.ButtonText = BackButtonText;

	EasyButton.SetPosition(sf::Vector2f(512.f, 300.f));
	HardButton.SetPosition(sf::Vector2f(512.f, 340.f));
	BackButton.SetPosition(sf::Vector2f(512.f, 380.f));

	currentText.setPosition(sf::Vector2f(512.f, 250.f));
}

DifMenu::~DifMenu()
{
}

void DifMenu::Update(sf::Time dt, StateMachine* StateManager)
{
	if (EasyButton.IsButtonPressed(StateManager->window))
	{
		StateManager->newScene = new Game('SE');
	}

	if (HardButton.IsButtonPressed(StateManager->window))
	{
		StateManager->newScene = new Game('SH');
	}

	if (BackButton.IsButtonPressed(StateManager->window))
	{
		StateManager->newScene = new MainMenu();
	}
}

void DifMenu::FixedUpdate(sf::Time dt, StateMachine* StateManager)
{
}

void DifMenu::Draw(StateMachine* StateManager)
{
	StateManager->window->clear();

	StateManager->window->draw(currentText);

	EasyButton.Draw(StateManager->window);

	HardButton.Draw(StateManager->window);

	BackButton.Draw(StateManager->window);

	StateManager->window->display();
}
