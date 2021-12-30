#include "Game.hpp"

/**
 * @brief Construct a new Game object
 */
Game::Game()
{
    _Window.create(VideoMode(1200, 800), "Monopoly game !");
    _Window.setFramerateLimit(10);

    _NbPlayers      = -1;
    _CurrentTurn    = 0;
    _TotalTurns     = 0;

    _Dice1          = new Dice();
    _Dice2          = new Dice();
    _Board          = new Board(&_Window, &_Players, &_TotalTurns);
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

        Player* pl = new Player(name, _Bank);
        _Players.push_back(pl);
    }
    cout << "Let the game begin ! " << endl;
}

/**
 * @brief Main function, plays the game
 */
bool Game::playGame()
{
    printf("\e[1;1H\e[2J");
    getNbPlayers();

    while (_Window.isOpen())
    {
        printf("\e[1;1H\e[2J");
        _CurrentPlayer  = _Players[_CurrentTurn];
        _CurrentTurn    = (_CurrentTurn + 1) % _NbPlayers;
        _TotalTurns++;

        Event event;
        bool replay = false;
        int doubles = 0;
        int* rolls  = nullptr;

        replay: //replayes the turn if the player made a double 
        
        while (_Window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                _Window.close();
                return false;
            }
        } 

        _Board->setCurrentPlayer(_CurrentPlayer);
        _Board->drawBoard();
        _Board->drawText(Vector2f(810, 300), "Next Player !", Color::Red);
        sleep(milliseconds(1000));
    
        if (_CurrentPlayer->isInJail())
        {
            _Board->drawText(Vector2f(810, 300), "You are in jail !", Color::Red);

            if (_CurrentPlayer->hasFreeCard())
            {
                _Board->drawText(Vector2f(810, 350), "You have a free card.\nUse it ?", Color::Blue);
                BOXES box = _Board->boxClicked();
                if (box == YES)
                {
                    _CurrentPlayer->useFreeCard();
                    _Board->drawText(Vector2f(810, 300), "You are out of jail !", Color::Red);
                    sleep(milliseconds(1000));
                    goto play;
                }
                else if (box == NO)
                {
                    _Board->drawText(Vector2f(810, 300), "You don't use \nyour free card.", Color::Red);
                    sleep(milliseconds(1000));
                }
                else if (box == EXIT)
                {
                    _Window.close();
                    return false;
                }
            }

            else
            {
                _Board->drawText(Vector2f(810, 350), "Do you want to pay\n50€ to get out ?", Color::Blue);
                BOXES box = _Board->boxClicked();
                if (box == YES)
                {
                    _CurrentPlayer->payBank(50);
                    _CurrentPlayer->setInJail(false);
                    _Board->drawText(Vector2f(810, 350), "You are now free. Play !", Color::Blue);
                    sleep(milliseconds(1000));
                    goto play;
                }
                else if (box == NO)
                {
                    _Board->drawText(Vector2f(810, 350), "You don't pay.", Color::Blue);   
                    const int* rolls2 = _CurrentPlayer->rollDices(_Dice1, _Dice2);
                    bool inJail       = _CurrentPlayer->updateTurnsInJail();
                    if ( (rolls2[0] == rolls2[1]) || (inJail == false) )
                    {
                        _CurrentPlayer->move();
                        _Board->drawText(Vector2f(810, 350), "You made a double !", Color::Red);
                        _Board->drawText(Vector2f(810, 400), "You are now free !", Color::Blue);
                        goto action;
                    }
                    else
                    {
                        _Board->drawText(Vector2f(810, 350), "You stay in prison !", Color::Blue);
                        continue;
                    }
                }
                else if (box == EXIT)
                {
                    cout << "You leave the game." << endl;
                    return true;
                }
            }
        }

        play:
        /* =========================== */
        /* STEP 1 : player rolls dices */
        /* =========================== */
        rolls = _CurrentPlayer->rollDices(_Dice1, _Dice2);

        /* ===================================== */
        /* STEP 2 : prints rolling on the screen */
        /* ===================================== */
        _Board->drawRolls(rolls);
        
        //if doubles, player replays
        replay = (rolls[0] == rolls[1]);
        if (replay)
        {
            cout << "Doubles ! You can play again at the end of your turn." << endl;
            _Board->drawText(Vector2f(810, 400), "Doubles ! You can play again \nat the end of your turn.", Color::Red);
            doubles++;
            sleep(milliseconds(1000));
            //if doubles == 2, player goes to prison
            if (doubles == 2)
            {
                cout << "Three doubles in a row : you have been sent jail ! " << endl;
                _Board->drawText(Vector2f(810, 400), "Three doubles in a row : \nyou have been sent jail ! ", Color::Red);
                _CurrentPlayer->setInJail(true);
                _CurrentPlayer->move(JAIL);
                _Board->drawBoard();
                replay = false;
                doubles = 0;
                sleep(milliseconds(1000));
                continue;
            }
        }
        else
            doubles = 0;

        /* =========================== */
        /* STEP 3 : player moves piece */
        /* =========================== */
        // bool go = _CurrentPlayer->move();
        if (_CurrentPlayer->move() == true)
            _CurrentPlayer->go();

        /* ====================================== */
        /* STEP 4 : updates position on the board */
        /* ====================================== */
        _Board->drawBoard();

        /* =========================================== */
        /* STEP 5 : player acts according to the place */
        /* =========================================== */
        action:
        const int place = _CurrentPlayer->getPosition();

        // Checks if the player should go to jail
        if (place == GO_TO_JAIL)
        {
            cout << "You have been sent to jail ! " << endl;
            _Board->drawText(Vector2f(810, 400), "You have been sent to jail ! ", Color::Red);
            _CurrentPlayer->setInJail(true);
            _CurrentPlayer->move(JAIL);
            _Board->drawBoard();
            sleep(milliseconds(1000));
            continue;
        }

        // Checks if the player is on LUXURY_TAX
        if (place == LUXURY_TAX)
        {
            if (!_CurrentPlayer->payBank(75))
            {
                cout << "You don't have enough money to pay the tax. You lose." << endl;
                cout << "You are eliminated from the game." << endl;
                _Board->drawText(Vector2f(810, 400), "You don't have enough money to pay \nthe tax. You lose.", Color::Red);
                delete _Players[_CurrentTurn];
                _Players.erase(_Players.begin() + _CurrentTurn);
                _NbPlayers--;

                if (_NbPlayers == 1)
                {
                    cout << "The winner is " << _Players[0]->getName() << " !" << endl;
                    _Board->drawText(Vector2f(810, 400), "The winner is " + _Players[0]->getName() + " !", Color::Red);
                    return true;
                }
            }
            _Board->drawBoard();
            sleep(milliseconds(1000));
            if (replay)
            {
                goto replay;
            }
            continue;
        }

        // Checks if the player is on INCOME_TAX
        if (place == INCOME_TAX)
        {
            cout << "You have to choose to pay 200 or 10% of your total worth." << endl;
            cout << "1. Pay 200" << endl;
            cout << "2. Pay 10% of your total worth" << endl;
            cout << "Your choice : ";
            _Board->drawText(Vector2f(810, 400), "You have to choose to pay 200 (1) or \n10% of your total worth (2).", Color::Red);
            sleep(milliseconds(1000));
            bool ok = false;

            BOXES box = _Board->boxClicked();
            if (box == YES)
            {
                cout << "You pay 200." << endl;
                _Board->drawText(Vector2f(810, 400), "You pay 200.", Color::Red);
                sleep(milliseconds(1000));
                ok = _CurrentPlayer->payBank(200);
            }
            else if (box == NO)
            {
                const int assets = _CurrentPlayer->getAssets();
                cout << "Your total worth is " << assets << endl;
                cout << "You have to pay " << assets / 10 << endl;
                _Board->drawText(Vector2f(810, 400), "Your total worth is " + to_string(assets) + ".\nYou have to pay " + to_string(assets / 10) + ".", Color::Red);
                ok = _CurrentPlayer->payBank(assets / 10);
                sleep(milliseconds(1000));
            }
            else if (box == EXIT)
            {
                cout << "You leave the game." << endl;
                return true;
            }
        
            //if the players couldn't pay the tax, he is eliminated from the game
            if (ok == false)
            {
                cout << "You don't have enough money to pay the tax. You lose." << endl;
                cout << "You are eliminated from the game." << endl;
                _Board->drawText(Vector2f(810, 400), "You don't have enough money to pay \nthe tax. You lose.", Color::Red);
                delete _Players[_CurrentTurn];
                _Players.erase(_Players.begin() + _CurrentTurn);
                _NbPlayers--;

                if (_NbPlayers == 1)
                {
                    cout << "The winner is " << _Players[0]->getName() << " !" << endl;
                    _Board->drawText(Vector2f(810, 400), "The winner is " + _Players[0]->getName() + " !", Color::Red);
                    return true;
                }
            }

            _Board->drawBoard();
            sleep(milliseconds(1000));
            if (replay)
            {
                goto replay;
            }
            continue;
        }

        // Checks if the player is paying a visit to the prison
        if (place == JAIL)
        {
            cout << "You are visiting the prison." << endl;
            _Board->drawText(Vector2f(810, 400), "You are visiting \nthe prison.", Color::Red);
            sleep(milliseconds(1000));
            if (replay)
            {
                goto replay;
            }
            continue;
        }

        // Checks if the player is on FREE_PARKING
        if (place == FREE_PARKING)
        {
            cout << "You are resting on free parking." << endl;
            _Board->drawText(Vector2f(810, 400), "You are resting \non free parking.", Color::Red);
            sleep(milliseconds(1000));
            if (replay)
            {
                goto replay;
            }
            continue;
        }

        // Checks if the player is on COMMUNITY_CHEST
        if (place == COMMUNITY_CHEST_1 || place == COMMUNITY_CHEST_2 || place == COMMUNITY_CHEST_3)
        {
            //TODO: Implement hotel
            _Board->drawCard(_Communities->drawCard(), false);
            _Communities->execute(_Bank, _CurrentPlayer, _Players);
            sleep(milliseconds(3000));
            _Board->drawBoard();
            if (replay)
            {
                sleep(milliseconds(1000));
                goto replay;
            }
            continue;
        }

        // Checks if the player is on CHANCE_CARD
        if (place == CHANCE_1 || place == CHANCE_2 || place == CHANCE_3)
        {
            //TODO: Implement hotel
            _Board->drawCard(_Chances->drawCard(), false);
            _Chances->execute(_Bank, _CurrentPlayer, _Players);
            sleep(milliseconds(3000));
            _Board->drawBoard();
            if (replay)
            {
                sleep(milliseconds(1000));
                goto replay;
            }
            continue;
        }

        House* currentHouse = getHouse((PLACES)place);

        // makes sure the player is on a house
        if (currentHouse == nullptr)    
        {
            cout << "Couldn't find the house. End of game" << endl;
            return false;
        }

        // if the player is on an non-sold house, he can buy it
        if (currentHouse->getOwner() == nullptr)
        {
            _Board->drawText(Vector2f(810, 450), "No owner.\nDo you want to buy it ?\nClick on the box", Color::Blue, 30);
            BOXES box = _Board->boxClicked();
            if (box == YES)
            {
                if (!_CurrentPlayer->buy(currentHouse))
                {
                    cout << "You can't buy this house." << endl;
                    _Board->drawText(Vector2f(810, 400), "You can't buy this house.", Color::Red);
                    sleep(milliseconds(1000));
                }
                else
                {
                    cout << "You bought the house." << endl;
                    _Board->drawText(Vector2f(810, 400), "You bought the house.", Color::Red);
                    sleep(milliseconds(1000));
                }
            }
            else if (box == NO)
            {
                cout << "You don't buy this house." << endl;
                _Board->drawText(Vector2f(810, 400), "You don't buy this house.", Color::Red);
                sleep(milliseconds(1000));
            }
            else if (box == EXIT)
            {
                cout << "You leave the game." << endl;
                return true;
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
                cout << "Do you want to sell this house ? Click on the box." << endl;
                _Board->drawText(Vector2f(810, 400), "You are at home, you \nalready own this house.\nDo you want to sell it ?", Color::Red);
                BOXES box = _Board->boxClicked();
                if (box == YES)
                {
                    if (!_CurrentPlayer->sell(currentHouse))
                    {    
                        cout << "You can't sell this house." << endl;
                        _Board->drawText(Vector2f(810, 400), "You can't sell this house.", Color::Red);
                        sleep(milliseconds(1000));
                    }
                    else
                    {
                        cout << "You sold the house." << endl;
                        _Board->drawText(Vector2f(810, 400), "You sold the house.", Color::Red);
                        sleep(milliseconds(1000));
                    }
                }
                else if (box == NO)
                {
                    cout << "You don't sell this house." << endl;
                    _Board->drawText(Vector2f(810, 400), "You don't sell this house.", Color::Red);
                }
                else if (box == EXIT)
                {
                    cout << "You leave the game." << endl;
                    return true;
                }
            }

            // if the player is not the owner, he has to pay rent
            else
            {
                bool ok;

                // If the player is on WATER_WORKS or ELECTRIC_COMPANY
                if (place == WATER_WORKS || place == ELECTRIC_COMPANY)
                {
                    Player* waterWorksOwner      = getHouse(WATER_WORKS)->getOwner();
                    Player* electricCompanyOwner = getHouse(ELECTRIC_COMPANY)->getOwner();

                    int amount = rolls[0] + rolls[1];
                    if (waterWorksOwner == electricCompanyOwner)
                        amount *= 10;
                    else 
                        amount *= 4;
                    
                    if (place == WATER_WORKS)
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
                    _Board->drawText(Vector2f(810, 400), "You don't have enough \nmoney to pay the rent.", Color::Red);
                    delete _Players[_CurrentTurn];
                    _Players.erase(_Players.begin() + _CurrentTurn);
                    _NbPlayers--;

                    if (_NbPlayers == 1)
                    {
                        cout << "The winner is " << _Players[0]->getName() << " !" << endl;
                        _Board->drawText(Vector2f(810, 400), "The winner is " + _Players[0]->getName() + " !", Color::Red);
                        return true;
                    }
                }
            }
        }
        _Board->drawBoard();
        sleep(milliseconds(1000));
        if (replay)
        {
            goto replay;
        }
        continue;
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