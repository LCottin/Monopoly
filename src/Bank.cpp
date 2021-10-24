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
 * @returns true if the bank is empty, else false
 */
bool Bank::output(const int amout)
{
    _Amount -= amout;
    if (_Amount < 0)
    {
        _Amount = 0;
        return true;
    }
    return false;
}

/**
 * Gives money to the bank
 * @param amout Money to give
 */
void Bank::input(const int amout)
{
    _Amount += amout;
}

/**
 * Default destructor
 */
Bank::~Bank()
{
}
