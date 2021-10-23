#include "Game.hpp"

/**
 * Default constructor
 */
Game::Game()
{
    _Window.create(VideoMode(800, 800), "Monopoly game !");

    _NbPlayers      = -1;
    _CurrentTurn    = 0;
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
    
    cout << "How many players will play ? " << endl;
    do
    {
        cout << "Enter a number between 2 and 4 included. " << endl;
        cout << "Number = ";
        cin >> _NbPlayers;
    } while (_NbPlayers < 2 || _NbPlayers > 4);
    
    //creates all players
    for (size_t i = 0; i < _NbPlayers; i++)
    {
        //FIXME: avoid player to have the same piece by removing it from the available pieces
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
 * Main function, plays the game
 */
bool Game::playGame()
{
    while (_Window.isOpen())
    {
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
        _Window.display();
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
    delete _CurrentPlayer;
}