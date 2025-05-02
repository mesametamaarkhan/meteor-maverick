
#include "game.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Menu {
public:
    Sprite background;
    Texture bg_texture;
    Texture HTP_BG;
    Sprite HTP;
    Sprite HS;
    Texture HS_BG;
    bool help = false;
    bool highScore = false;
    string fileName = "High Scores";
    string* name;
    int* score;
    Text line1;
    Text line2;
    Text line3;
    Font font;
    fstream myFile1;
    string username;
    //add menu attributes here
    Menu()
    {
        bg_texture.loadFromFile("img/menu_bg2.jpg");
        background.setTexture(bg_texture);
        background.setScale(1, 1);
        font.loadFromFile("fonts/Orbitron-Black.ttf");
        line1.setFont(font);
        line2.setFont(font);
        line3.setFont(font);

        line1.setCharacterSize(50);
        line2.setCharacterSize(50);
        line3.setCharacterSize(50);

        line1.setFillColor(Color::Yellow);
        line2.setFillColor(Color::Yellow);
        line3.setFillColor(Color::Yellow);

        line1.setPosition(200, 350);
        line2.setPosition(200, 400);
        line3.setPosition(200, 450);
        myFile1.open(fileName, ios::in);

        name = new string[3];
        score = new int[3];

        int i = 0;
        while (!myFile1.eof())
        {
            myFile1 >> name[i] >> score[i];
            name[i] += " ";
            name[i] += to_string(score[i]);
            i++;
            if (i > 2)
                break;
        }
        myFile1.close();
        //constructors body
    }

    void display_menu()

    {
        Game g;
        RenderWindow window(VideoMode(780, 780), title);
        window.draw(background);
        window.display();
        cout << "Enter your name: ";
        cin >> username;
        Event E;
        while (window.isOpen())
        {
            while (window.pollEvent(E))
            {
                if (E.type == Event::Closed)
                    window.close();
            }


            if (Keyboard::isKeyPressed(Keyboard::G))
            {
                Game g;
                g.start_game(window, username);

            }
            if (Keyboard::isKeyPressed(Keyboard::H))
            {
                help = howToPlay();
            }
            if (Keyboard::isKeyPressed(Keyboard::E))
            {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::M) && help)
            {
                help = false;
            }

            //display menu screen here
            if (!help)
                window.clear(Color::White);
            // add functionality of all the menu options here
            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                highScore = HighScores();
            }
            if (Keyboard::isKeyPressed(Keyboard::M) && highScore)
            {
                highScore = false;
            }
            window.draw(background);
            if (help)
            {
                window.draw(HTP);
            }

            if (highScore)
            {
                window.draw(HS);
                window.draw(line1);
                window.draw(line2);
                window.draw(line3);
            }

            //if Start game option is chosen 
            window.display();
        }
    }

    bool howToPlay()
    {

        HTP_BG.loadFromFile("img/howtoplay_bg.jpg");
        HTP.setTexture(HTP_BG);
        HTP.setScale(1, 1);
        help = true;
        return help;
    }

    bool HighScores()
    {

        line1.setString(name[0]);
        line2.setString(name[1]);
        line3.setString(name[2]);
        HS_BG.loadFromFile("img/highscores_bg.jpg");
        HS.setTexture(HS_BG);
        HS.setScale(1, 1);
        highScore = true;
        return highScore;
    }


};
