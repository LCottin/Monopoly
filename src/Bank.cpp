#include "Bank.hpp"

/**
 * Default constructor
 */
Bank::Bank()
{
    _Amount = 100000;
}

/**
 * Tells how much left in the bank
 * @returns Amount of money in the bank
 */
int Bank::getAmout() const
{
    return _Amount;
}

/**
 * Takes money from the bank
 * @param amout Money to take
 */
void Bank::take(const int amout)
{
    _Amount -= amout;
}

/**
 * Gives money to the bank
 * @param amout Money to give
 */
void Bank::give(const int amout)
{
    _Amount += amout;
}

/**
 * Default destructor
 */
Bank::~Bank()
{
}
