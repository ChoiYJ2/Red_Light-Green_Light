#include "NPC.h"
#include "Sound.h"

NPC::NPC(int _ps)
{
	t_npc.loadFromFile("images/NPC.png");
	t_npc_death.loadFromFile("images/NPC_death.png");
	s_npc.setTexture(t_npc);
	x = (float)npc_x[_ps];
	y = (float)npc_y[_ps];
	nspeed = (float)speed[_ps];
	s_npc.setPosition(x, 350.0f - y);
}

void NPC::update(IT& it, TimeText& timetext)
{
	if (NPC_end == true || NPC_stop == true)
	{
		return;
	}
	cur_x = s_npc.getPosition().x;
	if (cur_x >= 1350.0f)
	{
		NPC_end = true;
	}
	if (timetext.timeover == true || it.someoneMove(cur_x) == true)
	{
		NPC_end = true;
		PlaySound(TEXT("shot.wav"), 0, SND_FILENAME | SND_ASYNC);
		s_npc.setTextureRect(IntRect(0, 0, 65, 45));
		s_npc.setTexture(t_npc_death);
		s_npc.setPosition(cur_x, 350.0f - (y - 45.0f));
	}
	else
	{
		s_npc.setTexture(t_npc);
	}
	s_npc.move((float)nspeed, 0.0f);
}

void NPC::draw(RenderWindow& _window)
{
	_window.draw(s_npc);
}