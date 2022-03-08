#include "Game.h"
#include "StateMachine.h"

Game::Game(char aMode) : RightPall(Entity(20.f, 80.f, 300.f, "Player1Pallete.png")), LeftPall(Entity(20.f, 80.f, 300.f, "Player2Pallete.png")), Ball(Entity(15.f, 15.f, 400.f, "Ball.png")), PauseScreen(PauseMenu())
{
	RightScore = 0;
	LeftScore = 0;

	Mode = aMode;

	AIMap['M'] = [this](Entity* Pallete, float PalLen, sf::Time dt, sf::Keyboard::Key Up, sf::Keyboard::Key Down)
	{
		PalleteInputMove(Pallete, PalLen, dt, Up, Down);
	};

	AIMap['SE'] = [this](Entity* Pallete, float PalLen, sf::Time dt, sf::Keyboard::Key Up, sf::Keyboard::Key Down)
	{
		PalleteEasyAI(Pallete, PalLen, dt, Up, Down);
	};

	AIMap['SH'] = [this](Entity* Pallete, float PalLen, sf::Time dt, sf::Keyboard::Key Up, sf::Keyboard::Key Down)
	{
		PalleteHardAI(Pallete, PalLen, dt, Up, Down);
	};

	UpCollider = DownCollider = sf::RectangleShape(sf::Vector2f(1024.f, 30.f));

	UpCollider.setOrigin(sf::Vector2f(512.f, 15.f));
	DownCollider.setOrigin(sf::Vector2f(512.f, 15.f));

	UpCollider.setPosition(sf::Vector2f(512.f, -15.f));
	DownCollider.setPosition(sf::Vector2f(512.f, 527.f));

	ScoreFont.loadFromFile("PressStart2P-Regular.ttf");

	ScoreText.setFont(ScoreFont);
	ScoreText.setCharacterSize(30);
	ScoreText.setFillColor(sf::Color::Blue);

	ballXdir = 1;
	ballYdir = 0;

	RightPall.Shape.setPosition(sf::Vector2f(50.f, 256.f));
	LeftPall.Shape.setPosition(sf::Vector2f(974.f, 256.f));
	Ball.Shape.setPosition(sf::Vector2f(1024.f / 2, 512.f / 2));

	ChangeScoreText(RightScore, LeftScore, &ScoreText);
}

Game::~Game()
{
}

void Game::Update(sf::Time dt, StateMachine* StateManager)
{
	if (PauseScreen.isPaused)
	{
		PauseScreen.Update(dt, StateManager);
	}

	if (!PauseScreen.isPaused)
	{
		PalleteInputMove(&RightPall, 80.f, dt, sf::Keyboard::Key::W, sf::Keyboard::Key::S);

		AIMap[Mode](&LeftPall, 80.f, dt, sf::Keyboard::Key::Up, sf::Keyboard::Key::Down);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			PauseScreen.isPaused = true;
		}
	}
}

void Game::FixedUpdate(sf::Time dt, StateMachine* StateManager)
{
	if (!PauseScreen.isPaused)
	{
		Ball.Move(dt.asSeconds(), ballXdir, ballYdir);

		TreatBallCollision();
	}
}

void Game::Draw(StateMachine* StateManager)
{
	StateManager->window->clear();

	RightPall.Draw(StateManager->window);

	LeftPall.Draw(StateManager->window);

	Ball.Draw(StateManager->window);

	StateManager->window->draw(ScoreText);

	if (PauseScreen.isPaused)
	{
		PauseScreen.Draw(StateManager);
	}

	StateManager->window->display();
}

void Game::TreatBallCollision()
{
	if (isColliding(RightPall.Shape, Ball.Shape))
	{
		ballYdir = sin(PIConst * (Ball.Shape.getPosition().y - RightPall.Shape.getPosition().y));
		ballXdir = sqrt(1 - pow(ballYdir, 2));

		if (Ball.MovementSpeed <= 640.f)
			Ball.MovementSpeed = 1.025f * Ball.MovementSpeed;
	}

	if (isColliding(LeftPall.Shape, Ball.Shape))
	{
		ballYdir = sin(PIConst * (Ball.Shape.getPosition().y - LeftPall.Shape.getPosition().y));
		ballXdir = -1 * sqrt(1 - pow(ballYdir, 2));
		if (Ball.MovementSpeed <= 640.f)
			Ball.MovementSpeed = 1.025f * Ball.MovementSpeed;
	}

	if (isColliding(Ball.Shape, UpCollider))
	{
		ballYdir = abs(ballYdir);
	}

	if (isColliding(Ball.Shape, DownCollider))
	{
		ballYdir = -1 * abs(ballYdir);
	}

	if (Ball.Shape.getPosition().x < 0 || Ball.Shape.getPosition().x > 1024.f)
	{
		(Ball.Shape.getPosition().x < 0) ? LeftScore++ : RightScore++;
		ChangeScoreText(RightScore, LeftScore, &ScoreText);
		Ball.Shape.setPosition(sf::Vector2f(1024.f / 2, 512.f / 2));
		ballYdir = 0;
		Ball.MovementSpeed = 400.f;
	}
}

void Game::PalleteInputMove(Entity* Pallete, float PalLen, sf::Time dt, sf::Keyboard::Key Up, sf::Keyboard::Key Down)
{
	if (sf::Keyboard::isKeyPressed(Up) && !isColliding(Pallete->Shape, UpCollider))
	{
		Pallete->Move(dt.asSeconds(), 0.f, -1.f);
	}

	if (sf::Keyboard::isKeyPressed(Down) && !isColliding(Pallete->Shape, DownCollider))
	{
		Pallete->Move(dt.asSeconds(), 0.f, 1.f);
	}
}

void Game::PalleteEasyAI(Entity* Pallete, float PalLen, sf::Time dt, sf::Keyboard::Key Up, sf::Keyboard::Key Down)
{
	float PalleteY = Pallete->Shape.getPosition().y;
	float BallY = Ball.Shape.getPosition().y;

	if (BallY < PalleteY + BallY * 0.05f && BallY > PalleteY - BallY * 0.05f)
		return;

	if (PalleteY > BallY && !isColliding(Pallete->Shape, UpCollider))
	{
		Pallete->Move(dt.asSeconds(), 0, -1);
	}

	if (PalleteY < BallY && !isColliding(Pallete->Shape, DownCollider))
	{
		Pallete->Move(dt.asSeconds(), 0, 1);
	}
}

void Game::PalleteHardAI(Entity* Pallete, float PalLen, sf::Time dt, sf::Keyboard::Key Up, sf::Keyboard::Key Down)
{
	float PalleteRY = RightPall.Shape.getPosition().y;
	float PalleteLY = LeftPall.Shape.getPosition().y;
	float BallY = Ball.Shape.getPosition().y;


	if (BallY < PalleteLY + PalLen / 2 && BallY > PalleteLY - PalLen / 2)
	{
		if (GetSign(PalleteRY - PalleteLY) > 0) // cacat
		{
			BallY = BallY - PalLen / 2 + 15.f;
		}

		else
		{
			BallY = BallY + PalLen / 2 - 15.f;
		}
	}

	if (PalleteLY > BallY && !isColliding(Pallete->Shape, UpCollider))
	{
		Pallete->Move(dt.asSeconds(), 0, -1);
	}

	if (PalleteLY < BallY && !isColliding(Pallete->Shape, DownCollider))
	{
		Pallete->Move(dt.asSeconds(), 0, 1);
	}
}