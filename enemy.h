#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Bomb
{
public:
	Sprite sprite;
	Texture texture;
	double x, y;
	float speed = 1;

	Bomb()
	{
		texture.loadFromFile("img/fire2.png");
		sprite.setTexture(texture);
		x = -1; y = -1;
		sprite.setPosition(x, y);
		sprite.setScale(0.25, 0.25);
	}

	void move()
	{
		float delta_x = 0, delta_y = 0;
		delta_y += 1;
		delta_y *= speed;
		sprite.move(delta_x, delta_y);
	}

	~Bomb()
	{

	}

};

class Enemy
{
public:
	Texture tex;
	Sprite sprite;
	double x, y;
	Sprite lightning;
	Texture light_Tex;
	Sprite dragonFire;
	Sprite dragonFire2;
	Sprite dragonFire3;
	Texture dragFire_tex1;
	Texture dragFire_tex2;
	Texture dragFire_tex3;
	float speed = 0.3;


	Enemy(std::string png_path)
	{

		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 0; y = 0;
		sprite.setPosition(x, y);
		sprite.setScale(0.75, 0.75);
	}

	void setEnemy(std::string png_path, double a, double b)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = a; y = b;
		sprite.setPosition(x, y);
		sprite.setScale(0.75, 0.75);
	}

	virtual void BossMove()
	{
		float delta_x = 0;
		delta_x += 0.1;
		if (sprite.getPosition().x > 780)
			sprite.setPosition(0, 0);
		sprite.move(delta_x, 0);
	}

	virtual ~Enemy()
	{

	}

};

class Invaders : public Enemy
{
public:
	Texture tex;
	Sprite sprite;
	double x, y;
	float speed = 0.25;
	Bomb bomb;

	Invaders(std::string png_path) : Enemy(png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = -1; y = 781;
		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);
	}

	void setInvaders(std::string png_path, double a, double b)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = a; y = b;
		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);
	}

	void move()
	{
		float delta_x = 0, delta_y = 0;
		if (sprite.getPosition().x == 0)
		{
			delta_x += 1;
			delta_x *= speed;
		}
		else if (sprite.getPosition().y == 780)
		{
			delta_x += 1;
			delta_x *= speed;
		}
		sprite.move(delta_x, delta_y);
	}

	~Invaders()
	{

	}

};

class AlphaInvaders : public Invaders
{
public:


	AlphaInvaders() :Invaders("img/enemy_1.png")
	{
		tex.loadFromFile("img/enemy_1.png");
		sprite.setTexture(tex);
		x = -120331; y = -102231;
		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);
		bomb.sprite.setPosition(-12121, -1223);
	}

	~AlphaInvaders()
	{

	}

};
//3 11 12 13 18 19 20 21

class BetaInvaders : public Invaders
{
public:


	BetaInvaders() :Invaders("img/enemy_2.png")
	{
		tex.loadFromFile("img/enemy_2.png");
		sprite.setTexture(tex);
		x = -102231; y = -120031;
		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);
		bomb.sprite.setPosition(-12121, -1223);
	}

	~BetaInvaders()
	{

	}

};

class GammaInvaders : public Invaders
{
public:


	GammaInvaders() :Invaders("img/enemy_3.png")
	{
		tex.loadFromFile("img/enemy_3.png");
		sprite.setTexture(tex);
		x = -102123; y = -100212;
		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);
		bomb.sprite.setPosition(-12121, -1223);
	}

	~GammaInvaders()
	{

	}

};



class Monster : public Enemy
{
public:

	Monster(std::string png_path) : Enemy(png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		light_Tex.loadFromFile("img/lightning/lightning13.png");
		lightning.setTexture(light_Tex);
		lightning.setScale(2, 3.5);
		lightning.setPosition(-40000, 78111);
		x = 0; y = 0;
		sprite.setPosition(x, y);
		sprite.setScale(0.75, 0.5);
	}

	void BossMove()
	{
		float delta_x = 0;
		delta_x += 1;
		if ((sprite.getPosition().x >= 700))
		{
			sprite.setPosition(0, 0);
			lightning.setPosition(200, 200);
		}
		delta_x *= speed;
		sprite.move(delta_x, 0);
		lightning.move(delta_x, 0);
	}

	~Monster()
	{

	}

	/*
	for monster lightning
	scale is 0.75,0.75
	position is 400,200 or 200,200
	*/

};

class Dragon : public Enemy
{
public:

	Dragon(std::string png_path) : Enemy(png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 0; y = 0;
		speed = 0.5;
		sprite.setPosition(x, y);
		sprite.setScale(1.5, 1.5);
		dragFire_tex1.loadFromFile("img/dragon/5.png");
		dragFire_tex2.loadFromFile("img/dragon/6.png");
		dragFire_tex3.loadFromFile("img/dragon/7.png");
		dragonFire.setTexture(dragFire_tex1);
		dragonFire.setScale(0.25, 0.65);
		dragonFire.setPosition(-40000, 78111);

		dragonFire2.setTexture(dragFire_tex2);
		dragonFire2.setScale(0.25, 0.75);
		dragonFire2.setPosition(-40000, 78111);

		dragonFire3.setTexture(dragFire_tex3);
		dragonFire3.setScale(0.25, 0.75);
		dragonFire3.setPosition(-40000, 78111);
	}
	/*
	for texture 1
	scale is 0.25,0.65
	position is 350,320

	for texture 2
	scale is 0.25,0.75
	position is 250,320

	for texture 3
	scale is 0.25,0.75

	*/

	void BossMove()
	{
		float delta_x = 0;
		delta_x += 1;
		if ((sprite.getPosition().x >= 700))
		{
			sprite.setPosition(0, 0);
			dragonFire.setPosition(150, 320);
			dragonFire2.setPosition(50, 320);
			dragonFire3.setPosition(180, 320);

		}
		delta_x *= speed;
		sprite.move(delta_x, 0);
		dragonFire.move(delta_x, 0);
		dragonFire2.move(delta_x, 0);
		dragonFire3.move(delta_x, 0);
	}

	~Dragon()
	{

	}


};



