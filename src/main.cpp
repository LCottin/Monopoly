/************************
 *      MAIN FILE       *
 ************************/

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "Dice.hpp"
#include "Piece.hpp"
#include "Player.hpp"
#include "Communities.hpp"
#include "Chances.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

int main(int argc, char const *argv[])
{
    Game monopoly;
    bool run = monopoly.playGame();
    
    if (run)
        cout << "Game finished." << endl;
    else
        cout << "Game aborted." << endl;

    return 0;
}
