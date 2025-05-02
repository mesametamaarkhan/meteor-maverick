#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
class bullet
{
public:
	Texture tex;	
	Sprite sp;
	float speed = 1;
	int x, y;
	bullet()
	{
		tex.loadFromFile("img/laserRed09.png");
		sp.setTexture(tex);
		x = 400; y = 740;
		sp.setPosition(x, y);
		sp.setScale(0.25, 0.25);
	}

	void setBullet(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sp.setTexture(tex);
		x = -1000; y = 0;
		sp.setPosition(x, y);
		sp.setScale(0.75, 0.75);

	}

	void move(int tempX, int tempY)
	{

		float delta_x = 0, delta_y = 0;
		delta_y -= 1;
		delta_y *= speed;
		if (sp.getPosition().y < 0)
			sp.setPosition(tempX + 80.0f, tempY + 40.0f);
		else if (sp.getPosition().y > 780)
			sp.setPosition(tempX + 80.0f, tempY + 40.0f);
		else if (sp.getPosition().x > 780)
			sp.setPosition(tempX + 80.0f, tempY + 40.0f);
		else if (sp.getPosition().x < 0)
			sp.setPosition(tempX + 80.0f, tempY + 40.0f);
		sp.move(delta_x, delta_y);
	}

	void movePower(int tempX, int tempY, bool p)
	{


		float delta_x = 0, delta_y = 0;
		if (p)
			delta_x -= 1;
		else
			delta_x += 1;
		delta_y -= 1;
		delta_x *= speed;
		delta_y *= speed;
		if (sp.getPosition().y < 0)
			sp.setPosition(tempX, tempY);
		else if (sp.getPosition().y > 780)
			sp.setPosition(tempX, tempY);
		else if (sp.getPosition().x > 780)
			sp.setPosition(tempX, tempY);
		else if (sp.getPosition().x < 0)
			sp.setPosition(tempX, tempY);
		sp.move(delta_x, delta_y);

	}

	~bullet()
	{

	}

};
