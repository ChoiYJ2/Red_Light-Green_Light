#include "TimeText.h"

TimeText::TimeText()
{
	font.loadFromFile("MapoDacapo.ttf");
	start = clock();
	end = 50 * CLOCKS_PER_SEC;
}

void TimeText::showTimeLimit(RenderWindow& _window)
{
	start = clock();
	if ((end - start) >= 10000)
	{
		text.setString("TimeLimit 00 : " + to_string((end - start) / 1000));
	}
	else
	{
		text.setString("TimeLimit 00 : 0" + to_string((end - start) / 1000));
	}
	if ((end - start) / 1000 == 0)
	{
		timeover = true;
	}
	text.setFont(font);
	text.setFillColor(Color::Red);
	text.setCharacterSize(30);
	text.setPosition(625.0f, 0.0f);
	text.setStyle(Text::Bold);
	_window.draw(text);
}