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
	void draw(RenderWindow&); //윈도우 창에 사람 텍스쳐 그릴 함수
	void update(Bullet&); //사람 움직인 거 업데이트할 함수 -> 아직 어떻게 구현할지 잘 모름
	void moveLeft(); //왼쪽으로 움직일 함수
	void moveRight(); //오른쪽으로 움직일 함수
	FloatRect personArea(); //총에 맞았을 경우 죽는 모션할 때 사용
};