/************************
 *      DICE CLASS      *
 ************************/

#ifndef __DICE__
#define __DICE__

#include <iostream>
#include <random>
#include <vector>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Dice
{
    private:
        Sprite  _Sprite;
        vector<Texture> _Textures;
        
    public:
        Dice();
        int roll();
        Sprite* getSprite();
        Sprite* getSprite(const int i);
        void    setPosition(const Vector2f pos);
        ~Dice();
};




#endif