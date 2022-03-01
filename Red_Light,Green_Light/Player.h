#pragma once
#include <SFML/Graphics.hpp>
#include "IT.h"
#include "TimeText.h"

using namespace sf;

class Player
{
	Texture t_player, t_player_death;
	Sprite s_player;
	bool player_end = false;
	bool player_win = false;
public:
	Player();
	bool is_end();
	bool is_win();
	void moveLeft();
	void moveRight();
	void update(IT&, TimeText&);
	void draw(RenderWindow&);
};