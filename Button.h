#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Utilities.h"

class Button
{
private:
	sf::RectangleShape ButtonShape;

public:
	sf::Text ButtonText;

	Button(const sf::Text& aText,const sf::RectangleShape& aShape);

	~Button();

	//functions

	void SetPosition(sf::Vector2f v);

	void Draw(sf::RenderWindow* window);

	bool IsButtonPressed(sf::RenderWindow* window);
};

