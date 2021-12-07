#include "Cards.hpp"

/**
 * Default constructor
 */
Cards::Cards() 
{
    _CardsInDeck  = 16;
    _Number       = 0;
    _Scale        = Vector2f(0.45, 0.50);

    _MainSprite.setScale(_Scale);
    _FocusSprite.setScale(_Scale);

    _OtherSprite.setPosition(Vector2f(150, 200));
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
 * Returns the out of focus sprite of a card, ie it's back
 * @returns The out of focus sprite
 */
Sprite* Cards::getFocusSprite()
{
    return &_FocusSprite;
}

/**
 * Default destructor
 */
Cards::~Cards() 
{
}