#include <SFML/Graphics.hpp>
#include "Person.h"
using namespace std;
using namespace sf;

void Person::moveLeft()
{
	if (s_person.getPosition().x <= 5.0f)
	{
		return;
	}
	s_person.move(-10.0f, 0.0f);
}

void Person::moveRight()
{
	if (s_person.getPosition().x >= 1500.0f - 25.0f)
	{
		return;
	}
	s_person.move(10.0f, 0.0f);
}