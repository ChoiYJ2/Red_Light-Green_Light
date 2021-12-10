#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class NPC
{
	Texture t_npc, t_npc_death;
	Sprite s_npc;
	float speed;
public:
	bool start = false;
	bool end = false;
	NPC();
	void is_start();
	void is_end();
	void draw(RenderWindow&); //������ â�� NPC�׸� �� ���
	void update();
	FloatRect NPCarea(); //NPC�� �ѿ� ������ �״� ���
};