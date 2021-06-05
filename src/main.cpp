/************************
 *      MAIN FILE       *
 ************************/

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Dice.hpp"
#include "Piece.hpp"

using namespace std;
using namespace sf;

int main(int argc, char const *argv[])
{
    //Dice creation
    Dice d;
    Piece p(BARROW);
    Texture font;
    font.loadFromFile("./Images/font.png");
    Sprite bg;
    bg.setTexture(font);

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
        window.draw(bg);

        d.roll();
        window.draw(*d.getSprite());
        
        p.move(Vector2i(100, 100));
        window.draw(*p.getSprite());

        window.display();
    }

    cout << "Runned main" << endl;
    return 0;
}
