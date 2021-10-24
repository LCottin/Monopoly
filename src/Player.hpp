/**************************
 *      PLAYER CLASS      *
 **************************/

#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include <iostream>
#include "Piece.hpp"
#include "Bank.hpp"
#include "Dice.hpp"
#include "Board.hpp"

using namespace std;
using namespace sf;

class Player
{
    private:
        string  _Pseudo;
        Piece*  _Piece;
        int     _Money;
        bool    _Alive;
        bool    _InJail;
        int     _Position;
        int     _Roll1, _Roll2;

    public:
        Player(const string name);
        Player(const string name, const TYPES type);
        string  getName() const;
        Piece*  getPiece() const;
        int     getMoney() const;
        int     getPosition() const;
        bool    getStatus() const;
        bool    isInJail() const;
        void    go(Bank& bank);
        void    rollDices(RenderWindow& window, Dice* d1, Dice* d2);
        bool    move();
    
        ~Player();
};


#endif