#include "House.hpp"

/**
 * @brief Construct a new House:: House object  
 * 
 * @param place Place of the house
 * @param name Name of the house
 * @param price Price of the house
 */
House::House(PLACES place, string name, int price)
{
    _Place  = place;
    _Name   = name;
    _Price  = price;
    _IsSold = false;
    _Owner  = nullptr;
}

/**
 * @brief Returns the price of the house
 * @returns The price of the house
 */
int House::getPrice() const
{
    return _Price;
}

/**
 * @brief Returns the place of the house
 * @returns The place of the house
 */
PLACES House::getPlace() const
{
    return _Place;
}

/**
 * @brief Returns the name of the house
 * @returns The name of the house
 */
string House::getName() const
{
    return _Name;
}

/**
 * @brief Indicates if the house is sold or not
 * @returns True if the house is sold, false otherwise
 */
bool House::IsSold() const
{
    return _IsSold;
}

/**
 * @brief Returns the owner of the house
 * @returns The owner of the house
 */
Player* House::getOwner()
{
    return _Owner;
}

/**
 * @brief Sets the owner of the house
 * @param owner The owner of the house
 */
void House::setOwner(Player* owner)
{
    _Owner = owner;
}

/**
 * @brief Sets the house as sold
 * @param sold True if the house is sold, false otherwise
 */
void House::setSold(bool sold)
{
    _IsSold = sold;
}

House::~House()
{
}