// PlayboyRevelations.cpp: define o ponto de entrada para o aplicativo.
//

#include <SFML/Graphics.hpp>
#include <Player.h>
#include <Camera.h>
#include <iostream>
#include <Game.h>

int main()
{
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(800,600), "Playboy Revelation", sf::Style::Default);

	window.setVerticalSyncEnabled(true);

	Initilize();

	plr::Camera camera(50.f);

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		sf::Event event{};


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		Update(deltaTime);

		window.setView(camera.getView(window.getSize()));
		window.clear();
		Update(deltaTime);
		Render(window);
		LateUpdate(deltaTime);
		window.display();
	}

	return 0;
}
