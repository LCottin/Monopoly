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
        Bank*           _Bank;
        int             _Money;
        bool            _Alive;
        bool            _InJail;
        int             _Position;
        int             _Rolls[2];
        int             _Assets;
        int             _TurnsInJail;
        vector<House*>  _Properties;

        static vector<int>      _AvailablePieces;
        static vector<string>   _AvailableNames;

        void updateAssets();

    public:
        Player(const string name, Bank* bank);
        Player(const string name, Bank* bank, const TYPES type);

        string  getName() const;
        Piece*  getPiece() const;
        int     getMoney() const;
        int     getPosition() const;
        bool    getStatus() const;
        int     getPropertyCount() const;
        int     getAssets() const;
        bool    isInJail() const;
        int     getTurnsInJail() const;

        void    setInJail(const bool inJail);
        void    go();
        int*    rollDices(Dice* d1, Dice* d2);
        bool    move();
        bool    move(const int pos);
        bool    buy(House* house);
        bool    sell(House* house);
        bool    addMoney(const int money, const bool fromBank = true);
        bool    payBank(const int money);
        bool    removeMoney(const int money);
        bool    payRent(Player* player, const int amount);
        bool    updateTurnsInJail();
    
        ~Player();
};


#endif