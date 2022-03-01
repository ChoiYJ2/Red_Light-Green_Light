#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class TimeText
{
	Text text;
	Font font;
	clock_t start, end;
public:
	TimeText();
	void showTimeLimit(RenderWindow&);
	bool timeover = false;
};