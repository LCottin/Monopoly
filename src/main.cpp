/************************
 *      MAIN FILE       *
 ************************/

#include <iostream>
#include <string>

#include "Dice.hpp"

using namespace std;

int main(int argc, char const *argv[])
{

    Dice d;
    d.roll();

    cout << "Runned main" << endl;
    return 0;
}
