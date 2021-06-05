#include "Piece.hpp"

/**
 * Default constructor
 */
Piece::Piece()
{
}

Piece::Piece(const TYPES type)
{
    //sets initial position at 0, 0
    _Position = Vector2i(0, 0);

    //loads correct texture
    switch (type)
    {
        case BARROW:
            _Type = BARROW;
            _Texture.loadFromFile("./Images/Pieces/barrow.png");
            break;
        
        case BASEBALL:
            _Type = BASEBALL;
            _Texture.loadFromFile("./Images/Pieces/baseball.png");
            break;

        case CAR:
            _Type = CAR;
            _Texture.loadFromFile("./Images/Pieces/car.png");
            break;

        case DOG:
            _Type = DOG;
            _Texture.loadFromFile("./Images/Pieces/dog.png");
            break;

        case DRAGON:
            _Type = DRAGON;
            _Texture.loadFromFile("./Images/Pieces/dragon.png");
            break;

        case HAT:
            _Type = HAT;
            _Texture.loadFromFile("./Images/Pieces/hat.png");
            break;

        case PRETZEL:
            _Type = PRETZEL;
            _Texture.loadFromFile("./Images/Pieces/pretzel.png");
            break;

        case SHIP:
            _Type = SHIP;
            _Texture.loadFromFile("./Images/Pieces/ship.png");
            break;

        case SOCCER:
            _Type = SOCCER;
            _Texture.loadFromFile("./Images/Pieces/soccer.png");
            break;

        case SURFER:
            _Type = SURFER;
            _Texture.loadFromFile("./Images/Pieces/surfer.png");
            break;

        default:
            _Type = THIMBLE;
            _Texture.loadFromFile("./Images/Pieces/thimble.png");
            break;
    }
    _Sprite.setTexture(_Texture);
    _Sprite.setPosition(Vector2f(_Position));
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
Vector2i Piece::getPosition() const
{
    return _Position;
}

/**
 * Moves the piece
 * @param newPos Vector2i of the new position
 */
void Piece::move(const Vector2i newPos)
{
    _Sprite.setPosition(Vector2f(newPos));
    _Position = newPos;
}

/**
 * Default destructor
 */
Piece::~Piece()
{
}