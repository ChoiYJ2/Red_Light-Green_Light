#include <SFML/Graphics.hpp>
#include "NPC.h"
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

NPC::NPC()
{
	t_npc.loadFromFile("images/NPC.png");
	t_npc_death.loadFromFile("images/NPC_death.png");
	s_npc.setTexture(t_npc);
	s_npc.setPosition(20.0f, 350.0f - 110.0f);
	srand((unsigned int)time(NULL));
	speed = rand() % 3 + 2; //NPC���� �ӵ� �����ϰ� (2 ~ 5)
}

void NPC::update()
{
	Vector2f pos = s_npc.getPosition();
	if (end == true)
	{
		return;
	}
	if (pos.x >= 1315.0f) // ��¼� �Ѿ�� �������� ����
	{
		end = true;
	}
	s_npc.move(speed, 0.0f);
}

void NPC::draw(RenderWindow& _window)
{
	_window.draw(s_npc);
}