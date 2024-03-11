#pragma once
#include <SFML/Graphics.hpp>

namespace plr {
	class Camera {
	private:
		float zoomLevel = 5.0f;
		sf::Vector2<float> position = sf::Vector2f(0,0);
	public:
		sf::View getView(sf::Vector2u windowSize);
		Camera(float zoomLevel);
		Camera();

		void setPosition(sf::Vector2<float> position);
	};
}