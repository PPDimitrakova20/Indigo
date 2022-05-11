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