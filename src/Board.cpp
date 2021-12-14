#include "Board.hpp"

/**
 * Default constructor
 */
Board::Board(RenderWindow* window, int* currentTurn)
{
    _Texture.loadFromFile("./Images/Boards/monopoly.png");
    _FocusTexture.loadFromFile("./Images/Boards/Monopoly2.png");
    _Font.loadFromFile("./Fonts/Raleway-Regular.ttf");

    _Sprite.setTexture(_Texture);
    _FocusSprite.setTexture(_FocusTexture);

    _Window      = window;
    _CurrentTurn = currentTurn;

    _YesTextPos = Vector2f(930, 600);
    _NoTextPos  = Vector2f(935, 700);

    _YesBoxPos  = _YesTextPos - Vector2f(2, 2);
    _NoBoxPos   =  _NoTextPos - Vector2f(2, 2);

    _YesBoxSize = Vector2f(140, 50);
    _NoBoxSize  = Vector2f(130, 50);

    //Yes text
    _YesText.setFont(_Font);
    _YesText.setString("Yes / 1");
    _YesText.setCharacterSize(40);
    _YesText.setFillColor(Color::Black);
    _YesText.setPosition(_YesTextPos);
    
    //Yes box
    _YesBox.setSize(_YesBoxSize);
    _YesBox.setFillColor(Color::Transparent);
    _YesBox.setOutlineColor(Color::Black);
    _YesBox.setOutlineThickness(5);
    _YesBox.setPosition(_YesBoxPos);
    
    //No text
    _NoText.setFont(_Font);
    _NoText.setString("No / 2");
    _NoText.setCharacterSize(40);
    _NoText.setFillColor(Color::Black);
    _NoText.setPosition(_NoTextPos);
    
    //No box
    _NoBox.setSize(_NoBoxSize);
    _NoBox.setFillColor(Color::Transparent);
    _NoBox.setOutlineColor(Color::Black);
    _NoBox.setOutlineThickness(5);
    _NoBox.setPosition(_NoBoxPos);
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
void Board::drawRolls(const int* rolls)
{
    //creates two artifial dices
    Dice* d1 = new Dice();
    Dice* d2 = new Dice();

    //sets the position of the dices
    d1->setPosition(Vector2f(50, 250));
    d2->setPosition(Vector2f(450, 250));

    //Creates two artificial cards
    Chances ch;
    Communities com;

    //1 : rolls dices to animate screen
    for (size_t i = 0; i < 20; i++)
    {
        //2 : changes framerate 
        _Window->setFramerateLimit(20 - i);
        
        d1->roll();
        d2->roll();

        drawBoard(true, false);
        _Window->draw(_FocusSprite);
        _Window->draw(*ch.getFocusSprite());
        _Window->draw(*com.getFocusSprite());
        _Window->draw(*d1->getSprite());
        _Window->draw(*d2->getSprite());
        _Window->display();

        //sleeps to slow down 
        sleep(milliseconds(100));
    }
    //3 : sets back framerate
    _Window->setFramerateLimit(10);

    //4 : prints real numbers 
    d1->setPosition(Vector2f(50, 250));
    d2->setPosition(Vector2f(450, 250));

    drawBoard(true, false);
    _Window->draw(_FocusSprite);
    _Window->draw(*ch.getFocusSprite());
    _Window->draw(*com.getFocusSprite());
    _Window->draw(*d1->getSprite(rolls[0]));
    _Window->draw(*d2->getSprite(rolls[1]));
    _Window->display();

    //sleeps for three seconds
    sleep(seconds(2));

    delete d1;
    delete d2;
}

/**
 * Prints each player's piece on the board
 * @param window Window to update
 * @param players Vector containing every player
 */
void Board::drawPieces(vector<Player*> players)
{
    //refreshes screen before adding other things
    drawBoard(true, false);
    //prints each player's piece on the board
    for (size_t i = 0; i < players.size(); i++)
    {
        //moves the piece ...
        movePiece(players[i]);

        //...then displays it
        _Window->draw(*players[i]->getPiece()->getSprite());
    }
    _Window->display();
    sleep(seconds(1));
}

/**
 * Prints one piece on the board after being tested
 * @param window Window to update
 * @param player Player owning the piece
 */
void Board::movePiece(Player* player)
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
void Board::drawBoard(const bool clear, const bool display)
{
    Chances ch;
    Communities com;

    if (clear)
        _Window->clear(Color::White);
    _Window->draw(_Sprite);
    _Window->draw(*ch.getMainSprite());
    _Window->draw(*com.getMainSprite());
    _Window->draw(_YesBox);
    _Window->draw(_NoBox);
    _Window->draw(_YesText);
    _Window->draw(_NoText);

    // Draws the turn
    drawText(Vector2f(820, 50), "Turn : ", Color::Black, 40, false, false);
    drawText(Vector2f(970, 50), to_string(*_CurrentTurn), Color::Blue, 40, false, false);
    
    // Draw info about the player
    drawText(Vector2f(820, 130), "Player : ", Color::Black, 40, false, false);
    drawText(Vector2f(970, 130), _CurrentPlayer->getName(), Color::Blue, 40, false, false);
    drawText(Vector2f(820, 210), "Money : ", Color::Black, 40, false, false);
    drawText(Vector2f(970, 210), to_string(_CurrentPlayer->getMoney()) + " $", Color::Blue, 40, false, false);

    if (display)
        _Window->display();
}

/**
 * @brief Sets current player
 * @param player Player to set
 */
void Board::setCurrentPlayer(Player *player)
{
    _CurrentPlayer = player;
}

/**
 * @brief Indicates which box the player clicked on
 * @param window Window to draw on
 * @returns The box the player clicked on
 */
BOXES Board::boxClicked()
{
    Event event;
    while(true)
    {
        while (_Window->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                _Window->close();
                return EXIT;
            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    //Returns the box the player clicked on
                    Vector2i mousPos = Mouse::getPosition(*_Window);
                    if (mousPos.x >= _YesBoxPos.x && mousPos.x <= _YesBoxPos.x + _YesBoxSize.x &&
                        mousPos.y >= _YesBoxPos.y && mousPos.y <= _YesBoxPos.y + _YesBoxSize.y)
                        return YES;
                    else if (mousPos.x >= _NoBoxPos.x && mousPos.x <= _NoBoxPos.x + _NoBoxSize.x &&
                            mousPos.y >= _NoBoxPos.y && mousPos.y <= _NoBoxPos.y + _NoBoxSize.y)
                        return NO;
                }
            }
        }
    }
}

/**
 * Draws the board and the cards on it
 * @param window Window to draw on
 * @param sprite Sprite to draw
 */
void Board::drawCard(const Sprite* sprite, const bool clear, const bool display)
{
    drawBoard(clear, false);
    _Window->draw(*sprite);
    if (display)
        _Window->display();
    sleep(milliseconds(1000));
}

/**
 * @brief Draws some text on the board
 * @param window Window to draw on
 * @param text Text to draw
 */
void Board::drawText(const Vector2f pos, const string text, const Color color, const int size, const bool clear, const bool display)
{
    Text textToDraw(text, _Font, size);
    textToDraw.setFillColor(color);
    textToDraw.setPosition(pos);

    if (clear)
    {
        Chances ch;
        Communities com;

        _Window->clear(Color::White);
        _Window->draw(_Sprite);
        _Window->draw(*ch.getMainSprite());
        _Window->draw(*com.getMainSprite());
        _Window->draw(_YesBox);
        _Window->draw(_NoBox);
        _Window->draw(_YesText);
        _Window->draw(_NoText);

        //drawPieces();

        // Draws the turn
        drawText(Vector2f(820, 50), "Turn : ", Color::Black, 40, false, false);
        drawText(Vector2f(970, 50), to_string(*_CurrentTurn), Color::Blue, 40, false, false);
        
        // Draw info about the player
        drawText(Vector2f(820, 130), "Player : ", Color::Black, 40, false, false);
        drawText(Vector2f(970, 130), _CurrentPlayer->getName(), Color::Blue, 40, false, false);
        drawText(Vector2f(820, 210), "Money : ", Color::Black, 40, false, false);
        drawText(Vector2f(970, 210), to_string(_CurrentPlayer->getMoney()) + " $", Color::Blue, 40, false, false);
    }

    _Window->draw(textToDraw);
    if (display)
        _Window->display();
}

/**
 * Default destructor
 */
Board::~Board()
{
}
