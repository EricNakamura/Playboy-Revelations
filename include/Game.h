#pragma once
#include <SFML/Graphics.hpp>


void Initilize(sf::RenderWindow& target);

void Update(float deltaTime);

void LateUpdate(float deltaTime);

void Render(sf::RenderWindow& target);