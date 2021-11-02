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

    //Creates two artificial cards
    Chances ch;
    Communities com;

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
        window.draw(*ch.getFocusSprite());
        window.draw(*com.getFocusSprite());
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
    window.draw(*ch.getFocusSprite());
    window.draw(*com.getFocusSprite());
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
    //refreshes screen before adding other things
    drawBoard(window, true, false);
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
            piece->move(Vector2f(638, 730));
            break;
        case 2:
            piece->move(Vector2f(575, 730));
            break;
        case 3:
            piece->move(Vector2f(510, 730));
            break;
        case 4:
            piece->move(Vector2f(445, 730));
            break;
        case 5:
            piece->move(Vector2f(380, 730));
            break;
        case 6:
            piece->move(Vector2f(317, 730));
            break;
        case 7:
            piece->move(Vector2f(252, 730));
            break;
        case 8:
            piece->move(Vector2f(187, 730));
            break;
        case 9:
            piece->move(Vector2f(122, 730));
            break;
        case 10:
            if (player->isInJail())
                piece->move(Vector2f(50, 700));
            else    
                piece->move(Vector2f(0, 740));
            break;

        //first row
        case 11:
            piece->move(Vector2f(10, 635));
            break;
        case 12:
            piece->move(Vector2f(10, 572));
            break;
        case 13:
            piece->move(Vector2f(10, 505));
            break;
        case 14:
            piece->move(Vector2f(10, 440));
            break;
        case 15:
            piece->move(Vector2f(30, 375));
            break;
        case 16:
            piece->move(Vector2f(10, 310));
            break;
        case 17:
            piece->move(Vector2f(38, 245));
            break;
        case 18:
            piece->move(Vector2f(10, 180));
            break;
        case 19:
            piece->move(Vector2f(10, 115));
            break;
        case 20:
            piece->move(Vector2f(40, 30));
            break;

        //first line
        //TODO: continuer à partir d'ici
        case 21:
            piece->move(Vector2f(122, 15));
            break;
        case 22:
            piece->move(Vector2f(187, 15));
            break;
        case 23:
            piece->move(Vector2f(252, 15));
            break;
        case 24:
            piece->move(Vector2f(317, 15));
            break;
        case 25:
            piece->move(Vector2f(380, 15));
            break;
        case 26:
            piece->move(Vector2f(445, 15));
            break;
        case 27:
            piece->move(Vector2f(510, 15));
            break;
        case 28:
            piece->move(Vector2f(575, 15));
            break;
        case 29:
            piece->move(Vector2f(638, 15));
            break;
        case 30:
            piece->move(Vector2f(730, 15));
            break;

        //last row
        case 31:
            piece->move(Vector2f(730, 112));
            break;
        case 32:
            piece->move(Vector2f(730, 180));
            break;
        case 33:
            piece->move(Vector2f(730, 245));
            break;
        case 34:
            piece->move(Vector2f(730, 310));
            break;
        case 35:
            piece->move(Vector2f(730, 375));
            break;
        case 36:
            piece->move(Vector2f(730, 440));
            break;
        case 37:
            piece->move(Vector2f(730, 505));
            break;
        case 38:
            piece->move(Vector2f(730, 572));
            break;
        case 39:
            piece->move(Vector2f(730, 635));
            break;

        default:
            cout << "Piece not at the right place" << endl;
    }
}

/**
 * Draws the board and the cards on it
 * @param window Window to draw on
 */
void Board::drawBoard(RenderWindow& window, bool clear, bool display)
{
    Chances ch;
    Communities com;

    if (clear)
        window.clear();
    window.draw(_Sprite);
    window.draw(*ch.getMainSprite());
    window.draw(*com.getMainSprite());
    if (display)
        window.display();
}

/**
 * Default destructor
 */
Board::~Board()
{
}
