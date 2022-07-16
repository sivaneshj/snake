#include <SFML/Graphics.hpp>
#include "snake.h"
#include "food.h"
#include <vector>
#include <windows.h>
#include <iostream>

#define WIDTH 50
#define HEIGHT 30
#define SIZE 16
#define W SIZE*WIDTH
#define H SIZE*HEIGHT
using namespace sf;


snake snake({WIDTH/2,HEIGHT/2});
food food;

int main()
{
    Clock clock;
    float timer = 0, delay = 0.1;
    RenderWindow window(VideoMode(W,H),"Snake Game");

    Texture t1,t2;
    t1.loadFromFile("images/green.png");
    t2.loadFromFile("images/red.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);
    while(window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) snake.setdir('l');
        if (Keyboard::isKeyPressed(Keyboard::Right)) snake.setdir('r');
        if (Keyboard::isKeyPressed(Keyboard::Up)) snake.setdir('u');
        if (Keyboard::isKeyPressed(Keyboard::Down)) snake.setdir('d');

        if(timer>delay)
        {
            snake.movesnake();
            timer = 0;
            if(snake.eaten(food))
            {
                snake .grow();
                food .genfood();
            }
        }


        window.clear();

        for(int i=0;i<WIDTH;i++)
            for(int j=0;j<HEIGHT;j++)
            {
                sprite1.setPosition(i*SIZE,j*SIZE);
                window.draw(sprite1);
            }

        vector<COORD> s = snake.getsnakebody();
        for(int i=0;i<s.size();i++)
        {
            sprite2.setPosition(s[i].X*SIZE,s[i].Y*SIZE);
            window.draw(sprite2);
        }

        sprite2.setPosition(food.getfoodpos().X*SIZE,food.getfoodpos().Y*SIZE);
        window.draw(sprite2);

        if(snake.collided())
        {
            window.clear();
            Text t;
            t.setString("GAME OVER");
            Font f;
            if(!f.loadFromFile("fonts/Arial.ttf"))
            {
                std::cout<<"game over";
            }
            t.setFont(f);
            t.setCharacterSize(50);
            t.setStyle(Text::Bold);
            t.setPosition(W/3,H/3);
           
            for (int i=0; i<WIDTH; i++)
                for (int j=0; j<HEIGHT; j++)
                { sprite1.setPosition(i*SIZE, j*SIZE);  window.draw(sprite1);}
             window.draw(t);
            window.display();
            Sleep(3000);
            break;
        }
        window.display();


    }
    return 0;
}
