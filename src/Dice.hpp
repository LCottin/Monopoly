/************************
 *      DICE CLASS      *
 ************************/

#ifndef __DICE__
#define __DICE__

#include <iostream>
#include <random>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Dice
{
    private:
        Sprite  _Sprite;
        Texture _Texture;
        
    public:
        Dice();
        int roll();
        Sprite* getSprite();
        ~Dice();
};




#endif