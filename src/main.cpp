/************************
 *      MAIN FILE       *
 ************************/

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Dice.hpp"

using namespace std;
using namespace sf;

int main(int argc, char const *argv[])
{
    //Dice creation
    Dice d;

    //Creation of a window to try drawing the dice
    RenderWindow window(VideoMode(600, 600), "try");
    window.setFramerateLimit(5);

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        
        window.clear();

        int roll = d.roll();
        //Sprite* diceSprite = d.getSprite();
        window.draw(*d.getSprite());

        window.display();
    }

    cout << "Runned main" << endl;
    return 0;
}
