#include <SFML/Graphics.hpp>
#include "Person.h"
using namespace std;
using namespace sf;

Person::Person()
{
	t_player.loadFromFile("images/player_white.jpg");
	t_player_death.loadFromFile("images/player_death.jpg");
	s_player.setTexture(t_player);
	s_player.setPosition(25.0f, 350.0f - 65.0f);
	hitted = false;
}

void Person::draw(RenderWindow& _window)
{
	_window.draw(s_player);
}

void Person::update(Bullet& bullet)
{
	if (bullet.checkHit(personArea()) == true)
	{
		s_player.setTexture(t_player_death);
	}
	else
	{
		s_player.setTexture(t_player);
	}
}

void Person::moveLeft()
{
	if (s_player.getPosition().x <= 5.0f)
	{
		return;
	}
	s_player.move(-10.0f, 0.0f);
}

void Person::moveRight()
{
	if (s_player.getPosition().x >= 1500.0f - 25.0f)
	{
		return;
	}
	s_player.move(10.0f, 0.0f);
}

FloatRect Person::personArea()
{
	return s_player.getGlobalBounds();
}