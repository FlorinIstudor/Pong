#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Entity.h"
#include <iostream>

#pragma once

bool isColliding(sf::RectangleShape FirstShape, sf::RectangleShape SecondShape);

void ChangeScoreText(int score1, int score2, sf::Text* text);

bool ReleaseMouseButton();

int GetSign(float n);