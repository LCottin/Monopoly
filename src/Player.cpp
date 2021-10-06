#include "Player.hpp"

/**
 * Default constructor
 */
Player::Player(const string name)
{
    _Pseudo = name;
    _Money  = 2000;
    _Alive  = true;

    string answer;
    TYPES type;

    //sets player's piece
    cout << "Barrow     = 1" << endl;
    cout << "Baseball   = 2" << endl;
    cout << "Car        = 3" << endl;
    cout << "Dog        = 4" << endl;
    cout << "Dragon     = 5" << endl;
    cout << "Hat        = 6" << endl;
    cout << "Pretzel    = 7" << endl;
    cout << "Ship       = 8" << endl;
    cout << "Soccer     = 9" << endl;
    cout << "Surfer     = 10" << endl;
    cout << "Thimble    = 11" << endl;
    cout << "Which piece do you want to play ? ";
    getline(cin, answer);

    switch (atoi(answer.c_str()))
    {
        case 1:
            type = BARROW;
            break;

        case 2:
            type = BASEBALL;
            break;

        case 3:
            type = CAR;
            break;

        case 4:
            type = DOG;
            break;

        case 5:
            type = DRAGON;
            break;

        case 6:
            type = HAT;
            break;

        case 7:
            type = PRETZEL;
            break;

        case 8:
            type = SHIP;
            break;

        case 9:
            type = SOCCER;
            break;

        case 10:
            type = SURFER;
            break;
        
        default:
            type = THIMBLE;
            break;
    }
    _Piece = new Piece(type);
}

Player::Player(const string name, const TYPES piece)
{
    _Pseudo = name;
    _Money  = 2000;
    _Alive  = true;

    _Piece = new Piece(piece);
}

/**
 * Tells the player's pseudo
 * @returns Player's pseudo
 */
string Player::getName() const
{
    return _Pseudo;
}

/**
 * Gets the player's piece
 * @returns A pointer to the piece
 */
Piece* Player::getPiece() const
{
    return _Piece;
}

/**
 * Shows the player's money
 * @returns Player's current amout of money
 */
int Player::getMoney() const
{
    return _Money;
}

/**
 * Tells if the payer is still alive
 * @returns True if he's alive, else false
 */
bool Player::getStatus() const
{
    return _Alive;
}

/**
 * Default destructor
 */
Player::~Player()
{
    delete _Piece;
}
