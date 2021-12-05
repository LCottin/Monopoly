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
#include "House.hpp"

using namespace std;

class House; // Forward declaration of House class to avoid circular dependency
class Player
{
    private:
        string          _Pseudo;
        Piece*          _Piece;
        int             _Money;
        bool            _Alive;
        bool            _InJail;
        int             _Position;
        int             _Rolls[2];
        vector<House*>  _Properties;

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
        bool    buy(House* house);
        bool    sell(House* house);
        void    addMoney(const int money);
        bool    removeMoney(const int money);
        bool    payRent(Player* player, const int amount);
    
        ~Player();
};


#endif