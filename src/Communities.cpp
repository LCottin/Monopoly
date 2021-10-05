#include "Communities.hpp"

/**
 * Default constructor
 */
Communities::Communities() : Cards()
{
    _Cards = 16;

    _MainTexture.loadFromFile("./Images/Communities/com.png");
    _MainSprite.setTexture(_MainTexture);
}

Sprite* Communities::drawCard()
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
    string path = "./Images/Communities/com" + to_string(random) + ".png";
    _OtherTexture.loadFromFile(path.c_str());
    _OtherSprite.setTexture(_OtherTexture);

    return &_OtherSprite;
}

/**
 * Default destructor
 */
Communities::~Communities()
{
}