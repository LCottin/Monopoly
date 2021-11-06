/**************************
 *      PLAYER CLASS      *
 **************************/

#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include <iostream>
#include <algorithm>
#include "Piece.hpp"
#include "PLACES.hpp"
#include "Bank.hpp"
#include "Dice.hpp"

using namespace std;
using namespace sf;

class Player
{
    private:
        string      _Pseudo;
        Piece*      _Piece;
        int         _Money;
        bool        _Alive;
        bool        _InJail;
        int         _Position;
        int         _Rolls[2];

        static vector<int>      _AvailablePieces;
        static vector<string>   _AvailableNames;

    public:
        Player(const string name);
        Player(const string name, const TYPES type);
        string  getName() const;
        Piece*  getPiece() const;
        int     getMoney() const;
        int     getPosition() const;
        bool    getStatus() const;
        bool    isInJail() const;
        void    go(Bank* bank);
        int*    rollDices(Dice* d1, Dice* d2);
        bool    move();
        void    move(const int pos);
    
        ~Player();
};


#endif