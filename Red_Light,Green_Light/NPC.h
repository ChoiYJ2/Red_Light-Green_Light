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
	void draw(RenderWindow&); //윈도우 창에 NPC그릴 때 사용
	void update();
	FloatRect NPCarea(); //NPC가 총에 맞으면 죽는 모션
};