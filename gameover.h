#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;

class GameOver
{
public:
	Sprite background;
	Texture bg_texture;
	string fileName = "High Scores";
	fstream myFile;
	string name1;
	string* name;
	int* score2;
	Text username;
	Text score1;
	Font font;
	int arraySize;

	GameOver()
	{
		bg_texture.loadFromFile("img/gameover_bg2.jpg");
		background.setTexture(bg_texture);
		background.setScale(1, 1);
		myFile.open(fileName, ios::app);
		myFile.close();
		username.setPosition(300, 450);
		font.loadFromFile("fonts/Orbitron-Black.ttf");
		username.setFont(font);
		username.setCharacterSize(50);
		username.setFillColor(Color::Yellow);
		score1.setFont(font);
		score1.setCharacterSize(50);
		score1.setFillColor(Color::Yellow);
		score1.setPosition(300, 600);
	}

	void gameover(RenderWindow& window, bool win, int score, string a)
	{
		window.clear();
		window.draw(background);
		window.display();
		Event E;
		name1 = a;
		score1.setString(to_string(score));
		username.setString(name1);


		myFile.open(fileName, ios::app);
		myFile << name1 << "\t" << score << endl;
		myFile.close();
		arraySize = countLines();

		int i = 0;
		name = new string[arraySize];
		score2 = new int[arraySize];
		myFile.open(fileName, ios::in);
		while (!myFile.eof())
		{
			if (i > arraySize - 1)
				break;
			myFile >> name[i] >> score2[i];
			i++;
		}
		myFile.close();

		int temp;
		string temp1;
		for (int i = 0; i < arraySize; i++)
		{
			for (int j = 0; j < arraySize; j++)
			{
				if (score2[i] > score2[j])
				{
					temp = score2[i];
					temp1 = name[i];

					score2[i] = score2[j];
					name[i] = name[j];

					score2[j] = temp;
					name[j] = temp1;
				}
			}
		}

		myFile.open(fileName, ios::trunc | ios::out);
		for (int i = 0; i < arraySize; i++)
			myFile << name[i] << "\t" << score2[i] << endl;
		myFile.close();

		while (window.isOpen())
		{
			while (window.pollEvent(E))
			{
				if (E.type == Event::Closed)
					window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				//delete[] name;
					//delete[] score2;
				window.close();
			}
			window.draw(username);
			window.draw(score1);
			window.display();
		}

	}


	int countLines()
	{
		myFile.open(fileName, ios::in);
		string line;
		int count = 0;
		while (!myFile.eof())
		{
			getline(myFile, line);
			count++;
		}
		myFile.close();
		return count - 1;
	}
};
