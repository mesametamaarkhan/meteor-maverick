#include <SFML/Graphics.hpp>
#include <time.h>
#include "gameover.h"
#include <iostream>
#include "add-ons.h"
//#include "enemy.h"
#include "additional.h"
using namespace std;
#include "player.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
    GameOver g1;
    Sprite background; //Game background sprite
    Texture bg_texture;
    Texture bg;
    Sprite gpause;
    Texture HTP_BG;
    Sprite HTP;
    Sprite Health;
    Texture health_t1;
    Texture health_t2;
    Texture health_t3;
    Texture health_t4;
    Texture health_t5;
    Player* p; //player 
    AlphaInvaders* e1;
    BetaInvaders* e2;
    GammaInvaders* e3;
    Enemy* M1 = new Monster("img/monster1.png");
    bool monster = false, monsterRun = false;
    Enemy* D1 = new Dragon("img/dragon.png");
    bool dragon = false, dragonRun = false;
    bool boss = false;
    bool powerup = false;
    bool fire = false;
    bool danger = false;
    bool pause = false;
    bool help = false;
    int alphaCount = 0;
    int betaCount = 0;
    int gammaCount = 0;
    bool alpha = false, beta = false, gamma = false;
    string username;
    bool alpha_bomb = false, beta_bomb = false, gamma_bomb = false;
    int score = 0;
    bool level_clear = false;
    int level = 1;
    Text lives;
    Text scoring;
    Text HP;
    Font font;

    // add other game attributes



    Game()
    {
        e1 = new AlphaInvaders[20];
        e2 = new BetaInvaders[20];
        e3 = new GammaInvaders[20];

        //setting Alpha Invaders
        alphaCount = setEnemies(1, 1, e1);
        betaCount = setEnemies(1, 2, e2);
        gammaCount = setEnemies(1, 3, e3);



        p = new Player("img/11.png");
        bg_texture.loadFromFile("img/gamebg2.jpg");
        background.setTexture(bg_texture);
        background.setScale(1, 1);
        font.loadFromFile("fonts/Orbitron-Black.ttf");
        lives.setCharacterSize(20);
        lives.setFont(font);
        lives.setPosition(720, 720);
        lives.setFillColor(Color::Yellow);
        scoring.setCharacterSize(20);
        scoring.setFont(font);
        scoring.setPosition(720, 743);
        scoring.setFillColor(Color::Yellow);
        HP.setCharacterSize(20);
        HP.setFont(font);
        HP.setPosition(720, 700);
        HP.setFillColor(Color::Yellow);
        health_t1.loadFromFile("img/full_HP.png");
        health_t2.loadFromFile("img/btw_71_to_90.png");
        health_t3.loadFromFile("img/btw_50_to_70.png");
        health_t4.loadFromFile("img/btw_30_to_50.png");
        health_t5.loadFromFile("img/below30_HP.png");
        Health.setScale(1, 1);
        Health.setPosition(670, 620);
    }
    void start_game(RenderWindow& window, string a)
    {
        username = a;
        srand(time(0));
        //this->window = window;
        Clock clock;
        float timer = 0;
        int count = 0, count1 = 0, count2 = 0;
        double powerup_timer = 0, fire_timer = 0, danger_timer = 0, lives_timer = 0;
        float alpha_bomb_timer = 0, beta_bomb_timer = 0, gamma_bomb_timer = 0;
        float powerupPickTimer = 0, firePickTimer = 0;
        float dragon_timer = 0, monster_timer = 0;
        while (window.isOpen())
        {

            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            powerup_timer += time; 
            fire_timer += time;
            danger_timer += time;
            lives_timer += time;
            if (!monster && !dragon)
            {
                if (alpha)
                {
                    alpha_bomb_timer += time;
                    beta_bomb_timer = 0;
                    gamma_bomb_timer = 0;
                }

                if (beta)
                {
                    alpha_bomb_timer = 0;
                    beta_bomb_timer += time;
                    gamma_bomb_timer = 0;
                }

                if (gamma)
                {
                    alpha_bomb_timer = 0;
                    beta_bomb_timer = 0;
                    gamma_bomb_timer += time;
                }

            }
            Event e;
            bool x = false;

            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game                        	    
            }
            //Pause Menu
            if (Keyboard::isKeyPressed(Keyboard::P))
            {
                pause = true;
            }
            if (Keyboard::isKeyPressed(Keyboard::R))
            {
                pause = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::H))
                help = true;
            if (Keyboard::isKeyPressed(Keyboard::M))
                help = false;
            if (Keyboard::isKeyPressed(Keyboard::Q))
            {
                window.close();
            }
            window.draw(background);


            /*----------------------------------------------------------------------------------------------------Pause Game--------------------------------------------------------------------------------------------*/
            if (help)
            {
                howToPlay();
                window.draw(HTP);
                window.display();
                continue;
            }
            if (pause && !help)
            {
                gamepause();
                window.draw(gpause);
                window.display();
                continue;
            }
            /*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


            /*----------------------------------------------------------------------------------------Player Movement and Fire-------------------------------------------------------------------------------------*/
                    //movement		
            if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
                p->move("l");    // Player will move to left
            if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                p->move("r");  //player will move to right
            if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
                p->move("u");    //player will move upwards
            if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
                p->move("d");  //player will move downwards
            p->fire(fire, powerup);
            /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



            /*---------------------------------------------------------------------------------------------------Start AddOn Fall---------------------------------------------------------------------------------------*/
                  //Add Ons
            if (powerup_timer >= 7.0)
            {
                int x_cor = 100, y_cor = 0;
                p->P1.sprite.setPosition(x_cor, y_cor);
                powerup_timer = 0;
            }
            p->P1.move();


            if (fire_timer >= 10.0)
            {
                int x_cor = 500, y_cor = 0;
                p->F1.sprite.setPosition(x_cor, y_cor);
                fire_timer = 0;
            }
            p->F1.move();


            if (danger_timer >= 13.0)
            {
                int x_cor = 350, y_cor = 0;
                p->D2.sprite.setPosition(x_cor, y_cor);
                danger_timer = 0;
                danger = true;
            }
            p->D2.move();

            if (lives_timer >= 15.0)
            {
                int x_cor = 300, y_cor = 0;
                p->L1.sprite.setPosition(x_cor, y_cor);
                lives_timer = 0;
            }
            p->L1.move();
            /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



            /*----------------------------------------------------------------------------------------Enemy Bombs------------------------------------------------------------------------------------------------------*/

            if (!monster && !dragon)
            {
                if (alpha)
                {
                    if (alpha_bomb_timer > 5)
                    {
                        for (int i = 0; i < alphaCount; i++)
                        {
                            e1[i].bomb.sprite.setPosition(e1[i].sprite.getPosition().x + 30.0f, e1[i].sprite.getPosition().y + 20.0f);

                        }
                        alpha_bomb = true;
                        alpha_bomb_timer = 0;
                    }
                }
                if (alpha_bomb)
                {
                    for (int i = 0; i < alphaCount; i++)
                        e1[i].bomb.move();
                }

                if (beta)
                {
                    if (beta_bomb_timer > 3)
                    {

                        for (int i = 0; i < betaCount; i++)
                        {
                            e2[i].bomb.sprite.setPosition(e2[i].sprite.getPosition().x + 30.0f, e2[i].sprite.getPosition().y + 20.0f);

                        }
                        beta_bomb = true;
                        beta_bomb_timer = 0;
                    }
                }
                if (beta_bomb)
                {
                    for (int i = 0; i < betaCount; i++)
                        e2[i].bomb.move();
                }

                if (gamma)
                {
                    if (gamma_bomb_timer > 2)

                    {

                        for (int i = 0; i < gammaCount; i++)
                        {
                            e3[i].bomb.sprite.setPosition(e3[i].sprite.getPosition().x + 30.0f, e3[i].sprite.getPosition().y + 20.0f);

                        }
                        gamma_bomb = true;
                        gamma_bomb_timer = 0;
                    }
                }
                if (gamma_bomb)
                {
                    for (int i = 0; i < gammaCount; i++)
                        e3[i].bomb.move();
                }


                if (!alpha)
                {
                    for (int i = 0; i < alphaCount; i++)
                        e1[i].bomb.sprite.setPosition(-1232, -24124);
                }

                if (!beta)
                {
                    for (int i = 0; i < betaCount; i++)
                        e2[i].bomb.sprite.setPosition(-1232, -24124);
                }

                if (!gamma)
                {
                    for (int i = 0; i < gammaCount; i++)
                        e3[i].bomb.sprite.setPosition(-1232, -24124);
                }

            }

            /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



            /*---------------------------------------------------------------------------Bomb And Spaceship Collision---------------------------------------------------------------------------------------------------*/

            if (alpha)
            {
                for (int i = 0; i < alphaCount; i++)
                {
                    if ((e1[i].bomb.sprite.getPosition().x >= (p->sprite.getPosition().x) && e1[i].bomb.sprite.getPosition().x <= (p->sprite.getPosition().x + 80.0f)) && (e1[i].bomb.sprite.getPosition().y >= p->sprite.getPosition().y) && (e1[i].bomb.sprite.getPosition().y <= p->sprite.getPosition().y + 70.0f))
                    {
                        e1[i].bomb.sprite.setPosition(-1000, -1223);
                        p->HP -= 3;
                        if (p->HP <= 0)
                        {
                            p->sprite.setPosition(340, 700);
                            p->lives -= 1;
                            p->HP = 100;
                        }
                    }
                }
            }

            if (beta)
            {
                for (int i = 0; i < betaCount; i++)
                {
                    if ((e2[i].bomb.sprite.getPosition().x >= (p->sprite.getPosition().x) && e2[i].bomb.sprite.getPosition().x <= (p->sprite.getPosition().x + 80.0f)) && (e2[i].bomb.sprite.getPosition().y >= p->sprite.getPosition().y) && (e2[i].bomb.sprite.getPosition().y <= p->sprite.getPosition().y + 70.0f))
                    {
                        e2[i].bomb.sprite.setPosition(-1000, -1223);
                        p->HP = p->HP - 5;
                        if (p->HP <= 0)
                        {
                            p->sprite.setPosition(340, 700);
                            p->lives -= 1;
                            p->HP = 100;
                        }
                    }
                }
            }

            if (gamma)
            {
                for (int i = 0; i < gammaCount; i++)
                {
                    if ((e3[i].bomb.sprite.getPosition().x >= (p->sprite.getPosition().x) && e3[i].bomb.sprite.getPosition().x <= (p->sprite.getPosition().x + 80.0f)) && (e3[i].bomb.sprite.getPosition().y >= p->sprite.getPosition().y) && (e3[i].bomb.sprite.getPosition().y <= p->sprite.getPosition().y + 70.0f))
                    {
                        e3[i].bomb.sprite.setPosition(-1000, -1223);
                        p->HP = p->HP - 7;
                        if (p->HP <= 0)
                        {
                            p->sprite.setPosition(340, 700);
                            p->lives -= 1;
                            p->HP = 100;
                        }
                    }
                }
            }
            /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/




            /*---------------------------------------------------------------------------Bullet And Enemy Collision----------------------------------------------------------------------------------------------------*/
                     //Alpha collision (bullets colliding with alpha invaders)  

            if (fire)
            {
                for (int i = 0; i < alphaCount; i++)
                {
                    if ((p->FIRE.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->FIRE.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 80.0f)) && p->FIRE.sp.getPosition().y == e1[i].sprite.getPosition().y)
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        count += 1;
                        score += 10;
                    }
                }
            }
            else if (powerup)
            {
                for (int i = 0; i < alphaCount; i++)
                {
                    if ((p->b.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)) && p->b.sp.getPosition().y == e1[i].sprite.getPosition().y)
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }

                    if ((p->b4.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b4.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)))
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b4.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }
                    if ((p->b5.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b5.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)))
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b5.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }
                    if ((p->b6.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b6.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)))
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b6.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }

                    if ((p->b7.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b7.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)))
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b7.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }
                    if ((p->b8.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b8.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)))
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b8.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }
                    if ((p->b9.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b9.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)))
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b9.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }

                }
            }
            else
            {
                for (int i = 0; i < alphaCount; i++)
                {
                    if ((p->b.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)) && p->b.sp.getPosition().y == e1[i].sprite.getPosition().y)
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }

                    if ((p->b1.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b1.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)) && p->b1.sp.getPosition().y == e1[i].sprite.getPosition().y)
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b1.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }
                    if ((p->b2.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b2.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)) && p->b2.sp.getPosition().y == e1[i].sprite.getPosition().y)
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b2.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }
                    if ((p->b3.sp.getPosition().x >= (e1[i].sprite.getPosition().x) && p->b3.sp.getPosition().x <= (e1[i].sprite.getPosition().x + 99.0f)) && p->b3.sp.getPosition().y == e1[i].sprite.getPosition().y)
                    {
                        e1[i].sprite.setPosition(-10000, -100000);
                        p->b3.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                        count += 1;
                        score += 10;
                    }
                }
            }

            //Beta Collison (bullets colliding with  beta invaders)
            if (count == alphaCount)
            {
                if (fire)
                {
                    for (int i = 0; i < betaCount; i++)
                    {
                        if ((p->FIRE.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->FIRE.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)) && p->FIRE.sp.getPosition().y == e2[i].sprite.getPosition().y)
                        {
                            e2[i].sprite.setPosition(-10000, -100000);
                            count1 += 1;
                            score += 20;
                        }
                    }
                }
                else if (powerup)
                {
                    for (int i = 0; i < betaCount; i++)
                    {
                        if ((p->b.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)) && p->b.sp.getPosition().y == e2[i].sprite.getPosition().y)
                        {
                            e1[i].sprite.setPosition(-10000, -100000);
                            p->b.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 10;
                        }

                        if ((p->b4.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b4.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)))
                        {
                            e2[i].sprite.setPosition(-10000, -100000);
                            p->b4.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 10;
                        }
                        if ((p->b5.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b5.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)))
                        {

                            e2[i].sprite.setPosition(-10000, -100000);
                            p->b5.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 10;
                        }
                        if ((p->b6.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b6.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)))
                        {
                            e2[i].sprite.setPosition(-10000, -100000);
                            p->b6.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 10;
                        }

                        if ((p->b7.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b7.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)))
                        {
                            e2[i].sprite.setPosition(-10000, -100000);
                            p->b7.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 10;
                        }
                        if ((p->b8.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b8.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)))
                        {
                            e2[i].sprite.setPosition(-10000, -100000);
                            p->b8.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 10;
                        }
                        if ((p->b9.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b9.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)))
                        {
                            e2[i].sprite.setPosition(-10000, -100000);
                            p->b9.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 10;
                        }

                    }
                }
                else
                {
                    for (int i = 0; i < betaCount; i++)
                    {
                        if ((p->b.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)) && p->b.sp.getPosition().y == e2[i].sprite.getPosition().y)
                        {
                            e2[i].sprite.setPosition(-10000, -100000);
                            p->b.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 20;
                        }

                        if ((p->b1.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b1.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)) && p->b1.sp.getPosition().y == e2[i].sprite.getPosition().y)
                        {
                            e2[i].sprite.setPosition(-10000, -100000);
                            p->b1.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 20;
                        }
                        if ((p->b2.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b2.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)) && p->b2.sp.getPosition().y == e2[i].sprite.getPosition().y)
                        {
                            e2[i].sprite.setPosition(-10000, -100000);
                            p->b2.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 20;
                        }
                        if ((p->b3.sp.getPosition().x >= (e2[i].sprite.getPosition().x) && p->b3.sp.getPosition().x <= (e2[i].sprite.getPosition().x + 99.0f)) && p->b3.sp.getPosition().y == e2[i].sprite.getPosition().y)
                        {
                            e2[i].sprite.setPosition(-10000, -100000);
                            p->b3.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count1 += 1;
                            score += 20;
                        }

                    }
                }
            }

            //Gamma Collision (bullets colliding with gamma invaders)
            if (count1 == betaCount)
            {
                if (fire)
                {
                    for (int i = 0; i < gammaCount; i++)
                    {
                        if ((p->FIRE.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->FIRE.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)) && p->FIRE.sp.getPosition().y == e3[i].sprite.getPosition().y)
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            count2 += 1;
                            score += 30;
                        }
                    }
                }
                else if (powerup)
                {
                    for (int i = 0; i < gammaCount; i++)
                    {
                        if ((p->b.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)))
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 10;
                        }

                        if ((p->b4.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b4.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)))
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b4.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 10;
                        }
                        if ((p->b5.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b5.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)))
                        {

                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b5.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 10;
                        }
                        if ((p->b6.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b6.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)))
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b6.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 10;
                        }

                        if ((p->b7.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b7.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)))
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b7.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 10;
                        }
                        if ((p->b8.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b8.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)))
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b8.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 10;
                        }
                        if ((p->b9.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b9.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)))
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b9.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 10;
                        }

                    }
                }
                else
                {
                    for (int i = 0; i < gammaCount; i++)
                    {
                        if ((p->b.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)) && p->b.sp.getPosition().y == e3[i].sprite.getPosition().y)
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 30;
                        }

                        if ((p->b1.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b1.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)) && p->b1.sp.getPosition().y == e3[i].sprite.getPosition().y)
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b1.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 30;
                        }
                        if ((p->b2.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b2.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)) && p->b2.sp.getPosition().y == e3[i].sprite.getPosition().y)
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b2.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 30;
                        }
                        if ((p->b3.sp.getPosition().x >= (e3[i].sprite.getPosition().x) && p->b3.sp.getPosition().x <= (e3[i].sprite.getPosition().x + 99.0f)) && p->b3.sp.getPosition().y == e3[i].sprite.getPosition().y)
                        {
                            e3[i].sprite.setPosition(-10000, -100000);
                            p->b3.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                            count2 += 1;
                            score += 30;
                        }

                    }
                }
            }
            /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

            /*--------------------------------------------------------------------------------Spaceship and Enemy Collision---------------------------------------------------------------------------------------*/

                     //SpaceShip Collision

            /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


            /*------------------------------------------------------------------------------AddOn Pick-Ups---------------------------------------------------------------------------------------------------------------*/

                     //Powerup PickUp

            if ((p->P1.sprite.getPosition().x >= (p->sprite.getPosition().x) && p->P1.sprite.getPosition().x <= (p->sprite.getPosition().x + 99.0f)) && (p->P1.sprite.getPosition().y >= p->sprite.getPosition().y) && (p->P1.sprite.getPosition().y <= p->sprite.getPosition().y + 99.0f))
            {
                p->P1.sprite.setPosition(-10000, -100000);
                p->b4.sp.setPosition(p->sprite.getPosition().x + 35.0f, p->sprite.getPosition().y + 10.0f);
                p->b5.sp.setPosition(p->sprite.getPosition().x + 20.0f, p->sprite.getPosition().y + 30.0f);
                p->b6.sp.setPosition(p->sprite.getPosition().x + 5.0f, p->sprite.getPosition().y + 50.0f);
                p->b7.sp.setPosition(p->sprite.getPosition().x + 50.0f, p->sprite.getPosition().y + 10.0f);
                p->b8.sp.setPosition(p->sprite.getPosition().x + 65.0f, p->sprite.getPosition().y + 30.0f);
                p->b9.sp.setPosition(p->sprite.getPosition().x + 80.0f, p->sprite.getPosition().y + 50.0f);
                powerup = true;
            }

            if (powerup)
            {
                powerupPickTimer += time;
            }


            //Fire Pickup

            if ((p->F1.sprite.getPosition().x >= (p->sprite.getPosition().x) && p->F1.sprite.getPosition().x <= (p->sprite.getPosition().x + 99.0f)) && (p->F1.sprite.getPosition().y >= p->sprite.getPosition().y) && (p->F1.sprite.getPosition().y <= p->sprite.getPosition().y + 99.0f))
            {
                fire = true;
                p->F1.sprite.setPosition(-10000, -100000);
            }

            if (fire)
            {
                firePickTimer += time;
            }

            //Lives Pickup
            if ((p->L1.sprite.getPosition().x >= (p->sprite.getPosition().x) && p->L1.sprite.getPosition().x <= (p->sprite.getPosition().x + 99.0f)) && (p->L1.sprite.getPosition().y >= p->sprite.getPosition().y) && (p->L1.sprite.getPosition().y <= p->sprite.getPosition().y + 99.0f))
            {
                p->L1.sprite.setPosition(-10000, -100000);
                p->lives += 1;

            }

            //Danger PickUp
            if ((p->D2.sprite.getPosition().x >= (p->sprite.getPosition().x) && p->D2.sprite.getPosition().x <= (p->sprite.getPosition().x + 99.0f)) && (p->D2.sprite.getPosition().y >= p->sprite.getPosition().y) && (p->D2.sprite.getPosition().y <= p->sprite.getPosition().y + 99.0f))
            {
                if (!powerup)
                {
                    p->D2.sprite.setPosition(-10000, -100000);
                    p->HP -= 30;
                    if (p->HP <= 0)
                    {
                        p->lives -= 1;
                        p->sprite.setPosition(340, 700);
                        p->HP = 100;
                    }
                }
            }

            if (p->D2.sprite.getPosition().y > 780 && danger)
            {
                score += 15;
                danger = false;
            }


            /*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


            /*------------------------------------------------------------------------------AddOn End--------------------------------------------------------------------------------------------------------------*/
                     //finshing powerup add on
            if (powerupPickTimer >= 1.7)
            {
                p->sprite.setScale(0.75, 0.75);
                p->b.sp.setScale(0.25, 0.25);
                p->b1.sp.setScale(0.25, 0.25);
                p->b2.sp.setScale(0.25, 0.25);
                p->b3.sp.setScale(0.25, 0.25);
                p->b.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                p->b1.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                p->b2.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                p->b3.sp.setPosition(p->sprite.getPosition().x + 30.0f, p->sprite.getPosition().y + 40.0f);
                powerup = false;
                powerupPickTimer = 0;
            }

            //finishing fire add on
            if (firePickTimer >= 2)
            {
                fire = false;
                firePickTimer = 0;
            }
            /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


            /*------------------------------------------------------------------------------------------Drawing Stuff and Checking Levels------------------------------------------------------------------------*/
                    //drawing stuff 

            if (fire)
                window.draw(p->FIRE.sp);
            if (powerup)
            {
                window.draw(p->b.sp);
                window.draw(p->b4.sp);
                window.draw(p->b5.sp);
                window.draw(p->b6.sp);
                window.draw(p->b7.sp);
                window.draw(p->b8.sp);
                window.draw(p->b9.sp);
            }

            if (!fire && !powerup)
            {
                window.draw(p->b.sp);
                window.draw(p->b1.sp);
                window.draw(p->b2.sp);
                window.draw(p->b3.sp);
            }
            window.draw(p->F1.sprite);
            window.draw(p->P1.sprite);
            window.draw(p->L1.sprite);
            window.draw(p->D2.sprite);

            window.draw(p->sprite);   // setting player on screen

            if (!monster && !dragon)
            {
                for (int i = 0; i < alphaCount; i++)
                {
                    alpha = true;
                    window.draw(e1[i].bomb.sprite);
                    window.draw(e1[i].sprite);

                }


                //checking waves
                if (count == alphaCount)
                {
                    alpha = false;
                    alpha_bomb = false;
                    beta = true;
                    for (int i = 0; i < betaCount; i++)
                    {

                        window.draw(e2[i].bomb.sprite);
                        window.draw(e2[i].sprite);

                    }
                }

                if (count1 == betaCount)
                {
                    alpha = false;
                    alpha_bomb = false;
                    beta = false;
                    beta_bomb = false;
                    gamma = true;
                    for (int i = 0; i < gammaCount; i++)
                    {

                        window.draw(e3[i].bomb.sprite);
                        window.draw(e3[i].sprite);
                    }
                }

                if (count2 == gammaCount)
                {
                    alpha = true;
                    beta = false;
                    beta_bomb = false;
                    gamma = false;
                    gamma_bomb = false;
                    level += 1;
                    if (level == 2)
                        level_clear = true;
                    else
                        boss = true;
                    gammaCount = 0;
                }
            }


            if (level == 2 && level_clear)
            {
                e1 = new AlphaInvaders[20];
                e2 = new BetaInvaders[20];
                e3 = new GammaInvaders[20];
                alphaCount = setEnemies(2, 1, e1);
                count = 0;
                betaCount = setEnemies(2, 2, e2);
                count1 = 0;
                gammaCount = setEnemies(2, 3, e3);
                count2 = 0;
                level_clear = false;
            }


            //start monster
            if (level == 3 && boss)
            {
                monster = true;
                M1->lightning.setPosition(200, 200);
            }

            if (monster)
            {
                boss = false;
                monster_timer += time;
                if (monster_timer < 15)
                {
                    window.draw(M1->lightning);
                    window.draw(M1->sprite);
                    M1->BossMove();
                }
                else
                {
                    monster = false;
                    M1->sprite.setPosition(-100000, -1022102);
                    M1->lightning.setPosition(-10202121, -24124124);
                    level_clear = true;
                    score += 40;
                }
            }

            //start level 3
            if (level == 3 && level_clear)
            {
                e1 = new AlphaInvaders[20];
                e2 = new BetaInvaders[20];
                e3 = new GammaInvaders[20];
                alphaCount = setEnemies(3, 1, e1);
                count = 0;
                betaCount = setEnemies(3, 2, e2);
                count1 = 0;
                gammaCount = setEnemies(3, 3, e3);
                count2 = 0;
                level_clear = false;
            }


            //start dragon
            if (level > 3 && boss)
            {
                dragon = true;
                D1->dragonFire.setPosition(150, 320);
                D1->dragonFire2.setPosition(50, 320);
                D1->dragonFire3.setPosition(180, 320);
            }
            if (dragon)
            {
                boss = false;
                dragon_timer += time;
                if (dragon_timer <= 20)
                {
                    window.draw(D1->dragonFire);
                    window.draw(D1->dragonFire2);
                    window.draw(D1->dragonFire3);
                    window.draw(D1->sprite);
                    D1->BossMove();
                }
                else
                {
                    dragon = false;
                    D1->sprite.setPosition(-100000, -222112);
                    D1->dragonFire.setPosition(-214124, -421412);
                    D1->dragonFire2.setPosition(-214124, -421412);
                    D1->dragonFire3.setPosition(-214124, -421412);
                    level_clear = true;
                    score += 50;
                }
            }
            /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


            /*-------------------------------------------------------------checking collision with dragon fire and monster lightning------------------------------------------------------------------------------*/


                //collision with moster lightning
            if (((p->sprite.getPosition().x >= M1->lightning.getPosition().x) && (p->sprite.getPosition().x <= M1->lightning.getPosition().x + 100.0f)) && (p->sprite.getPosition().y >= M1->lightning.getPosition().y) && (p->sprite.getPosition().y <= M1->lightning.getPosition().y + 580.0f))
            {
                p->sprite.setPosition(0, 500);
                p->lives -= 1;
                p->HP = 100;
            }


            // collision with dragon fire
            if (((p->sprite.getPosition().x >= D1->dragonFire.getPosition().x) && (p->sprite.getPosition().x <= D1->dragonFire.getPosition().x + 50.0f)) && (p->sprite.getPosition().y >= D1->dragonFire.getPosition().y) && (p->sprite.getPosition().y <= D1->dragonFire.getPosition().y + 480.0f))
            {

                p->sprite.setPosition(0, 500);
                p->lives -= 1;
                p->HP = 100;
            }

            if (((p->sprite.getPosition().x >= D1->dragonFire2.getPosition().x) && (p->sprite.getPosition().x <= D1->dragonFire2.getPosition().x + 50.0f)) && (p->sprite.getPosition().y >= D1->dragonFire2.getPosition().y) && (p->sprite.getPosition().y <= D1->dragonFire2.getPosition().y + 480.0f))
            {
                p->sprite.setPosition(0, 500);
                p->lives -= 1;
                p->HP = 100;
            }

            if (((p->sprite.getPosition().x >= D1->dragonFire3.getPosition().x) && (p->sprite.getPosition().x <= D1->dragonFire3.getPosition().x + 50.0f)) && (p->sprite.getPosition().y >= D1->dragonFire3.getPosition().y) && (p->sprite.getPosition().y <= D1->dragonFire3.getPosition().y + 480.0f))
            {
                p->sprite.setPosition(0, 500);
                p->lives -= 1;
                p->HP = 100;

            }

            /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


            /*-----------------------------------------------------------------------------------Game Over Calling------------------------------------------------------------------------------------------------*/

            if (level > 3 && level_clear)
            {
                g1.gameover(window, true, score, username);
            }

            if (p->lives < 0)
            {
                g1.gameover(window, false, score, username);
            }

            /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

            lives.setString(to_string(p->lives));
            scoring.setString(to_string(score));
            HP.setString(to_string(p->HP));
            if (p->HP >= 90)
                Health.setTexture(health_t1);
            else if (p->HP >= 70 && p->HP < 90)
                Health.setTexture(health_t2);
            else if (p->HP > 50 && p->HP < 70)
                Health.setTexture(health_t3);
            else if (p->HP >= 30 && p->HP < 70)
                Health.setTexture(health_t4);
            else
                Health.setTexture(health_t5);
            window.draw(lives);
            window.draw(scoring);
            window.draw(HP);
            window.draw(Health);
            window.display();  //Displaying all the sprites
        }


    }

    void gamepause()
    {

        bg.loadFromFile("img/pause-bg1.jpg");
        gpause.setTexture(bg);
        gpause.setScale(1, 1);

    }

    void howToPlay()
    {

        HTP_BG.loadFromFile("img/howtoplay_bg.jpg");
        HTP.setTexture(HTP_BG);
        HTP.setScale(1, 1);
        help = true;
    }

};

