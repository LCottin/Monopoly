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
        RenderWindow    *_Window;

        Font            _Font;
        Text            _YesText, _NoText;

        RectangleShape  _YesBox, _NoBox;

        Vector2f        _YesBoxPos, _NoBoxPos;
        Vector2f        _YesBoxSize, _NoBoxSize;
        Vector2f        _YesTextPos, _NoTextPos;

        int*            _CurrentTurn; 
        Player*         _CurrentPlayer;
        void            movePiece(Player* player);

    public:
        Board(RenderWindow* window, int* currentTurn);
        Sprite* getSprite();
        Sprite* getOtherSprite();
        void    setCurrentPlayer(Player* player);
        void    drawBoard(const bool clear = true, const bool display = true);
        void    drawPieces(vector<Player*> players);
        void    drawRolls(const int* rolls);
        void    drawCard(const Sprite* card, const bool clear = true, const bool display = true);
        void    drawText(const Vector2f pos, const string text, const Color color = Color::Blue, const bool clear = true, const bool display = true);
        BOXES   boxClicked();
        ~Board();
};

#endif