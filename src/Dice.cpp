#include "Dice.hpp"

/**
 * Default constructor
 */
Dice::Dice()
{
    //creates all textures
    Texture t1;
    t1.loadFromFile("./Images/Dices/dice1.png");
    _Textures.push_back(t1);

    Texture t2;
    t2.loadFromFile("./Images/Dices/dice2.png");
    _Textures.push_back(t2);

    Texture t3;
    t3.loadFromFile("./Images/Dices/dice3.png");
    _Textures.push_back(t3);

    Texture t4;
    t4.loadFromFile("./Images/Dices/dice4.png");
    _Textures.push_back(t4);

    Texture t5;
    t5.loadFromFile("./Images/Dices/dice5.png");
    _Textures.push_back(t5);

    Texture t6;
    t6.loadFromFile("./Images/Dices/dice6.png");
    _Textures.push_back(t6);
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
    uniform_int_distribution<mt19937::result_type> dist6(1, 6); // distribution in range [1, 6]

    int random = dist6(rng);

    //sets correct texture according to the number generated
    _Sprite.setTexture(_Textures[random - 1]);
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
 * Gets the sprite of the dice according to its face
 * @returns The sprite to draw 
 */
Sprite* Dice::getSprite(const int i)
{
    _Sprite.setTexture(_Textures[i - 1]);
    return &_Sprite;
}

/**
 * Changes the position of the sprite
 * @param pos Vector containing the new position
 */
void Dice::setPosition(const Vector2f pos)
{
    _Sprite.setPosition(pos);
}

/**
 * Default destructor
 */
Dice::~Dice()
{
}