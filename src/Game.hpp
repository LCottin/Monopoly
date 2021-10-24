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
        Player*         _CurrentPlayer;
        Dice*           _Dice1;
        Dice *          _Dice2;
        Bank            _Bank;

        int             _NbPlayers;
        int             _CurrentTurn;

    public:
        Game();
        void getNbPlayers();
        bool playGame();
        ~Game();
};




#endif