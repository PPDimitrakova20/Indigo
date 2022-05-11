#include "pvp.h"

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
int getNewlyDrawnCardType(card altCard)
{
    altCard.type = rand() % 6; // Assign a type to the new card
    return altCard.type;
}

// Manage cards according to their type
void manageNewCards(card altCard, int Array[6])
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
    card newCard;

    newCard.type = rand() % 6; // Assign a type to the new card

    switch (newCard.type) // sorting algorithm
    {
    case 0:
        manageNewCards(newCard, cardQuanity);
        break;
    case 1:
        manageNewCards(newCard, cardQuanity);
        break;
    case 2:
        manageNewCards(newCard, cardQuanity);
        break;
    case 3:
        manageNewCards(newCard, cardQuanity);
        break;
    case 4:
        manageNewCards(newCard, cardQuanity);
        break;
    case 5:
        manageNewCards(newCard, cardQuanity);
        break;
    }
}