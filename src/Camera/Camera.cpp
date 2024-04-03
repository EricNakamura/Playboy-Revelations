#include <Camera.h>
#include <iostream>

plr::Camera::Camera(float zoomLevel) : zoomLevel(zoomLevel) {}
plr::Camera::Camera() {}

sf::View plr::Camera::getView(sf::Vector2u windowSize) {
	float aspect = (float)windowSize.x / (float)windowSize.y;
	sf::Vector2f size;
	if (aspect < 1.0f)
		size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
	else
		size = sf::Vector2f(zoomLevel * aspect, zoomLevel);

	sf::View view(sf::FloatRect(position.x, position.y, size.x, size.y));
	return view;
}

void plr::Camera::setPosition(sf::Vector2<float> position)
{
	this->position = position;
}