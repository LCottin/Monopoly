#include "Game.hpp"

/**
 * Default constructor
 */
Game::Game()
{
    _Window.create(VideoMode(800, 800), "Monopoly game !");
    _Window.setFramerateLimit(10);

    _NbPlayers      = -1;
    _CurrentTurn    = 0;
    _Dice1          = new Dice();
    _Dice2          = new Dice();
}

/**
 * Tells how many players will plays the game
 */
void Game::getNbPlayers()
{
    //Stores available piece so that each player has a different one
    vector<int> availableTypes;
    for (size_t i = 0; i < 11; i++)
    {
        availableTypes.push_back(i);
    }
    
    // cout << "How many players will play ? " << endl;
    // do
    // {
    //     cout << "Enter a number between 2 and 4 included. " << endl;
    //     cout << "Number = ";
    //     cin >> _NbPlayers;
    // } while (_NbPlayers < 2 || _NbPlayers > 4);
    
    // //creates all players
    // for (size_t i = 0; i < _NbPlayers; i++)
    // {
    //     //FIXME: avoid player to have the same piece by removing it from the available pieces
    //     string name = "none";
    //     do
    //     {
    //         cout << "Player " << i + 1 << ", what's your name ?" << endl;
    //         cout << "Name : ";
    //         getline(cin, name);
    //     } while(name == "none" || name == "");

    //     Player* pl = new Player(name);
    //     _Players.push_back(pl);
    // }
    Player* pl = new Player("test", BASEBALL);
    _Players.push_back(pl);
    _NbPlayers = (int)_Players.size();
    cout << "Let the game begin ! " << endl;
}



/**
 * Main function, plays the game
 */
bool Game::playGame()
{
    getNbPlayers();

    while (_Window.isOpen())
    {
        _CurrentTurn    = (_CurrentTurn + 1) % _NbPlayers;
        _CurrentPlayer  = _Players[_CurrentTurn];
        
        Event event;

        while (_Window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                _Window.close();
            }
        } 

        _Window.clear();
        _Window.draw(*board.getSprite());

        /* --------------------------- */
        /* STEP 1 : player rolls dices */
        /* --------------------------- */
        _CurrentPlayer->rollDices(_Window, _Dice1, _Dice2);

        /* --------------------------- */
        /* STEP 2 : player moves piece */
        /* --------------------------- */
        bool go = _CurrentPlayer->move();
        if (go)
            _CurrentPlayer->go(_Bank);

        /* -------------------------------------- */
        /* STEP 3 : updates position on the board */
        /* -------------------------------------- */
            

        _Window.display();
        return true;
    }
    return true;
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
    delete _Dice1;
    delete _Dice2;
}