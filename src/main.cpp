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
#include "Communities.hpp"
#include "Chances.hpp"

using namespace std;
using namespace sf;

int main(int argc, char const *argv[])
{
    //Creation of a window to try drawing the dice
    RenderWindow window(VideoMode(800, 800), "try");
    window.setFramerateLimit(50);

    //creation
    Dice d;
    Player* pl = new Player("Test", CAR);
    Communities com;
    Chances ch;
    
    Texture font;
    font.loadFromFile("./Images/Boards/monopoly.png");
    
    Sprite bg;
    bg.setTexture(font);


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
        window.draw(*com.getMainSprite());
        window.draw(*ch.getMainSprite());
        ch.drawCard();
        
        d.roll();
        window.draw(*d.getSprite());
        
        pl->getPiece()->move(Vector2f(100, 100));
        window.draw(*pl->getPiece()->getSprite());
        
        window.display();
    }

    delete pl;
    cout << "Runned main" << endl;
    return 0;
}
