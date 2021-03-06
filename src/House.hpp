/*************************
 *       HOUSE CLASS     *
 *************************/

#ifndef __HOUSE__
#define __HOUSE__

#include <iostream>
#include <string>
#include <vector>

#include "Player.hpp"
#include "PLACES.hpp"

using namespace std;

class Player; // Forward declaration of Player class to avoid circular dependency
class House
{
    private:
        PLACES  _Place;
        string  _Name;
        int     _Price;
        int     _Rent;
        bool    _IsSold;
        Player* _Owner;

    public:
        House(PLACES place, string name, int price, int rent);
        int     getPrice() const;
        PLACES  getPlace() const;
        string  getName() const;
        Player* getOwner();
        int     getRent() const;
        bool    IsSold() const;

        void    setOwner(Player* player);
        void    setSold(bool sold);

        ~House();
};

#endif