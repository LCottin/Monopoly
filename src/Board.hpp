/**************************
 *      BOARD CLASS      *
 **************************/

#ifndef __BOARD__
#define __BOARD__

#include <string>
#include <iostream>
#include "PLACES.hpp"
#include "Piece.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Communities.hpp"
#include "Chances.hpp"
#include "BOXES.hpp"

using namespace std;

class Board
{
    protected:
        Texture         _Texture, _FocusTexture;
        Sprite          _Sprite, _FocusSprite;
        void            movePiece(RenderWindow& window, Player* player);

        Font            _Font;
        Text            _YesText, _NoText;

        RectangleShape  _YesBox, _NoBox;

        Vector2f        _YesBoxPos, _NoBoxPos;
        Vector2f        _YesBoxSize, _NoBoxSize;
        Vector2f        _YesTextPos, _NoTextPos;


    public:
        Board();
        Sprite* getSprite();
        Sprite* getOtherSprite();
        void    drawBoard(RenderWindow& window, const bool clear = true, const bool display = true);
        void    drawPieces(RenderWindow& window, vector<Player*> players);
        void    drawRolls(RenderWindow& window, const int* rolls);
        void    drawCard(RenderWindow& window, const Sprite* card, const bool clear = true, const bool display = true);
        void    drawText(RenderWindow& window, const string text, const Color color = Color::Blue, const bool clear = true, const bool display = true);
        BOXES   boxClicked(RenderWindow& window);
        ~Board();
};

#endif