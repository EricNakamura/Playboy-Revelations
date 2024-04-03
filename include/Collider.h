#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace plr {
	class Collider {
	private:
		std::vector<sf::FloatRect> rects;
	public:
		Collider();
		bool CheckCollision(sf::FloatRect other);
		void AddRect(sf::FloatRect rect);
		void AddRect(std::vector<sf::FloatRect> rect);
	};
}