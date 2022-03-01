#include "NPC_GEN.h"

NPC_GEN::NPC_GEN()
{
	for (int i = 0; i < 15; i++)
	{
		ps = i % 15;
		NPC npc(ps);
		npcs.push_back(npc);
	}
}

void NPC_GEN::NPC_stop()
{
	for (auto& n : npcs)
	{
		n.NPC_stop = true;
	}
}

void NPC_GEN::NPC_wrongmove(int num)
{
	npcs[num].NPC_stop = false;
}

void NPC_GEN::NPC_move()
{
	for (auto& n : npcs)
	{
		n.NPC_stop = false;
	}
}

void NPC_GEN::update(IT& it, TimeText& timetext)
{
	for (auto& n : npcs)
	{
		n.update(it, timetext);
	}
}

void NPC_GEN::draw(RenderWindow& _window)
{
	for (auto& n : npcs)
	{
		n.draw(_window);
	}
}