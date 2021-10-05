/*************************
 *      CHANCES CLASS    *
 *************************/

#ifndef __CHANCES__
#define __CHANCES__

#include "Cards.hpp"

class Chances : public Cards
{
    public:
        Chances();
        Sprite* drawCard();
        ~Chances();
};

#endif