#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
using namespace std;
using namespace sf;

class Person
{
	Texture t_player, t_player_death;
	Sprite s_player;
	bool hitted;
public:
	Person();
	void draw(RenderWindow&); //������ â�� ��� �ؽ��� �׸� �Լ�
	void update(Bullet&); //��� ������ �� ������Ʈ�� �Լ� -> ���� ��� �������� �� ��
	void moveLeft(); //�������� ������ �Լ�
	void moveRight(); //���������� ������ �Լ�
	FloatRect personArea(); //�ѿ� �¾��� ��� �״� ����� �� ���
};