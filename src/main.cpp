/************************
 *      MAIN FILE       *
 ************************/

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "Dice.hpp"
#include "Piece.hpp"
#include "Player.hpp"

using namespace std;
using namespace sf;

int main(int argc, char const *argv[])
{
    //Dice creation
    Dice d;
    Player* pl = new Player("Test", CAR);

    Texture font, font2;
    font.loadFromFile("./Images/Boards/game.png");
    font2.loadFromFile("./Images/test2.png");

    Sprite bg, bg2;
    bg.setTexture(font);
    bg2.setTexture(font2);

    //Creation of a window to try drawing the dice
    RenderWindow window(VideoMode(800, 800), "try");
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
        window.draw(bg);
        window.draw(bg2);

        /*
        d.roll();
        window.draw(*d.getSprite());
        
        pl->getPiece()->move(Vector2f(100, 100));
        window.draw(*pl->getPiece()->getSprite());
        */
        window.display();
    }

    delete pl;
    cout << "Runned main" << endl;
    return 0;
}
