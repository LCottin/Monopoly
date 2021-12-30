#include "Chances.hpp"

/**
 * Default constructor
 */
Chances::Chances() : Cards()
{
    _MainTexture.loadFromFile("./Images/Chances/chance.png");
    _MainSprite.setTexture(_MainTexture);
    _MainSprite.setPosition(Vector2f(442, 603));
    _MainSprite.setRotation(315);
    
    _FocusTexture.loadFromFile("./Images/Chances/chance_focus.png");
    _FocusSprite.setTexture(_FocusTexture);
    _FocusSprite.setPosition(Vector2f(442, 603));
    _FocusSprite.setRotation(315);
}

/**
 * Draws a card randomly, saves it and returns the sprite associated
 * @returns The sprite of the card 
 */
Sprite* Chances::drawCard()
{
    //generates a pseudo random number between 1 and Cards
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> distribute(1, _CardsInDeck); // distribution in range [1, Cards]
    
    //makes sure the cards has not already been picked 
    do
    {
        _Number = distribute(rng);
    } while (find(_Numbers.begin(), _Numbers.end(), _Number) != _Numbers.end());
    
    //saves the info about the number of the card
    _Numbers.push_back(_Number);
    if (_Numbers.size() == _CardsInDeck)
        _Numbers.clear();

    //opens the right file
    string path = "./Images/Chances/chance" + to_string(_Number) + ".png";
    _OtherTexture.loadFromFile(path.c_str());
    _OtherSprite.setTexture(_OtherTexture);

    return &_OtherSprite;
}

/**
 * @brief Executes the action of the card
 * @param bank The bank
 * @param player The player who is playing
 * @returns 
 */
bool Chances::execute(Bank* bank, Player* player, vector<Player*>& players)
{
    vector<int> allPos(4);
    switch(_Number)
    {
        case 1:
        {
            //Goes to go and collects 200
            player->move(GO);
            player->go();
            cout << "You have collected 200 from the bank" << endl;
            return true;
        }

        case 2:
        {
            // Goes to Illinois Ave and collects 200 if you pass go
            if(player->move(ILLINOIS_AVENUE))
            {
                player->go();
                cout << "You have collected 200 from the bank" << endl;
            }
            cout << "You went to Illinois Avenue" << endl;
            return true;
        }
        
        case 3:
        {
            // Goes to St. Charles Place and collects 200 if you pass go
            if(player->move(ST_CHARLES_PLACE))
            {
                player->go();
                cout << "You have collected 200 from the bank" << endl;
            }
            cout << "You went to St. Charles Place" << endl;
            return true;
        }

        case 4:
        {
            // Goes to nearest utility and collects 100
            const int pos = player->getPosition();
            const int disWaterWorks       = abs(pos - WATER_WORKS);
            const int disElectricCompany  = abs(pos - ELECTRIC_COMPANY);
            bool go = false;

            // Moves the player to the nearest utility
            if (disWaterWorks < disElectricCompany)
            {
                go = player->move(WATER_WORKS);
                cout << "You went to Water Works" << endl;
            }
            else
            {
                go = player->move(ELECTRIC_COMPANY);
                cout << "You went to Electric Company" << endl;
            }

            // Collects 200 if the player passes go
            if (go)
            {
                player->go();
                cout << "You have collected 200 from the bank" << endl;
            }

            return true;
        }

        case 5:
        {
            // Goes to nearest railroad
            const int pos = player->getPosition();
            allPos.push_back(pos - READING_RAILROAD);
            allPos.push_back(pos - PENNSYLVANIA_RAILROAD);
            allPos.push_back(pos - B_AND_O_RAILROAD);
            allPos.push_back(pos - SHORT_LINE_RAILROAD);
            const int minPos = *min_element(allPos.begin(), allPos.end());

            // Moves the player to the nearest railroad
            const bool go = player->move(minPos);
            cout << "You went to the nearest railroad" << endl;

            // Collects 200 if the player passes go
            if (go)
            {
                player->go();
                cout << "You have collected 200 from the bank" << endl;
            }
            return true;
        }

        case 6:
        {
            // Receives 50 from the bank
            player->addMoney(50);
            cout << "You have received 50 from the bank" << endl;
            return true;
        }
        
        case 7: 
        {
            if (player->hasFreeCard() == false)
            {
                cout << "You received a Get Out of Jail Free card" << endl;
                player->setFreeCard(true);
            }
            else 
            {
                cout << "You already have a Get Out of Jail Free card" << endl;
            }
            return true;
        }

        case 8:
        {
            // Goes back 3 spaces 
            if (player->move(player->getPosition() - 3) == true)
            {
                player->go();
                cout << "You have collected 200 from the bank" << endl;
            }
            cout << "You went back 3 spaces" << endl;
            return true;
        }
        
        case 9:
        {
            // Go to jail and do not pass go
            player->move(JAIL);
            cout << "You went to jail" << endl;
            return true;
        }
        
        case 10:
        {
            //TODO: implements hotels
            // Makes general repairs on all your property
            const int toPay = player->getPropertyCount() * 25;
            bool ok = player->payBank(toPay);
            if (ok)
                cout << "You have paid the bank " << toPay << " for the repairs" << endl;
            else
                cout << "You don't have enough money to pay the bank -> ERROR" << endl;
            return ok;
        }

        case 11:
        {
            // Payes poor tax of $15
            const bool ok = player->payBank(15);
            if (ok)
                cout << "You have paid the bank 15 for the tax" << endl;
            else
                cout << "You don't have enough money to pay the bank -> ERROR" << endl;
            return ok;
        }

        case 12:
        {
            // Takes a trip to Reading Railroad
            if (player->move(READING_RAILROAD))
            {
                player->go();
                cout << "You have collected 200 from the bank" << endl;
            }
            cout << "You went to Reading Railroad" << endl;
            return true;
        }
        
        case 13:
        {
            // Goes to Boardwalk and collects 200 if you pass go
            if(player->move(BOARDWALK))
            {
                player->go();
                cout << "You have collected 200 from the bank" << endl;
            }
            cout << "You went to Boardwalk" << endl;
            return true;
        }
        
        case 14:
        {
            // Payes each player $50
            bool ok = true;
            for (int i = 0; i < players.size(); i++)
            {
                if (players[i] != player)
                {
                    ok &= player->payRent(players[i], 50);
                }
            }
            if (ok)
                cout << "You have paid each player 50" << endl;
            else
                cout << "You don't have enough money to pay the bank -> ERROR" << endl;
            return ok;
        }

        case 15:
        {
            // Building loan matures and you get $150
            player->addMoney(150);
            cout << "You have received 150 from the bank" << endl;
            return true;
        }

        case 16:
        {
            // Won a crossword competition and collect $100
            player->addMoney(100);
            cout << "You have received 100 from the bank" << endl;
            return true;
        }
        
        default:
        {
            cout << "Case not found in Chances::execute" << endl;
            return false;
        }
    }
}

/**
 * Default destructor
 */
Chances::~Chances()
{
}