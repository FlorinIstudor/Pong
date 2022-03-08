#include "Entity.h"

Entity::Entity(float len, float wid, float msp, const std::string TexturePath)
{
	this->MovementSpeed = msp;
	this->Shape = sf::RectangleShape(sf::Vector2f(len,wid));
	this->Shape.setOrigin(sf::Vector2f(len/2, wid/2));

	tx.loadFromFile(TexturePath);
	this->Shape.setTexture(&tx);
}

Entity::~Entity()
{
}

void Entity::Draw(sf::RenderWindow* window)
{
	window->draw(this->Shape);
}

void Entity::Move(float dt, float xdir, float ydir)
{
	this->Shape.move(sf::Vector2f(dt*xdir*this->MovementSpeed, dt * ydir * this->MovementSpeed));
}
