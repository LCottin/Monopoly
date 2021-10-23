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

using namespace std;

class Player
{
    private:
        string  _Pseudo;
        Piece*  _Piece;
        int     _Money;
        bool    _Alive;
        int     _Position;
        int     _RollDice;

    public:
        Player(const string name);
        Player(const string name, const TYPES type);
        string  getName() const;
        Piece*  getPiece() const;
        int     getMoney() const;
        int     getPosition() const;
        bool    getStatus() const;
        void    go(Bank& bank);
        Sprite* roll();
        void    move();
    
        ~Player();
};


#endif