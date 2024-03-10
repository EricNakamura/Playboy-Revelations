#pragma once
#include <SFML/Graphics.hpp>

namespace plr {
	class Camera {
	private:
		float zoomLevel = 5.0f*1000;
	public:
		sf::View getView(sf::Vector2u windowSize);
		Camera(float zoomLevel);
		Camera();
	};
}