#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Person
{
	Texture t_person;
	Sprite s_person;
public:
	Person();
	void draw(RenderWindow&); //������ â�� ��� �ؽ��� �׸� �Լ�
	void update(); //��� ������ �� ������Ʈ�� �Լ� -> ���� ��� �������� �� ��
	void moveLeft(); //�������� ������ �Լ�
	void moveRight(); //���������� ������ �Լ�
	FloatRect personArea(); //�ѿ� �¾��� ��� �״� ����� �� ���
};