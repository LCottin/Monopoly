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
            player->go(bank);
            return true;
        }

        case 2:
        {
            // Goes to Illinois Ave and collects 200 if you pass go
            if(player->move(ILLINOIS_AVENUE))
                player->go(bank);
            return true;
        }
        
        case 3:
        {
            // Goes to St. Charles Place and collects 200 if you pass go
            if(player->move(ST_CHARLES_PLACE))
                player->go(bank);
            return true;
        }

        case 4:
        {
            // Goes to nearest utility and collects 100
            int pos = player->getPosition();
            int disWaterWorks       = abs(pos - WATER_WORKS);
            int disElectricCompany  = abs(pos - ELECTRIC_COMPANY);
            bool go = false;

            // Moves the player to the nearest utility
            if (disWaterWorks < disElectricCompany)
            {
                go = player->move(WATER_WORKS);
            }
            else
            {
                go = player->move(ELECTRIC_COMPANY);
            }

            // Collects 200 if the player passes go
            if (go)
                player->go(bank);

            return true;
        }

        case 5:
        {
            // Goes to nearest railroad
            int pos = player->getPosition();
            allPos.push_back(pos - READING_RAILROAD);
            allPos.push_back(pos - PENNSYLVANIA_RAILROAD);
            allPos.push_back(pos - B_AND_O_RAILROAD);
            allPos.push_back(pos - SHORT_LINE_RAILROAD);
            int minPos = *min_element(allPos.begin(), allPos.end());

            // Moves the player to the nearest railroad
            bool go = player->move(minPos);

            // Collects 200 if the player passes go
            if (go)
                player->go(bank);

            return true;
        }

        case 6:
        {
            // Receives 50 from the bank
            bank->output(50);
            player->addMoney(50);
            return true;
        }
        
        //TODO: Implement the rest of the case
        case 7: 
        {
            // Goes out of jail free card
            return false;
        }

        case 8:
        {
            // Goes back 3 spaces 
            if (player->move(player->getPosition() - 3) == true)
                player->go(bank);
            return true;
        }
        
        case 9:
        {
            // Go to jail and do not pass go
            player->move(JAIL);
            return true;
        }
        
        case 10:
        {
            //TODO: implements hotels
            // Makes general repairs on all your property
            int toPay = player->getPropertyCount() * 25;
            return player->payBank(bank, toPay);
        }

        case 11:
        {
            // Payes poor tax of $15
            return player->payBank(bank, 15);
        }

        case 12:
        {
            // Takes a trip to Reading Railroad
            if (player->move(READING_RAILROAD))
                player->go(bank);
            return true;
        }
        
        case 13:
        {
            // Goes to Boardwalk and collects 200 if you pass go
            if(player->move(BOARDWALK))
                player->go(bank);
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
            return ok;
        }

        case 15:
        {
            // Building loan matures and you get $150
            bank->output(150);
            player->addMoney(150);
            return true;
        }

        case 16:
        {
            // Won a crossword competition and collect $100
            bank->output(100);
            player->addMoney(100);
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