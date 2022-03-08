#include "Utilities.h"

bool isColliding(sf::RectangleShape FirstShape, sf::RectangleShape SecondShape)
{
	float xdist = abs(FirstShape.getPosition().x - SecondShape.getPosition().x);
	float ydist = abs(FirstShape.getPosition().y - SecondShape.getPosition().y);
	
	if (xdist < (FirstShape.getSize().x + SecondShape.getSize().x) / 2 && ydist < (FirstShape.getSize().y + SecondShape.getSize().y) / 2)
		return true;

	return false;
}

void ChangeScoreText(int score1, int score2, sf::Text* text)
{
	std::string str = std::to_string(score1) + " : " + std::to_string(score2);
	text->setString(str);
	text->setPosition(sf::Vector2f(524.f - (std::to_string(score1).length()+2)*text->getCharacterSize(),50.f));
}

bool ReleaseMouseButton()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return true;

	return false;
}

int GetSign(float n)
{
	if (n > 0)
		return 1;
	if (n < 0)
		return -1;

	return 0;
}
