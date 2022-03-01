#include <SFML/Graphics.hpp>
#include "Player.h"
#include "IT.h"
#include "NPC.h"
#include "NPC_GEN.h"
#include "Sound.h"
#include "TimeText.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1500, 350), "Red Light, Green Light");
	window.setFramerateLimit(60);

	Texture t_bg;
	Sprite s_bg;
	t_bg.loadFromFile("images/backg.png");
	s_bg.setTexture(t_bg);

	Player player;
	IT it;
	NPC_GEN npc;
	TimeText timetext;

	clock_t start;
	it.speak();
	start = clock();
	while (window.isOpen())
	{
		srand((unsigned int)time(NULL));
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
					player.moveLeft();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Right) == true)
				{
					player.moveRight();
				}
			default:
				break;
			}
		}

		if ((clock() - start) / 1000 > 3.1)
		{
			npc.NPC_stop();
		}
		if ((clock() - start) / 1000 > 3.2)
		{
			it.speak_end();
		}
		if ((clock() - start) / 1000 > it.delay)
		{
			npc.NPC_wrongmove(rand() % 15);
		}
		if ((clock() - start) / 1000 > it.delay + 3.6)
		{
			npc.NPC_move();
		}
		if ((clock() - start) / 1000 > it.delay + 3.5)
		{
			it.speak_start();
			it.speak();
			start = clock();
		}
		window.draw(s_bg);
		timetext.showTimeLimit(window);
		it.update();
		player.update(it, timetext);
		npc.update(it, timetext);
		npc.draw(window);
		player.draw(window);
		it.draw(window);
		if (player.is_win() == true)
		{
			sleep(seconds(0.5));
			window.draw(s_bg);
			Text Gamewin;
			Font font;
			font.loadFromFile("MapoDacapo.ttf");
			Gamewin.setFont(font);
			Gamewin.setString("You Win!");
			Gamewin.setPosition(580.0f, 100.0f);
			Gamewin.setFillColor(Color::Black);
			Gamewin.setCharacterSize(100);
			Gamewin.setStyle(Text::Bold);
			window.draw(Gamewin);
			window.display();
			PlaySound(TEXT("win.wav"), 0, SND_FILENAME | SND_ASYNC);
			sleep(seconds(2));
			return 0;
		}
		if (timetext.timeover == true || player.is_end() == true)
		{
			Text Timeover;
			Font font;
			font.loadFromFile("MapoDacapo.ttf");
			Timeover.setFont(font);
			Timeover.setString("Game Over!");
			Timeover.setPosition(530.0f, 90.0f);
			Timeover.setFillColor(Color::Red);
			Timeover.setCharacterSize(100);
			Timeover.setStyle(Text::Bold);
			window.draw(Timeover);
			window.display();
			sleep(seconds(2));
			return 0;
		}
		window.display();
	}
}