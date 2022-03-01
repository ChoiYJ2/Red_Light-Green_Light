#include "IT.h"
#include "Sound.h"

using namespace std;
using namespace sf;

IT::IT()
{
	t_fIt.loadFromFile("images/IT_front.png");
	t_bIt.loadFromFile("images/IT_back.png");
	s_IT.setTexture(t_bIt);
	s_IT.setPosition(1370.0f, 350.0f - 245.0f);
	srand((unsigned int)time(NULL));
	delay = (float)(rand() % 4) + 2;
}

void IT::speak()
{
	PlaySound(TEXT("¹«±ÃÈ­0.wav"), 0, SND_FILENAME | SND_ASYNC);
}

void IT::speak_start()
{
	is_stop = false;
}

void IT::speak_end()
{
	is_stop = true;
}

void IT::draw(RenderWindow& _window)
{
	_window.draw(s_IT);
}

void IT::update()
{
	if (is_stop == true)
	{
		s_IT.setTexture(t_fIt);
	}
	else
	{
		s_IT.setTexture(t_bIt);
	}
}

bool IT::someoneMove(float posX)
{
	if (is_stop == true)
	{
		if (posX >= 150.0f)
		{
			if (lastPos == 0)
			{
				lastPos = posX;
			}
			else if (lastPos != posX)
			{
				return true;
			}
		}
	}
	else
	{
		lastPos = 0;
	}
	return false;
}