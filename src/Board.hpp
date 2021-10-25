/**************************
 *      BOARD CLASS      *
 **************************/

#ifndef __BOARD__
#define __BOARD__

#include <string>
#include <iostream>
#include "Piece.hpp"
#include "Dice.hpp"
#include "Player.hpp"

using namespace std;

class Board
{
    protected:
        Texture     _Texture, _FocusTexture;
        Sprite      _Sprite, _FocusSprite;
        void        movePiece(RenderWindow& window, Player* player);
        
    public:
        Board();
        Sprite* getSprite();
        Sprite* getOtherSprite();
        void    drawPieces(RenderWindow& window, vector<Player*> players);
        void    drawRolls(RenderWindow& window, const int* rolls);
        ~Board();
};

static Board board;

#endif