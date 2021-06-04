#include "Dice.hpp"

/**
 * Default constructor
 */
Dice::Dice()
{
}

/**
 * Rolls the dice to get a number
 * @returns A random number between 1 and 6
 */
int Dice::roll() const
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

    int random = dist6(rng);
    cout << dist6(rng) << endl;
    return random;
}

/**
 * Default destructor
 */
Dice::~Dice()
{
}