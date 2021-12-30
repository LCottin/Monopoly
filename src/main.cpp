/************************
 *      MAIN FILE       *
 ************************/

#include "Game.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Game monopoly;
    const bool run = monopoly.playGame();
    
    if (run)
        cout << "Game finished." << endl;
    else
        cout << "Game aborted." << endl;

    return 0;
}
