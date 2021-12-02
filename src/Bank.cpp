#include "Bank.hpp"

/**
 * @brief Constructs a new Bank object
 */
Bank::Bank()
{
    _Amount = 20000;
}

/**
 * @brief Tells how much left in the bank
 * @returns Amount of money in the bank
 */
int Bank::getAmout() const
{
    return _Amount;
}

/**
 * @brief Takes money from the bank
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
 * @brief Gives money to the bank
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
