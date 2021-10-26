#include "Chances.hpp"

/**
 * Default constructor
 */
Chances::Chances() : Cards()
{
    _MainTexture.loadFromFile("./Images/Chances/chance.png");
    _MainSprite.setTexture(_MainTexture);
    _MainSprite.setPosition(Vector2f(442, 603));
    _MainSprite.setRotation(315);
    
    _FocusTexture.loadFromFile("./Images/Chances/chance_focus.png");
    _FocusSprite.setTexture(_FocusTexture);
    _FocusSprite.setPosition(Vector2f(442, 603));
    _FocusSprite.setRotation(315);
}

/**
 * Draws a card randomly, saves it and returns the sprite associated
 * @returns The sprite of the card 
 */
Sprite* Chances::drawCard()
{
    //generates a pseudo random number between 1 and Cards
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> distribute(1, _Cards); // distribution in range [1, Cards]
    int random;
    
    //makes sure the cards has not already been picked 
    do
    {
        random = distribute(rng);
    } while (find(_Numbers.begin(), _Numbers.end(), random) != _Numbers.end());
    
    //saves the info about the number of the card
    _Numbers.push_back(random);
    if (_Numbers.size() == _Cards)
        _Numbers.clear();

    //opens the right file
    string path = "./Images/Chances/chance" + to_string(random) + ".png";
    _OtherTexture.loadFromFile(path.c_str());
    _OtherSprite.setTexture(_OtherTexture);

    return &_OtherSprite;
}

/**
 * Default destructor
 */
Chances::~Chances()
{
}