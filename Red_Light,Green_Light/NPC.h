#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class NPC
{
public:
	NPC();
	void draw(RenderWindow&); //������ â�� NPC�׸� �� ���
	FloatRect NPCarea(); //NPC�� �ѿ� ������ �״� ���
};