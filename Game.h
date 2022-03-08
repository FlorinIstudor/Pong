#pragma once

#include "Entity.h"
#include "Scene.h"
#include "Utilities.h"
#include "PauseMenu.h"

class StateMachine;

class Game : public Scene
{
private:

	Entity RightPall;
	Entity LeftPall;
	Entity Ball;

	sf::Texture RightPallTx, LeftPallTx, BallTx;

	sf::RectangleShape UpCollider, DownCollider;

	sf::Font ScoreFont;
	sf::Text ScoreText;

	PauseMenu PauseScreen;

	float ballXdir, ballYdir;
	int endPoint = 256;
	const float PIConst = 3.1416f / 160;

	int RightScore, LeftScore;

	char Mode;

	std::map< char, std::function<void(Entity*, float, sf::Time , sf::Keyboard::Key, sf::Keyboard::Key) > > AIMap;


public:
	Game(char aMode);

	~Game();

	//functions

	void Update(sf::Time dt, StateMachine* StateManager) override;

	void FixedUpdate(sf::Time dt, StateMachine* StateManager) override;

	void Draw(StateMachine* StateManager) override;

private:
	void TreatBallCollision();

	void PalleteInputMove(Entity*, float, sf::Time, sf::Keyboard::Key, sf::Keyboard::Key);

	void PalleteEasyAI(Entity*, float, sf::Time, sf::Keyboard::Key, sf::Keyboard::Key);

	void PalleteHardAI(Entity*, float, sf::Time, sf::Keyboard::Key, sf::Keyboard::Key);
};

