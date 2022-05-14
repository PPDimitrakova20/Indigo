#include "pvp.h"

Card::Card(int type)
{
    char* textureSource[8] = {
    "././resources/OR0.png",
    "././resources/OR1.png",
    "././resources/AND0.png",
    "././resources/AND1.png",
    "././resources/XOR0.png",
    "././resources/XOR1.png",
    "././resources/CoverCard.png",
    "././resources/IntialBinaryCard.png"
    };
    this->cardType = type;
    texture = LoadTexture(textureSource[cardType]);
}

//Card::~Card()
//{
//    UnloadTexture(texture);
//}

// Get the order of the 6 intial binaries
int *getIntialBinaryOrder(int Array[6])
{
    for (int i = 0; i < 6; i++)
    {
        Array[i] = rand() % 2; // Assign random value between 0 and 1
    }

    return Array;
}

// Manage cards according to their type
void manageNewCards(Card altCard, int Array[6])
{
    // Update number of cards left from any given type
    Array[altCard.cardType]--;

    // Check if there are no more cards from any given type
    while (Array[altCard.cardType] < 0)
    {
        Array[altCard.cardType]++;
        altCard.cardType = rand() % 6;
        Array[altCard.cardType]--;
    }
}

// Get new card 
Card getNewCard()
{
    // Block for drawing new cards

    int cardQuanity[6] = { 8,8,8,8,8,8 }; // array for how many cards are left
    Card newCard(rand() % 6);

    manageNewCards(newCard, cardQuanity);
    return newCard;
}

void checkForDrag(bool &canMoveCard, int &x, int &y)
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (GetMouseX() >= 910 && GetMouseX() <= 1010) && (GetMouseY() >= 455 && GetMouseY() <= 605) && !canMoveCard)
    {
        canMoveCard = true;
    }
    
    if (canMoveCard)
    {
        x = GetMouseX() - 50;
        y = GetMouseY() - 50;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            canMoveCard = false;
        }
    }
}
