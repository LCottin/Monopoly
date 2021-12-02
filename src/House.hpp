/********************
 *       HOUSE      *
 ********************/

#ifndef __HOUSE__
#define __HOUSE__

#include <iostream>
#include <string>
#include <vector>

#include "Player.hpp"
#include "PLACES.hpp"

using namespace std;

class House
{
    private:
        PLACES  _Place;
        string  _Name;
        int     _Price;
        bool    _IsSold;
        Player* _Owner;

    public:
        House(PLACES place, string name, int price);
        int     getPrice() const;
        PLACES  getPlace() const;
        string  getName() const;
        Player* getOwner();
        bool    IsSold() const;

        void    setOwner(Player* player);
        void    setSold(bool sold);

        ~House();
};

#endif