#include "Cards.hpp"

/**
 * Default constructor
 */
Cards::Cards() 
{
    _Cards = 16;
    _Scale = Vector2f(0.45, 0.50);
}

/**
 * Returns the main sprite of a card, ie it's back
 * @returns The main sprite
 */
Sprite* Cards::getMainSprite()
{
    return &_MainSprite;
}

/**
 * Default destructor
 */
Cards::~Cards() 
{
}