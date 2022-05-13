#include "pvp.h"

Card::Card(char* path, int type)
{
    this->type = type;
    texture = LoadTexture(path);
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

// Get type of newly drawn card
int getNewlyDrawnCardType(Card altCard)
{
    altCard.type = rand() % 6; // Assign a type to the new card
    return altCard.type;
}

// Manage cards according to their type
void manageNewCards(Card altCard, int Array[6])
{
    // Update number of cards left from any given type
    Array[altCard.type]--;

    // Check if there are no more cards from any given type
    while (Array[altCard.type] < 0)
    {
        Array[altCard.type]++;
        altCard.type = rand() % 6;
        Array[altCard.type]--;
    }

    // Assign corespoding result based on the card's type
    if (altCard.type % 2 == 0)
    {
        altCard.result = false;
    }
    else
    {
        altCard.result = true;
    }
}

// Get new card 
void getNewCard()
{
    // Block for drawing new cards

    int cardQuanity[6] = { 8,8,8,8,8,8 }; // array for how many cards are left
    Card newCard;

    newCard.type = rand() % 6; // Assign a type to the new card

    manageNewCards(newCard, cardQuanity);
   
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
