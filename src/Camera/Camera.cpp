#include <Camera.h>

plr::Camera::Camera(float zoomLevel) : zoomLevel(zoomLevel*1000) {}
plr::Camera::Camera() {}

sf::View plr::Camera::getView(sf::Vector2u windowSize) {
	float aspect = (float)windowSize.x / (float)windowSize.y;
	sf::Vector2f size;
	if (aspect < 1.0f)
		size = sf::Vector2f(this->zoomLevel, this->zoomLevel / aspect);
	else
		size = sf::Vector2f(this->zoomLevel * aspect, this->zoomLevel);

	return sf::View(sf::Vector2f(windowSize.x/2, windowSize.y/2), size);
}