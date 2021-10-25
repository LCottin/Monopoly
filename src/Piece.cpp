#include "Piece.hpp"

/**
 * Default constructor
 */
Piece::Piece()
{
}

Piece::Piece(const TYPES type)
{
    //sets initial position 
    _Position   = Vector2f(750, 750);
    _Scale      = Vector2f(0.1, 0.1);
    _Type       = type;

    //loads correct texture
    switch (type)
    {
        case BARROW:
            _Texture.loadFromFile("./Images/Pieces/barrow.png");
            break;
        
        case BASEBALL:
            _Texture.loadFromFile("./Images/Pieces/baseball.png");
            break;

        case CAR:
            _Texture.loadFromFile("./Images/Pieces/car.png");
            break;

        case DOG:
            _Texture.loadFromFile("./Images/Pieces/dog.png");
            break;

        case DRAGON:
            _Texture.loadFromFile("./Images/Pieces/dragon.png");
            break;

        case HAT:
            _Texture.loadFromFile("./Images/Pieces/hat.png");
            break;

        case PRETZEL:
            _Texture.loadFromFile("./Images/Pieces/pretzel.png");
            break;

        case SHIP:
            _Texture.loadFromFile("./Images/Pieces/ship.png");
            break;

        case SOCCER:
            _Texture.loadFromFile("./Images/Pieces/soccer.png");
            break;

        case SURFER:
            _Texture.loadFromFile("./Images/Pieces/surfer.png");
            break;

        default:
            _Texture.loadFromFile("./Images/Pieces/thimble.png");
            break;
    }
    _Sprite.setTexture(_Texture);
    _Sprite.scale(_Scale);
    _Sprite.setPosition(_Position);
}

/**
 * Changes the scale of the sprite
 * @param newScale New scale of the sprite
 */
void Piece::setScale(const double newScale)
{
    _Scale = Vector2f(newScale, newScale);
    _Sprite.scale(_Scale);
}

/**
 * Gets the sprite of the piece to draw
 * @returns The sprite to draw
 */
Sprite* Piece::getSprite()
{
    return &_Sprite;
}

/**
 * Indicates which piece it is 
 * @returns The type of the piece
 */
TYPES Piece::getType() const 
{
    return _Type;
}

/**
 * Tells where the piece is 
 * @returns A vector containing piece position
 */
Vector2f Piece::getPosition() const
{
    return _Position;
}

/**
 * Moves the piece
 * @param newPos Vector2i of the new position
 */
void Piece::move(const Vector2f newPos)
{
    _Sprite.setPosition(newPos);
    _Position = newPos;
}

/**
 * Default destructor
 */
Piece::~Piece()
{
}