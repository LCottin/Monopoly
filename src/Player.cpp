#include "Player.hpp"

vector<int> Player::_AvailablePieces = {BARROW, 
                                        BASEBALL,
                                        CAR, 
                                        DOG, 
                                        DRAGON, 
                                        HAT,
                                        PRETZEL,
                                        SHIP, 
                                        SOCCER, 
                                        SURFER, 
                                        THIMBLE};

vector<string> Player::_AvailableNames = {"Barrow", 
                                          "Baseball",
                                          "Car", 
                                          "Dog", 
                                          "Dragon", 
                                          "Hat",
                                          "Pretzel",
                                          "Ship", 
                                          "Soccer", 
                                          "Surfer", 
                                          "Thimble"};

/**
 * Default constructor
 */
Player::Player(const string name)
{
    _Pseudo     = name;
    _Money      = 2000;
    _Alive      = true;
    _Position   = GO;

    string answer;
    TYPES type;

    cout << "Which piece do you want to play ? " << endl;

    //checks for available pieces
    do
    {
        for (size_t i = 0; i < _AvailablePieces.size(); i++)
        {
            cout << _AvailableNames[i] << " = " << _AvailablePieces[i] << endl;
        }
        cout << "Number = ";
        getline(cin, answer);
    } while(find(_AvailablePieces.begin(), _AvailablePieces.end(), stoi(answer)) == _AvailablePieces.end());

    //sets player's piece
    switch (stoi(answer))
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

    //clears vectors
    _AvailableNames.erase(_AvailableNames.begin() + stoi(answer));
    _AvailablePieces.erase(_AvailablePieces.begin() + stoi(answer));
}

Player::Player(const string name, const TYPES piece)
{
    _Pseudo     = name;
    _Money      = 2000;
    _Alive      = true;
    _Position   = GO;

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
 * Shows the player's position
 * @returns Player's current position
 */
int Player::getPosition() const
{
    return _Position;
}

/**
 * Tells if the player is in jail
 * @returns true if it is, else false
 */
bool Player::isInJail() const
{
    return _InJail;
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
 * Each time a player pass go, it receives $200 from the bank
 * @param bank Bank of the game
 */
void Player::go(Bank* bank)
{
    bank->output(200);
    _Money += 200;
}

/**
 * Moves the player on the board
 * @returns true if the player comes across go, else false
 */
bool Player::move()
{
    int newPos = (_Position + _Rolls[0] + _Rolls[1]) % 40;
    
    if (newPos < _Position)
    {
        _Position = newPos;
        return true;
    }

    _Position = newPos;
    return false;
}

/**
 * Moves the player on the board
 * @param pos New position on the board
 */
void Player::move(const int pos)
{
    _Position = pos;
}

/**
 * Rolls both dices and prints the animation on the screen
 * @returns Array with two numbers
 */
int* Player::rollDices(Dice* d1, Dice* d2)
{
    _Rolls[0] = d1->roll();
    _Rolls[1] = d2->roll();
    return _Rolls;
}

/**
 * Default destructor
 */
Player::~Player()
{
    delete _Piece;
}
