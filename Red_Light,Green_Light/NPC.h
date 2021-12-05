#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class NPC
{
public:
	NPC();
	void draw(RenderWindow&); //윈도우 창에 NPC그릴 때 사용
	FloatRect NPCarea(); //NPC가 총에 맞으면 죽는 모션
};