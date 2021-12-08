#include "Game.hpp"

/**
 * @brief Construct a new Game object
 */
Game::Game()
{
    _Window.create(VideoMode(800, 800), "Monopoly game !");
    _Window.setFramerateLimit(10);

    _NbPlayers      = -1;
    _CurrentTurn    = 0;
    _TotalTurns     = 0;

    _Dice1          = new Dice();
    _Dice2          = new Dice();
    _Board          = new Board();
    _Bank           = new Bank();
    _Chances        = new Chances();
    _Communities    = new Communities();

    // Initialize the houses
    House* h = new House(MEDITERRANEAN_AVENUE, "Mediterranean Avenue", 60, 10);
    _Houses.push_back(h);
    House* h2 = new House(BALTIC_AVENUE, "Baltic Avenue", 60, 20);
    _Houses.push_back(h2);
    House* h3 = new House(READING_RAILROAD, "Reading Railroad", 200, 25);
    _Houses.push_back(h3);
    House* h4 = new House(ORIENTAL_AVENUE, "Oriental Avenue", 100, 30);
    _Houses.push_back(h4);
    House* h5 = new House(VERMONT_AVENUE, "Vermont Avenue", 100, 30);
    _Houses.push_back(h5);
    House* h6 = new House(CONNECTICUT_AVENUE, "Connecticut Avenue", 120, 40);
    _Houses.push_back(h6);

    House* h7 = new House(ST_CHARLES_PLACE, "St. Charles Place", 140, 50);
    _Houses.push_back(h7);
    House* h8 = new House(ELECTRIC_COMPANY, "Electric Company", 150, 0);
    _Houses.push_back(h8);
    House* h9 = new House(STATES_AVENUE, "States Avenue", 140, 50);
    _Houses.push_back(h9);
    House* h10 = new House(VIRGINIA_AVENUE, "Virginia Avenue", 160, 60);
    _Houses.push_back(h10);
    House* h11 = new House(PENNSYLVANIA_RAILROAD, "Pennsylvania Railroad", 200, 25);
    _Houses.push_back(h11);
    House* h12 = new House(ST_JAMES_PLACE, "St. James Place", 180, 70);
    _Houses.push_back(h12);
    House* h13 = new House(TENNESSEE_AVENUE, "Tennessee Avenue", 180, 70);
    _Houses.push_back(h13);
    House* h14 = new House(NEW_YORK_AVENUE, "New York Avenue", 200, 80);
    _Houses.push_back(h14);

    House* h15 = new House(KENTUCKY_AVENUE, "Kentucky Avenue", 220, 90);
    _Houses.push_back(h15);
    House* h16 = new House(INDIANA_AVENUE, "Indiana Avenue", 220, 90);
    _Houses.push_back(h16);
    House* h17 = new House(ILLINOIS_AVENUE, "Illinois Avenue", 240, 100);
    _Houses.push_back(h17);
    House* h18 = new House(B_AND_O_RAILROAD, "B. & O. Railroad", 200, 25);
    _Houses.push_back(h18);
    House* h19 = new House(ATLANTIC_AVENUE, "Atlantic Avenue", 260, 110);
    _Houses.push_back(h19);
    House* h20 = new House(VENTNOR_AVENUE, "Ventnor Avenue", 260, 110);
    _Houses.push_back(h20);
    House* h21 = new House(WATER_WORKS, "Water Works", 150, 0);
    _Houses.push_back(h21);
    House* h22 = new House(MARVIN_GARDENS, "Marvin Gardens", 280, 120);
    _Houses.push_back(h22);

    House* h23 = new House(PACIFIC_AVENUE, "Pacific Avenue", 300, 130);
    _Houses.push_back(h23);
    House* h24 = new House(NORTH_CAROLINA_AVENUE, "North Carolina Avenue", 300, 130);
    _Houses.push_back(h24);
    House* h25 = new House(PENNSYLVANIA_AVENUE, "Pennsylvania Avenue", 320, 150);
    _Houses.push_back(h25);
    House* h26 = new House(SHORT_LINE_RAILROAD, "Short Line Railroad", 200, 25);
    _Houses.push_back(h26);
    House* h27 = new House(PARK_PLACE, "Park Place", 350, 175);
    _Houses.push_back(h27);
    House* h28 = new House(BOARDWALK, "Boardwalk", 400, 200);
    _Houses.push_back(h28);
}

/**
 * @brief Tells how many players will plays the game
 */
void Game::getNbPlayers()
{    
    cout << "How many players will play ? " << endl;
    do
    {
        cout << "Enter a number between 2 and 4 included. " << endl;
        cout << "Number = ";
        string answer;
        getline(cin, answer);
        _NbPlayers = stoi(answer);
    } while (_NbPlayers < 2 || _NbPlayers > 4);
    
    //creates all players
    for (size_t i = 0; i < _NbPlayers; i++)
    {
        string name = "none";
        do
        {
            cout << "Player " << i + 1 << ", what's your name ?" << endl;
            cout << "Name : ";
            getline(cin, name);
        } while(name == "none" || name == "");

        Player* pl = new Player(name);
        _Players.push_back(pl);
    }
    cout << "Let the game begin ! " << endl;
}

/**
 * @brief Main function, plays the game
 */
bool Game::playGame()
{
    getNbPlayers();

    while (_Window.isOpen())
    {
        _TotalTurns++;
        if (_TotalTurns == 2) 
            return true;
        _CurrentTurn    = (_CurrentTurn + 1) % _NbPlayers;
        _CurrentPlayer  = _Players[_CurrentTurn];

        Event event;

        while (_Window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                _Window.close();
                return false;
            }
        } 

        sleep(milliseconds(1000));

        _Board->drawBoard(_Window);
        _Board->drawPieces(_Window, _Players);

        //TODO: implements prison before next turn
        /* =========================== */
        /* STEP 1 : player rolls dices */
        /* =========================== */
        //FIXME: implements three doubles in a row to go to prison 
        int* rolls = _CurrentPlayer->rollDices(_Dice1, _Dice2);

        /* ===================================== */
        /* STEP 2 : prints rolling on the screen */
        /* ===================================== */
        _Board->drawRolls(_Window, rolls);

        /* =========================== */
        /* STEP 3 : player moves piece */
        /* =========================== */
        bool go = _CurrentPlayer->move();
        if (go)
            _CurrentPlayer->go(_Bank);

        /* ====================================== */
        /* STEP 4 : updates position on the board */
        /* ====================================== */
        _Board->drawPieces(_Window, _Players);

        /* =========================================== */
        /* STEP 5 : player acts according to the place */
        /* =========================================== */

        // Checks if the player should go to jail
        if (_CurrentPlayer->getPosition() == GO_TO_JAIL)
        {
            _CurrentPlayer->setInJail(true);
            _CurrentPlayer->move(JAIL);
            _Board->drawPieces(_Window, _Players);
            continue;
        }

        // Checks if the player is on LUXURY_TAX
        if (_CurrentPlayer->getPosition() == LUXURY_TAX)
        {
            if (!_CurrentPlayer->payBank(_Bank, 75))
            {
                cout << "You don't have enough money to pay the tax. You lose." << endl;
                cout << "You are eliminated from the game." << endl;
                    _Players.erase(_Players.begin() + _CurrentTurn);
                    _NbPlayers--;

                    if (_NbPlayers == 1)
                    {
                        cout << "The winner is " << _Players[0]->getName() << " !" << endl;
                        return true;
                    }
            }
            _Board->drawPieces(_Window, _Players);
            continue;
        }

        // Checks if the player is on INCOME_TAX
        if (_CurrentPlayer->getPosition() == INCOME_TAX)
        {
            cout << "You have to choose to pay 200 or 10% of your total worth." << endl;
            cout << "1. Pay 200" << endl;
            cout << "2. Pay 10% of your total worth" << endl;
            cout << "Your choice : ";
            bool ok = false;
            int choice;
            do
            {   choice = -1;
                string answer;
                getline(cin, answer);
                choice = stoi(answer);
                if (choice == 1)
                {
                    cout << "You pay 200." << endl;
                    ok = _CurrentPlayer->payBank(_Bank, 200);
                }
                else if (choice == 2)
                {
                    int assets = _CurrentPlayer->getAssets();
                    cout << "Your total worth is " << assets << endl;
                    cout << "You have to pay " << assets * 0.1 << endl;
                    ok = _CurrentPlayer->payBank(_Bank, assets * 0.1);
                }
            } while (choice != 1 && choice != 2);
            
            //if the players couldn't pay the tax, he is eliminated from the game
            if (ok == false)
            {
                cout << "You don't have enough money to pay the tax. You lose." << endl;
                cout << "You are eliminated from the game." << endl;
                _Players.erase(_Players.begin() + _CurrentTurn);
                _NbPlayers--;

                if (_NbPlayers == 1)
                {
                    cout << "The winner is " << _Players[0]->getName() << " !" << endl;
                    return true;
                }
            }

            _Board->drawPieces(_Window, _Players);
            continue;
        }

        // Checks if the player is paying a visit to the prison
        if (_CurrentPlayer->getPosition() == JAIL)
        {
            cout << "You are visiting the prison." << endl;
            continue;
        }

        // Checks if the player is on FREE_PARKING
        if (_CurrentPlayer->getPosition() == FREE_PARKING)
        {
            cout << "You are resting on free parking." << endl;
            continue;
        }

        // Checks if the player is on COMMUNITY_CHEST
        if (_CurrentPlayer->getPosition() == COMMUNITY_CHEST_1 || _CurrentPlayer->getPosition() == COMMUNITY_CHEST_2 || _CurrentPlayer->getPosition() == COMMUNITY_CHEST_3)
        {
            _Board->drawCard(_Window, _Communities->drawCard(), false);
            _Communities->execute(_Bank, _CurrentPlayer, _Players);
            sleep(milliseconds(3000));
            _Board->drawPieces(_Window, _Players);
            continue;
        }

        // Checks if the player is on CHANCE_CARD
        if (_CurrentPlayer->getPosition() == CHANCE_1 || _CurrentPlayer->getPosition() == CHANCE_2 || _CurrentPlayer->getPosition() == CHANCE_3)
        {
            _Board->drawCard(_Window, _Chances->drawCard(), false);
            _Chances->execute(_Bank, _CurrentPlayer, _Players);
            sleep(milliseconds(3000));
            _Board->drawPieces(_Window, _Players);
            continue;
        }

        House* currentHouse = getHouse((PLACES)_CurrentPlayer->getPosition());

        // makes sure the player is on a house
        if (currentHouse == nullptr)    
        {
            cout << "Couldn't find the house. End of game" << endl;
            return false;
        }

        // if the player is on an non-sold house, he can buy it
        if (currentHouse->getOwner() == nullptr)
        {
            cout << "No owner." << endl;
            cout << "You currently have " << _CurrentPlayer->getMoney() << " dollars." << endl;
            cout << "Do you want to buy this house ? (y/n)" << endl;
            string answer;
            getline(cin, answer);
            if (answer == "y" || answer == "Y")
            {
                if (!_CurrentPlayer->buy(currentHouse))
                    cout << "You can't buy this house." << endl;
            }
        }

        // if the player is on a house already bought
        else
        {
            // if the player is the owner of the house, he can sell
            if (currentHouse->getOwner() == _CurrentPlayer)
            {
                cout << "You are at home, you already own this house" << endl;
                cout << "You currently have " << _CurrentPlayer->getMoney() << " dollars." << endl;
                cout << "Do you want to sell this house ? (y/n)" << endl;
                string answer;
                getline(cin, answer);
                if (answer == "y" || answer == "Y")
                {
                    _CurrentPlayer->sell(currentHouse);
                }
            }

            // if the player is not the owner, he has to pay rent
            else
            {
                bool ok;

                // If the player is on WATER_WORKS or ELECTRIC_COMPANY
                if (_CurrentPlayer->getPosition() == WATER_WORKS || _CurrentPlayer->getPosition() == ELECTRIC_COMPANY)
                {
                    Player* waterWorksOwner      = getHouse(WATER_WORKS)->getOwner();
                    Player* electricCompanyOwner = getHouse(ELECTRIC_COMPANY)->getOwner();

                    int amount = rolls[0] + rolls[1];
                    if (waterWorksOwner == electricCompanyOwner)
                        amount *= 10;
                    else 
                        amount *= 4;
                    
                    if (_CurrentPlayer->getPosition() == WATER_WORKS)
                        ok = _CurrentPlayer->payRent(waterWorksOwner, amount);
                    
                    else 
                        ok = _CurrentPlayer->payRent(electricCompanyOwner, amount);
                }

                // If the player is on a normal house
                else
                    ok = _CurrentPlayer->payRent(currentHouse->getOwner(), currentHouse->getRent());
                
                // Makes sure the player has enough money to pay the rent
                if (!ok)
                {
                    cout << "You don't have enough money to pay the rent." << endl;
                    cout << "You are eliminated from the game." << endl;
                    _Players.erase(_Players.begin() + _CurrentTurn);
                    _NbPlayers--;

                    if (_NbPlayers == 1)
                    {
                        cout << "The winner is " << _Players[0]->getName() << " !" << endl;
                        return true;
                    }
                }
            }
        }
        //uncomments to run one turn 
        //return true;
    }
    return true;
}

/**
 * @brief Gets the house
 * @param place Place of the house
 * @returns The house
 */
House* Game::getHouse(PLACES place)
{
    for (size_t i = 0; i < _Houses.size(); i++)
    {
        if (_Houses[i]->getPlace() == place)
            return _Houses[i];
    }
    return nullptr;
}

/**
 * @brief Gets the house
 * @param name Name of the house
 * @returns The house
 */
House* Game::getHouse(string name)
{
    for (size_t i = 0; i < _Houses.size(); i++)
    {
        if (_Houses[i]->getName() == name)
            return _Houses[i];
    }
    return nullptr;
}

/**
 * Default destructor
 */
Game::~Game()
{
    for (size_t i = 0; i < _Players.size(); i++)
    {
        delete _Players[i];
    }
    for (size_t i = 0; i < _Houses.size(); i++)
    {
        delete _Houses[i];
    }
    delete _Dice1;
    delete _Dice2;
    delete _Board;
    delete _Bank;
    delete _Chances;
    delete _Communities;
}