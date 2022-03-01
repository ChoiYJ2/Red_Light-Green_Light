#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class IT
{
	Texture t_fIt, t_bIt;
	Sprite s_IT;
	float lastPos = 0;
public:
	IT();
	void speak();
	void speak_start();
	void speak_end();
	void draw(RenderWindow&);
	void update();
	bool someoneMove(float);
	bool is_stop = false;
	float delay = 0;
};