#include "Player.h"
#include "IT.h"
#include "Sound.h"

Player::Player()
{
	t_player.loadFromFile("images/player.png");
	t_player_death.loadFromFile("images/player_death.png");
	s_player.setTexture(t_player);
	s_player.setPosition(25.0f, 350.0f - 125.0f);
}

bool Player::is_end()
{
	return player_end;
}

bool Player::is_win()
{
	return player_win;
}

void Player::moveLeft()
{
	if (s_player.getPosition().x <= 5.0f || player_end == true)
	{
		return;
	}
	s_player.move(-5.0f, 0.0f);
}

void Player::moveRight()
{
	if (s_player.getPosition().x >= 1500.0f - 40.0f || player_end == true)
	{
		return;
	}
	s_player.move(2.8f, 0.0f);
}

void Player::update(IT& it, TimeText& timetext)
{
	float x = s_player.getPosition().x;
	if (x >= 1345.0f)
	{
		player_win = true;
		return;
	}
	if (it.someoneMove(x) == true || timetext.timeover == true)
	{
		player_end = true;
		PlaySound(TEXT("shot.wav"), 0, SND_FILENAME | SND_ASYNC);
		s_player.setTextureRect(IntRect(0, 0, 65, 45));
		s_player.setTexture(t_player_death);
		s_player.setPosition(x, 350.0f - 85.0f);
	}
	else
	{
		s_player.setTexture(t_player);
	}
}

void Player::draw(RenderWindow& _window)
{
	_window.draw(s_player);
}