#pragma once
#include <SFML/Graphics.hpp>
#include <Camera.h>

namespace plr {

	class Scene : sf::View {
	private:
		plr::Camera camera;
		sf::Clock clock;
		float deltaTime = 0;
	public:
		Scene(sf::RenderWindow target);
	};
};