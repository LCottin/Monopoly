/*************************
 *   COMMUNITIES CLASS   *
 *************************/

#ifndef __COMMUNITIES__
#define __COMMUNITIES__

#include "Cards.hpp"

class Communities : public Cards
{
    public:
        Communities();
        Sprite* drawCard();
        ~Communities();
};

#endif