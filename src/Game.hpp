/**************************
 *       GAME CLASS       *
 **************************/

#ifndef __GAME__
#define __GAME__

#include "Board.hpp"
#include "Player.hpp"

using namespace std;

class Game
{
    private:
        RenderWindow    _Window;
        vector<Player*> _Players;
        vector<House*>  _Houses;
        Player*         _CurrentPlayer;
        Dice*           _Dice1;
        Dice*           _Dice2;
        Board*          _Board;
        Bank*           _Bank;
        Chances*        _Chances;
        Communities*    _Communities;

        int             _NbPlayers;
        int             _CurrentTurn;
        int             _TotalTurns;

    public:
        Game();
        void getNbPlayers();
        House* getHouse(string name);
        House* getHouse(PLACES place);
        bool playGame();
        ~Game();
};

#endif