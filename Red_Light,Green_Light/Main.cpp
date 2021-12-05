#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#include "IT.h"
#include "Person.h"
#include "NPC.h"
using namespace std;
using namespace sf;
int main()
{
	PlaySound(TEXT("무궁화꽃이피었습니다.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //bgm재생
	RenderWindow window(VideoMode(1500, 350), "Red Light, Green Light"); //윈도우 창 열기
	window.setFramerateLimit(60);

	Font font;
	font.loadFromFile("mb.ttf");

	Text text;
	Person person;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Left) == true)
				{
					person.moveLeft();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Right) == true)
				{
					person.moveRight();
				}
			default:
				break;
			}
		}
		text.setString("time: 0123456789");
		text.setFillColor(Color::Red);
		text.setCharacterSize(25);
		text.setPosition(350.0f, 0.0f);
		window.draw(text);
		window.display();
	}
	return 0;
}