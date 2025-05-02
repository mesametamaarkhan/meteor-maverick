#include <SFML/Graphics.hpp>
#include <string.h>
#include <time.h>
#include <iostream>
#include "bullet.h"
using namespace std;
using namespace sf;

class Player {
public:
	Texture tex;
	Sprite sprite;
	float speed = 0.75;
	int x, y;
	int temp_x, temp_y;
	bullet b, b1, b2, b3;
	bullet FIRE;
	bullet b4, b5, b6, b7, b8, b9;
	int lives = 1;
	int HP = 100;
	PowerUp P1;
	Fire F1;
	Lives L1;
	Danger D2;

	Player(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 340; y = 700;
		sprite.setPosition(x, y);
		sprite.setScale(0.75, 0.75);
		FIRE.setBullet("img/laserRed08.png");
		b4.setBullet("img/laserRed09.png");
		b5.setBullet("img/laserRed09.png");
		b6.setBullet("img/laserRed09.png");
		b7.setBullet("img/laserRed09.png");
		b8.setBullet("img/laserRed09.png");
		b9.setBullet("img/laserRed09.png");
		b4.sp.setScale(0.25, 0.25);
		b5.sp.setScale(0.25, 0.25);
		b6.sp.setScale(0.25, 0.25);
		b7.sp.setScale(0.25, 0.25);
		b8.sp.setScale(0.25, 0.25);
		b9.sp.setScale(0.25, 0.25);
	}

	void fire(bool x, bool y)
	{
		if (x && y)
		{
			b1.sp.setPosition(-1000, -1000);
			b2.sp.setPosition(-1000, -1000);
			b3.sp.setPosition(-1000, -1000);
			FIRE.move(sprite.getPosition().x, sprite.getPosition().y);
			b.move(sprite.getPosition().x, sprite.getPosition().y);
			b4.movePower(sprite.getPosition().x + 10.0f, sprite.getPosition().y + 10.0f, true);
			b5.movePower(sprite.getPosition().x + 20.0f, sprite.getPosition().y + 20.0f, true);
			b6.movePower(sprite.getPosition().x + 30.0f, sprite.getPosition().y + 30.0f, true);
			b7.movePower(sprite.getPosition().x + 50.0f, sprite.getPosition().y + 10.0f, false);
			b8.movePower(sprite.getPosition().x + 60.0f, sprite.getPosition().y + 20.0f, false);
			b9.movePower(sprite.getPosition().x + 70.0f, sprite.getPosition().y + 30.0f, false);
		}
		else if (x)
		{
			b.sp.setPosition(-1000, -1000);
			b1.sp.setPosition(-1000, -1000);
			b2.sp.setPosition(-1000, -1000);
			b3.sp.setPosition(-1000, -1000);
			FIRE.move(sprite.getPosition().x, sprite.getPosition().y);


		}
		else if (y)
		{
			b1.sp.setPosition(-1000, -1000);
			b2.sp.setPosition(-1000, -1000);
			b3.sp.setPosition(-1000, -1000);
			b.move(sprite.getPosition().x, sprite.getPosition().y);
			b4.movePower(sprite.getPosition().x + 10.0f, sprite.getPosition().y + 10.0f, true);
			b5.movePower(sprite.getPosition().x + 20.0f, sprite.getPosition().y + 20.0f, true);
			b6.movePower(sprite.getPosition().x + 30.0f, sprite.getPosition().y + 30.0f, true);
			b7.movePower(sprite.getPosition().x + 50.0f, sprite.getPosition().y + 10.0f, false);
			b8.movePower(sprite.getPosition().x + 60.0f, sprite.getPosition().y + 20.0f, false);
			b9.movePower(sprite.getPosition().x + 70.0f, sprite.getPosition().y + 30.0f, false);
		}
		else
		{
			b.move(sprite.getPosition().x, sprite.getPosition().y);
			b1.move(sprite.getPosition().x, sprite.getPosition().y);
			b2.move(sprite.getPosition().x, sprite.getPosition().y);
			b3.move(sprite.getPosition().x, sprite.getPosition().y);
		}

	}

	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;
		if (s == "l")
			delta_x -= 1;
		//move the player left

		else if (s == "r")
			delta_x += 1;
		//move the player right
		else if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y += 1;

		delta_x *= speed;
		delta_y *= speed;

		if (sprite.getPosition().y < 0)
		{
			sprite.setPosition(sprite.getPosition().x, 780);
		}
		else if (sprite.getPosition().x < 0)
		{
			sprite.setPosition(780, sprite.getPosition().y);
		}
		else if (sprite.getPosition().y > 780)
		{
			sprite.setPosition(sprite.getPosition().x, 0);
		}
		else if (sprite.getPosition().x > 780)
		{
			sprite.setPosition(0, sprite.getPosition().y);
		}

		sprite.move(delta_x, delta_y);

	}

	~Player()
	{

	}

};
