#include "Communities.hpp"

/**
 * Default constructor
 */
Communities::Communities() : Cards()
{
    _MainTexture.loadFromFile("./Images/Communities/com.png");
    _MainSprite.setTexture(_MainTexture);
    _MainSprite.setPosition(Vector2f(358, 200));
    _MainSprite.setRotation(135);
    
    _FocusTexture.loadFromFile("./Images/Communities/com_focus.png");
    _FocusSprite.setTexture(_FocusTexture);
    _FocusSprite.setPosition(Vector2f(358, 200));
    _FocusSprite.setRotation(135);
}

/**
 * Draws a card randomly, saves it and returns the sprite associated
 * @returns The sprite of the card 
 */
Sprite* Communities::drawCard()
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
    string path = "./Images/Communities/com" + to_string(_Number) + ".png";
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
bool Communities::execute(Bank* bank, Player* player, vector<Player*>& players)
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
            // Bank error in your favor. Collects 200
            player->addMoney(200);
            cout << "You have collected 200 from the bank" << endl;
            return true;
        }
        
        case 3:
        {
            // Doctor's fees. Payes 50
            const bool ok = player->payBank(50);
            if (ok)
                cout << "You have paid 50 to the bank" << endl;
            else
                cout << "You don't have enough money -> ERROR" << endl;
            return ok;
        }

        case 4:
        {
            // Gets 50 from sale of stock you own.
            player->addMoney(50);
            cout << "You have collected 50 from the bank" << endl;
            return true;
        }

        //TODO: Adds the rest of the cards
        case 5:
        {
            // Gets out of jail free card
            return false;
        }

        case 6:
        {
            // Goes directly to jail. Do not pass go. Do not collect 200
            player->move(JAIL);
            cout << "You have been sent to jail" << endl;
            return true;
        }

        case 7:
        {
            // Grand Opera Night. Collects 50 from every player for opening night seats.
            bool ok = true;
            for (int i = 0; i < players.size(); i++)
            {
                if (players[i] != player)
                {
                    ok &= players[i]->removeMoney(50);
                    player->addMoney(50, false);
                }
            }
            if (ok)
                cout << "You have collected 50 from every player" << endl;
            else
                cout << "You have not collected 50 from every player -> ERROR" << endl;
            return ok;
        }

        case 8:
        {
            // Holiday fund matures. Collects 100
            player->addMoney(100);
            cout << "You have collected 100 from the bank" << endl;
            return true;
        }
        
        case 9:
        {
            // It's your birthday. Collect 20
            player->addMoney(20);
            cout << "You have collected 20 from the bank" << endl;
            return true;
        }

        case 10:
        {
            // Life insurance matures. Collect 100
            player->addMoney(100);
            cout << "You have collected 100 from the bank" << endl;
            return true;
        }
        
        case 11:
        {
            // Payes hospital fees of $100
            const bool ok = player->payBank(100);
            if (ok)
                cout << "You have paid 100 to the bank" << endl;
            else
                cout << "You don't have enough money -> ERROR" << endl;
            return ok;
        }

        case 12:
        {
            // Payes school fees of $100
            const bool ok = player->payBank(100);
            if (ok)
                cout << "You have paid 100 to the bank" << endl;
            else
                cout << "You don't have enough money -> ERROR" << endl;
            return ok;
        }

        case 13:
        {
            // Receives $25 consultancy fee
            player->addMoney(25);
            cout << "You have collected 25 from the bank" << endl;
            return true;
        }

        case 14:
        {
            //TODO: implements hotels
            // Makes general repairs on all your property. For each house pay $40. For each hotel $100.
            const int toPay = player->getPropertyCount() * 40;
            bool ok = player->payBank(toPay);
            if (ok)
                cout << "You have paid " << to_string(toPay) << " to the bank" << endl;
            else
                cout << "You don't have enough money -> ERROR" << endl;
            return ok;
        }

        case 15:
        {
            // Won a second prize in a beauty contest. Collect 50
            player->addMoney(50);
            cout << "You have collected 50 from the bank" << endl;
            return true;
        }
        
        case 16: 
        {  
            // You inherits $100
            player->addMoney(100);
            cout << "You have collected 100 from the bank" << endl;
            return true;
        }

        default:
        {
            cout << "Case not found in Comunities::execute" << endl;
            return false;
        }
    }
}

/**
 * Default destructor
 */
Communities::~Communities()
{
}