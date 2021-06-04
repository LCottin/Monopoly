/************************
 *      DICE CLASS      *
 ************************/

#ifndef __DICE__
#define __DICE__

#include <iostream>
#include <random>
// #include <SFML/Graphics.hpp>
// #include <SFML/Window.hpp>

using namespace std;
// using namespace sf;

class Dice
{
    private:
        //Sprite  _DiceSprite;
        //Texture _DiceTexture;
        void update();
        
    public:
        Dice();
        int roll() const;
        //Sprite* getSprite() const;
        ~Dice();
};




#endif