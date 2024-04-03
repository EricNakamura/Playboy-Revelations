// PlayboyRevelations.cpp: define o ponto de entrada para o aplicativo.
//

#include <SFML/Graphics.hpp>
#include <GameMap.h>
#include <Entity.h>
#include <Camera.h>
#include <iostream>
#include <Game.h>

int main()
{

	bool started = false;
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Playboy Revelation", sf::Style::Default);

	window.setVerticalSyncEnabled(true);


	static plr::Camera camera(300.f);


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
		window.setView(camera.getView(window.getSize()));
		window.clear();
		if (!started)
		{
			Initilize(window);
			started = true;
		}
		Update(deltaTime);
		Render(window);
		window.display();
		LateUpdate(deltaTime);
	}

	return 0;
}
