/**************************
 *      BOARD CLASS      *
 **************************/

#ifndef __BOARD__
#define __BOARD__

#include <string>
#include <iostream>
#include "Piece.hpp"
#include "Bank.hpp"
#include "Dice.hpp"

using namespace std;

class Board
{
    private:
        Texture      _Texture;
        Sprite       _Sprite;
        
    public:
        Board();
        Sprite* getSprite();
        ~Board();
};

static Board board;

#endif