#include "Button.h"

Button::Button(const sf::Text& aText,const sf::RectangleShape& aShape) : ButtonText(aText), ButtonShape(aShape)
{
	ButtonShape.setOrigin(sf::Vector2f(ButtonShape.getSize().x / 2, ButtonShape.getSize().y / 2));

	ButtonShape.setFillColor(sf::Color(211,211,211));
}

Button::~Button()
{
}

void Button::SetPosition(sf::Vector2f v)
{
	ButtonShape.setPosition(v);
	ButtonText.setPosition(v);
}

void Button::Draw(sf::RenderWindow* window)
{
	window->draw(ButtonShape);
	window->draw(ButtonText);
}

bool Button::IsButtonPressed(sf::RenderWindow* window)
{
	if (sf::Mouse::getPosition(*window).x < this->ButtonShape.getPosition().x + this->ButtonShape.getSize().x / 2 && sf::Mouse::getPosition(*window).x > this->ButtonShape.getPosition().x - this->ButtonShape.getSize().x / 2
		&& sf::Mouse::getPosition(*window).y < this->ButtonShape.getPosition().y + this->ButtonShape.getSize().y / 2 && sf::Mouse::getPosition(*window).y > this->ButtonShape.getPosition().y - this->ButtonShape.getSize().y / 2)
	{
		this->ButtonShape.setFillColor(sf::Color(161, 161, 161));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			while (ReleaseMouseButton());
			return true;
		}

		return false;
	}

	this->ButtonShape.setFillColor(sf::Color(211, 211, 211));

	return false;
}

