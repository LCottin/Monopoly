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
#include "Player.hpp"

using namespace std;
using namespace sf;

class Cards
{
    protected:
        //number of cards available
        int         _CardsInDeck;
        int         _Number;
        vector<int> _Numbers;
        
        //template cards
        Texture _MainTexture, _FocusTexture;
        Sprite _MainSprite, _FocusSprite;

        //other cards
        Texture _OtherTexture;
        Sprite _OtherSprite;

        //cards scale
        Vector2f _Scale;

    public:
        Cards();
        Sprite* getMainSprite();
        Sprite* getFocusSprite();
        virtual Sprite* drawCard() = 0;
        virtual bool execute(Bank* bank, Player* player, vector<Player*>& players) = 0;
        virtual ~Cards();
};


#endif