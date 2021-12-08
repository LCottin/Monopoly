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
        case GO:
            piece->move(Vector2f(730, 730));
            break;
        case MEDITERRANEAN_AVENUE:
            piece->move(Vector2f(638, 730));
            break;
        case COMMUNITY_CHEST_1:
            piece->move(Vector2f(575, 730));
            break;
        case BALTIC_AVENUE:
            piece->move(Vector2f(510, 730));
            break;
        case INCOME_TAX:
            piece->move(Vector2f(445, 730));
            break;
        case READING_RAILROAD:
            piece->move(Vector2f(380, 730));
            break;
        case ORIENTAL_AVENUE:
            piece->move(Vector2f(317, 730));
            break;
        case CHANCE_1:
            piece->move(Vector2f(252, 730));
            break;
        case VERMONT_AVENUE:
            piece->move(Vector2f(187, 730));
            break;
        case CONNECTICUT_AVENUE:
            piece->move(Vector2f(122, 730));
            break;
        case JAIL:
            if (player->isInJail())
                piece->move(Vector2f(50, 700));
            else    
                piece->move(Vector2f(0, 740));
            break;

        //first row
        case ST_CHARLES_PLACE:
            piece->move(Vector2f(10, 635));
            break;
        case ELECTRIC_COMPANY:
            piece->move(Vector2f(10, 572));
            break;
        case STATES_AVENUE:
            piece->move(Vector2f(10, 505));
            break;
        case VIRGINIA_AVENUE:
            piece->move(Vector2f(10, 440));
            break;
        case PENNSYLVANIA_RAILROAD:
            piece->move(Vector2f(30, 375));
            break;
        case ST_JAMES_PLACE:
            piece->move(Vector2f(10, 310));
            break;
        case COMMUNITY_CHEST_2:
            piece->move(Vector2f(38, 245));
            break;
        case TENNESSEE_AVENUE:
            piece->move(Vector2f(10, 180));
            break;
        case NEW_YORK_AVENUE:
            piece->move(Vector2f(10, 115));
            break;
        case FREE_PARKING:
            piece->move(Vector2f(40, 30));
            break;

        //first line
        case KENTUCKY_AVENUE:
            piece->move(Vector2f(122, 15));
            break;
        case CHANCE_2:
            piece->move(Vector2f(187, 15));
            break;
        case INDIANA_AVENUE:
            piece->move(Vector2f(252, 15));
            break;
        case ILLINOIS_AVENUE:
            piece->move(Vector2f(317, 15));
            break;
        case B_AND_O_RAILROAD:
            piece->move(Vector2f(380, 15));
            break;
        case ATLANTIC_AVENUE:
            piece->move(Vector2f(445, 15));
            break;
        case VENTNOR_AVENUE:
            piece->move(Vector2f(510, 15));
            break;
        case WATER_WORKS:
            piece->move(Vector2f(575, 15));
            break;
        case MARVIN_GARDENS:
            piece->move(Vector2f(638, 15));
            break;
        case GO_TO_JAIL:
            piece->move(Vector2f(730, 15));
            break;

        //last row
        case PACIFIC_AVENUE:
            piece->move(Vector2f(730, 112));
            break;
        case NORTH_CAROLINA_AVENUE:
            piece->move(Vector2f(730, 180));
            break;
        case COMMUNITY_CHEST_3:
            piece->move(Vector2f(730, 245));
            break;
        case PENNSYLVANIA_AVENUE:
            piece->move(Vector2f(730, 310));
            break;
        case SHORT_LINE_RAILROAD:
            piece->move(Vector2f(730, 375));
            break;
        case CHANCE_3:
            piece->move(Vector2f(730, 440));
            break;
        case PARK_PLACE:
            piece->move(Vector2f(730, 505));
            break;
        case LUXURY_TAX:
            piece->move(Vector2f(730, 572));
            break;
        case BOARDWALK:
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
void Board::drawBoard(RenderWindow& window, const bool clear, const bool display)
{
    Chances ch;
    Communities com;

    Font font;
    font.loadFromFile("Raleway-Regular.ttf");
    Text yes("YES (1)", font, 40);
    Text no("NO (2)", font, 40);
    yes.setFillColor(Color::Black);
    no.setFillColor(Color::Black);
    yes.setPosition(150, 630);
    no.setPosition(300, 630);

    if (clear)
        window.clear();
    window.draw(_Sprite);
    window.draw(*ch.getMainSprite());
    window.draw(*com.getMainSprite());
    window.draw(yes);
    window.draw(no);
    if (display)
        window.display();
    sleep(milliseconds(2000));
}

/**
 * Draws the board and the cards on it
 * @param window Window to draw on
 * @param sprite Sprite to draw
 */
void Board::drawCard(RenderWindow& window, const Sprite* sprite, const bool clear, const bool display)
{
    if (clear)
        window.clear();
    window.draw(*sprite);
    if (display)
        window.display();
}

/**
 * Default destructor
 */
Board::~Board()
{
}
