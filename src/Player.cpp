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
 * @brief Constructor for Player
 * @param name Player's name
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

/**
 * @brief Constructs a new Player object
 * @param name Player's name
 * @param piece Player's piece
 */
Player::Player(const string name, const TYPES piece)
{
    _Pseudo     = name;
    _Money      = 2000;
    _Alive      = true;
    _Position   = GO;

    _Piece = new Piece(piece);
}

/**
 * @brief Gets the pseudo of the player
 * @returns Player's pseudo
 */
string Player::getName() const
{
    return _Pseudo;
}

/**
 * @brief Gets the player's piece
 * @returns A pointer to the piece
 */
Piece* Player::getPiece() const
{
    return _Piece;
}

/**
 * @brief Shows the player's money
 * @returns Player's current amout of money
 */
int Player::getMoney() const
{
    return _Money;
}

/**
 * @brief Shows the player's position
 * @returns Player's current position
 */
int Player::getPosition() const
{
    return _Position;
}

/**
 * @brief Tells if the player is in jail
 * @returns true if it is, else false
 */
bool Player::isInJail() const
{
    return _InJail;
}

/**
 * @brief Tells if the payer is still alive
 * @returns True if he's alive, else false
 */
bool Player::getStatus() const
{
    return _Alive;
}

/**
 * @brief Each time a player passes go, it receives $200 from the bank
 * @param bank Bank of the game
 */
void Player::go(Bank* bank)
{
    bank->output(200);
    _Money += 200;
}

/**
 * @brief Moves the player on the board
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
 * @brief Returns the number of houses the player owns
 * @returns Number of houses
 */
int Player::getPropertyCount() const
{
    return (int)_Properties.size();
}

/**
 * @brief Moves the player on the board
 * @param pos New position on the board
 * @returns true if the player comes across go, else false
 */
bool Player::move(const int pos)
{
    int newPos = (pos < 40) ? pos : pos % 40;
    
    if (newPos < _Position)
    {
        _Position = newPos;
        return true;
    }

    _Position = newPos;
    return false;
}

/**
 * @brief Rolls both dices and prints the animation on the screen
 * @returns Array with two numbers
 */
int* Player::rollDices(Dice* d1, Dice* d2)
{
    _Rolls[0] = d1->roll();
    _Rolls[1] = d2->roll();
    return _Rolls;
}

/**
 * @brief Sets the player's situation
 * @param inJail True if the player is in jail, else false
 */
void Player::setInJail(const bool inJail)
{
    _InJail = inJail;
}

/**
 * @brief The player pays the bank for the amount he has to pay
 * @param bank Bank of the game
 * @param amount Amount to pay
 * @returns True if the player has enough money, else false
 */
bool Player::payBank(Bank* bank, const int amount)
{
    bank->input(amount);
    return removeMoney(amount);
}

/**
 * @brief Buys a property
 * @param house House to buy
 * @returns true if the player can buy the property, else false
 */
bool Player::buy(House* house)
{
    if (_Money >= house->getPrice())
    {
        _Money -= house->getPrice();
        _Properties.push_back(house);
        house->setOwner(this);
        house->setSold(true);
        cout << "You bought " << house->getName() << " for " << house->getPrice() << " dollars." << endl;
        cout << "You have " << _Money << " dollars left." << endl;
        return true;
    }
    else 
        cout << "You don't have enough money to buy this property" << endl;
    return false;
}

/**
 * @brief Sells a property
 * @param house House to sell
 * @returns true if the player can sell the property, else false
 */
bool Player::sell(House* house)
{
    if (find(_Properties.begin(), _Properties.end(), house) != _Properties.end())
    {
        _Money += house->getPrice() / 2;
        _Properties.erase(find(_Properties.begin(), _Properties.end(), house));
        house->setOwner(NULL);
        house->setSold(false);
        cout << "You sold " << house->getName() << " for " << house->getPrice() / 2 << " dollars." << endl;
        return true;
    }
    else
        cout << "You don't own this property" << endl;
    return false;
}

/**
 * @brief Adds money to player's account
 * @param amount Amount to add 
 */
void Player::addMoney(const int amount)
{
    _Money += amount;
}

/**
 * @brief Removes money to player's account
 * @param amount Amount to remove 
 * @returns true if the player has enough money, else false
 */
bool Player::removeMoney(const int amount)
{
    _Money -= amount;
    if (_Money < 0)
    {
        _Alive = false;
        cout << "You are bankrupt!" << endl;
        return false;
    }
    return true;
}

/**
 * @brief Pays the rent to the owner of the property
 * @param player Player who owns the property
 * @param rent Rent to pay 
 * @returns true if the player has enough money, else false
 */
bool Player::payRent(Player* player, const int rent)
{
    player->addMoney(rent);
    return removeMoney(rent);
}

/**
 * Default destructor
 */
Player::~Player()
{
    delete _Piece;
}
