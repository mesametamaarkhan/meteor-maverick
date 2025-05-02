#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
using namespace sf;
class AddOn
{
public:
	Texture tex;
	Sprite sprite;
	float speed = 0.5;
	double x, y;


	AddOn(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		sprite.setScale(0.25, 0.25);
		x = rand() % 720; y = 0;
		sprite.setPosition(x, y);
	}

	void move()
	{

		double delta_x = 0, delta_y = 0;
		delta_y += 1;
		delta_y *= speed;
		sprite.move(delta_x, delta_y);

	}

	~AddOn()
	{

	}

};

class PowerUp : public AddOn
{
public:

	PowerUp() : AddOn("img/powerup.png")
	{
		tex.loadFromFile("img/powerup.png");
		sprite.setTexture(tex);
		sprite.setScale(0.25, 0.25);
		sprite.setPosition(-100, -100);
	}

	~PowerUp()
	{

	}

};

class Fire : public AddOn
{
public:
	Fire() : AddOn("img/fire1.png")
	{
		tex.loadFromFile("img/fire1.png");
		sprite.setTexture(tex);
		sprite.setScale(0.25, 0.25);
		sprite.setPosition(-123, -123);
	}

	~Fire()
	{

	}

};

class Lives : public AddOn
{
public:
	Lives() : AddOn("img/hospital1.png")
	{
		tex.loadFromFile("img/hospital1.png");
		sprite.setTexture(tex);
		sprite.setScale(0.25, 0.25);
		sprite.setPosition(-126, -126);
	}

	~Lives()
	{

	}

};

class Danger : public AddOn
{
public:
	Danger() : AddOn("img/meteor_danger.png")
	{
		tex.loadFromFile("img/meteor_danger.png");
		sprite.setTexture(tex);
		sprite.setScale(0.75, 0.75);
		sprite.setPosition(-226, -226);
	}

	~Danger()
	{

	}

};
