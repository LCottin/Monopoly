/*************************
 *       CARDS CLASS     *
 *************************/

#ifndef __CARDS__
#define __CARDS__

#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

using namespace std;
using namespace sf;

class Cards
{
    protected:
        //number of cards available
        int _Cards;
        vector<int> _Numbers;
        
        //template cards
        Texture _MainTexture;
        Sprite _MainSprite;

        //other cards
        Texture _OtherTexture;
        Sprite _OtherSprite;

        //cards scale
        Vector2f _Scale;

    public:
        Cards();
        Sprite* getMainSprite();
        virtual Sprite* drawCard() = 0;
        virtual ~Cards() = 0;
};


#endif