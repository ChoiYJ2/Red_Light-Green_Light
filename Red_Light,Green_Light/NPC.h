#pragma once
#include <SFML/Graphics.hpp>
#include "TimeText.h"
#include "IT.h"

using namespace sf;

class NPC
{
	Texture t_npc, t_npc_death;
	Sprite s_npc;
	float x = 0, y = 0, cur_x = 0;
	double npc_x[15] = { 24.0, 20.0, 22.5, 15.0, 14.1, 16.8, 17.5, 7.8, 9.8, 12.5, 11.0, 13.3, 6.5, 23.5, 24.5 };
	double npc_y[15] = { 110.0, 112.5, 90.7, 100.0, 119.8, 121.6, 117.7, 108.8, 98.0, 114.4, 113.2, 115.8, 95.5, 120.0, 126.6 };
	double speed[15] = { 0.8, 0.85, 0.9, 0.95, 1.0, 1.05, 1.1, 1.15, 1.2, 1.25, 1.3, 1.35, 1.4, 1.45, 1.5 };
	float nspeed = 0;
	bool NPC_end = false;
public:
	NPC(int);
	void update(IT&, TimeText&);
	void draw(RenderWindow&);
	bool NPC_stop = false;
};