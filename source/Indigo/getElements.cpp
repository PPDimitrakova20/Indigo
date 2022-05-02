#include <iostream>
#include "inputChecks.h"

// Calcute result when playing a card
// operation - which boolean operation is used (OR, AND, XOR)
bool getCardResult(bool card1, bool card2)
{
    int operation = cardResultCheck();

    switch (operation)
    {
    case 1:
        return card1 || card2;
        break;
    case 2:
        return card1 && card2;
        break;
    case 3:
        if (card1 != card2)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
}

// Get on which row is the player's next move
// Check if the input is in the intended range
// ActiveR - stores the value of the newly inputed varible
int getActiveRow()
{
    char activeR;
    std::cin >> activeR;
    int checkRLimit = 12;

    if (activeR - '0' < checkRLimit)
    {
        return activeR - '0';
    }
    else
    {
        printPositionErrorMessage(activeR - '0');
    }
}

// Get on which column is the player's next move
// Check if the input in the intended range
// ActiveC - stores the value of the newly inputed varible
int getActiveColumn()
{
    char activeC;
    std::cin >> activeC;
    int checkCLimit = 5;

    if (activeC - '0' < checkCLimit)
    {
        return activeC - '0';
    }
    else
    {
        printPositionErrorMessage(activeC - '0');
    }
}