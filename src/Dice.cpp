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
int Dice::roll()
{
    //generates a pseudo random number between 1 and 6
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

    int random = dist6(rng);
    cout << dist6(rng) << endl;

    //sets correct texture according to the number generated
    switch (random)
    {
        case 1:
            _Texture.loadFromFile("./Images/Dice/dice1.png");
            break;
        
        case 2:
            _Texture.loadFromFile("./Images/Dice/dice2.png");
            break;

        case 3:
            _Texture.loadFromFile("./Images/Dice/dice3.png");
            break;

        case 4:
            _Texture.loadFromFile("./Images/Dice/dice4.png");
            break;

        case 5:
            _Texture.loadFromFile("./Images/Dice/dice5.png");
            break;

        case 6:
            _Texture.loadFromFile("./Images/Dice/dice6.png");
            break;

        default:
            break;
    }

    //sets sprite and position
    _Sprite.setTexture(_Texture);
    _Sprite.setPosition(Vector2f(0, 0));
    return random;
}

/**
 * Gets the right sprite of the dice to print
 * @returns The sprite to draw 
 */
Sprite* Dice::getSprite()
{
    return &_Sprite;
}

/**
 * Default destructor
 */
Dice::~Dice()
{
}