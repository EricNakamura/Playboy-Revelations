#include <Game.h>
#include <Entity.h>
#include <iostream>
#include <GameMap.h>

plr::Entity player("assets/player/player.png");
plr::Entity player2("assets/player/player.png");

plr::Map map("assets/map/map_template.png");

sf::RenderWindow window;

void Initilize(sf::RenderWindow& target)
{
	std::cout << "Player bounds: " << target.getView().getSize().x << " " << target.getView().getSize().y << std::endl;
	player.setSize(sf::Vector2f(30.f, 30.f));
	player.setPosition(sf::Vector2f(1, 1));
	player.setmoveSpeed(1.f);
	player.setJumpForce(10.f);
	player.setGravity(true);
	player2.setSize(sf::Vector2f(5.f, 5.f));
	player2.setPosition(sf::Vector2f(30, 30));
	player2.setmoveSpeed(0);
	player.setMaxBounds(target.getView().getSize());
}

void Update(float deltaTime)
{
	player.Update(deltaTime);
	//player2.Update(deltaTime);
	player.FixedUpdate();
	//player2.FixedUpdate();
	//player2.LateUpdate(deltaTime);

}

void LateUpdate(float deltaTime)
{
	player.LateUpdate(deltaTime);
}

void Render(sf::RenderWindow& target) {
	//player2.setMaxBounds(target.getView().getSize());
	map.Draw(target);
	player.Draw(target);
	//player2.Draw(target);
}

