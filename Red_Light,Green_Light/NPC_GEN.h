#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "NPC.h"
#include "TimeText.h"

using namespace std;
using namespace sf;

class NPC_GEN
{
	vector<NPC> npcs;
	int ps = 0;
public:
	NPC_GEN();
	void update(IT&, TimeText&);
	void draw(RenderWindow&);
	void NPC_stop();
	void NPC_wrongmove(int);
	void NPC_move();
};