#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Entity
{
private:
	sf::Texture tx;

public:
	float MovementSpeed;
	
	sf::RectangleShape Shape;

	Entity(float len, float wid, float msp, const std::string TexturePath);

	~Entity();

//functions

	void Draw(sf::RenderWindow* window);

	void Move(float dt, float xdir, float ydir);
};

#endif