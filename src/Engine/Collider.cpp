#include <Collider.h>

plr::Collider::Collider()
{
	AddRect(sf::FloatRect(0, 0, 0, 0));
}

bool plr::Collider::CheckCollision(sf::FloatRect other)
{
	for (auto rect : rects)
	{
		if (rect.intersects(other))
		{
			return true;
		}
	};
}

void plr::Collider::AddRect(sf::FloatRect rect)
{
	rects.push_back(rect);
}

void plr::Collider::AddRect(std::vector<sf::FloatRect> rect)
{
	rects.insert(rects.end(), rect.begin(), rect.end());
}