/**************************
 *      PLAYER CLASS      *
 **************************/

#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include <iostream>
#include "Piece.hpp"

using namespace std;

class Player
{
    private:
        string  _Pseudo;
        Piece*  _Piece;
        int     _Money;
        bool    _Alive;

    public:
        Player(const string name);
        string  getName() const;
        Piece*  getPiece() const;
        int     getMoney() const;
        bool    getStatus() const;
    
        ~Player();
};


#endif