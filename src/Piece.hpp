/*************************
 *      PIECE CLASS      *
 *************************/

#ifndef __PIECES__
#define __PIECES__

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "PIECETYPES.hpp"

using namespace std;
using namespace sf;

class Piece
{
    private:
        Sprite      _Sprite;
        Texture     _Texture;
        Vector2f    _Position;
        Vector2f    _Scale;
        TYPES       _Type;
        
    public:
        Piece();
        Piece(const TYPES type);
        Sprite*     getSprite();
        TYPES       getType() const;
        Vector2f    getPosition() const;
        void        move(const Vector2f newPos);
        void        setScale(const double newScale);
        ~Piece();
};

#endif