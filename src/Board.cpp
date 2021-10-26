#include "Board.hpp"

/**
 * Default constructor
 */
Board::Board()
{
    _Texture.loadFromFile("./Images/Boards/monopoly.png");
    _FocusTexture.loadFromFile("./Images/Boards/Monopoly2.png");

    _Sprite.setTexture(_Texture);
    _FocusSprite.setTexture(_FocusTexture);
}

/**
 * Returns the board sprite
 */
Sprite* Board::getSprite()
{
    return &_Sprite;
}

/**
 * Returns the board sprite out of focus
 */
Sprite* Board::getOtherSprite()
{
    return &_FocusSprite;
}

/**
 * Prints animation when dices are rolling
 * @param window Window to update
 * @param rolls Array with the result of the rolling
 */
void Board::drawRolls(RenderWindow& window, const int* rolls)
{
    //creates two artifial dices
    Dice* d1 = new Dice();
    Dice* d2 = new Dice();

    //1 : rolls dices to animate screen
    for (size_t i = 0; i < 20; i++)
    {
        //2 : changes framerate 
        window.setFramerateLimit(20 - i);
        
        d1->roll();
        d2->roll();

        d1->setPosition(Vector2f(50, 250));
        d2->setPosition(Vector2f(450, 250));

        window.clear();
        window.draw(_FocusSprite);
        window.draw(*d1->getSprite());
        window.draw(*d2->getSprite());
        window.display();

        //sleeps to slow down 
        sleep(milliseconds(100));
    }
    //3 : sets back framerate
    window.setFramerateLimit(10);

    //4 : prints real numbers 
    d1->setPosition(Vector2f(50, 250));
    d2->setPosition(Vector2f(450, 250));

    window.clear();
    window.draw(_FocusSprite);
    window.draw(*d1->getSprite(rolls[0]));
    window.draw(*d2->getSprite(rolls[1]));
    window.display();

    //sleeps for three seconds
    sleep(seconds(3));

    delete d1;
    delete d2;
}

/**
 * Prints each player's piece on the board
 * @param window Window to update
 * @param players Vector containing every player
 */
void Board::drawPieces(RenderWindow& window, vector<Player*> players)
{
    //prints each player's piece on the board
    for (size_t i = 0; i < players.size(); i++)
    {
        //moves the piece ...
        movePiece(window, players[i]);

        //...then displays it
        window.draw(*players[i]->getPiece()->getSprite());
    }
    window.display();
    sleep(seconds(2));
}

/**
 * Prints one piece on the board after being tested
 * @param window Window to update
 * @param player Player owning the piece
 */
void Board::movePiece(RenderWindow& window, Player* player)
{
    int pos      = player->getPosition();
    Piece* piece = player->getPiece();

    switch (pos)
    {
        //last line
        case 0:
            piece->move(Vector2f(730, 730));
            break;
        case 1:
            piece->move(Vector2f(660, 730));
            break;
        case 2:
            piece->move(Vector2f(590, 730));
            break;
        case 3:
            piece->move(Vector2f(520, 730));
            break;
        case 4:
            piece->move(Vector2f(460, 730));
            break;
        case 5:
            piece->move(Vector2f(400, 730));
            break;
        case 6:
            piece->move(Vector2f(330, 730));
            break;
        case 7:
            piece->move(Vector2f(270, 730));
            break;
        case 8:
            piece->move(Vector2f(205, 730));
            break;
        case 9:
            piece->move(Vector2f(140, 730));
            break;
        case 10:
            if (player->isInJail())
                piece->move(Vector2f(60, 730));
            else    
                piece->move(Vector2f(15, 760));
            break;

        //first row
        case 11:
            piece->move(Vector2f(40, 660));
            break;
        case 12:
            piece->move(Vector2f(40, 600));
            break;
        case 13:
            piece->move(Vector2f(40, 530));
            break;
        case 14:
            piece->move(Vector2f(40, 465));
            break;
        case 15:
            piece->move(Vector2f(40, 400));
            break;
        case 16:
            piece->move(Vector2f(40, 340));
            break;
        case 17:
            piece->move(Vector2f(40, 270));
            break;
        case 18:
            piece->move(Vector2f(40, 210));
            break;
        case 19:
            piece->move(Vector2f(40, 145));
            break;
        case 20:
            piece->move(Vector2f(40, 60));
            break;

        //first line
        case 21:
            piece->move(Vector2f(130, 60));
            break;
        case 22:
            piece->move(Vector2f(200, 60));
            break;
        case 23:
            piece->move(Vector2f(260, 60));
            break;
        case 24:
            piece->move(Vector2f(330, 60));
            break;
        case 25:
            piece->move(Vector2f(390, 60));
            break;
        case 26:
            piece->move(Vector2f(455, 60));
            break;
        case 27:
            piece->move(Vector2f(520, 60));
            break;
        case 28:
            piece->move(Vector2f(580, 60));
            break;
        case 29:
            piece->move(Vector2f(650, 60));
            break;
        case 30:
            piece->move(Vector2f(750, 60));
            break;

        //last row
        case 31:
            piece->move(Vector2f(750, 60));
            break;
        case 32:
            piece->move(Vector2f(750, 145));
            break;
        case 33:
            piece->move(Vector2f(750, 210));
            break;
        case 34:
            piece->move(Vector2f(750, 270));
            break;
        case 35:
            piece->move(Vector2f(750, 340));
            break;
        case 36:
            piece->move(Vector2f(750, 400));
            break;
        case 37:
            piece->move(Vector2f(750, 465));
            break;
        case 38:
            piece->move(Vector2f(750, 530));
            break;
        case 39:
            piece->move(Vector2f(750, 660));
            break;

        default:
            cout << "Piece not at the right place" << endl;
    }
}

/**
 * Default destructor
 */
Board::~Board()
{
}
