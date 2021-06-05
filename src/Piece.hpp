/**************************
 *      PIECES CLASS      *
 **************************/

#ifndef __PIECES__
#define __PIECES__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "PIECETYPES.hpp"

using namespace sf;

class Piece
{
private:
    Sprite      _Sprite;
    Texture     _Texture;
    Vector2i    _Position;
    TYPES       _Type;
    
public:
    Piece();
    Piece(const TYPES type);
    ~Piece();
};



#endif