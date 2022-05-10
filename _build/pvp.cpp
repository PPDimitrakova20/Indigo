#include "pvp.h"

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