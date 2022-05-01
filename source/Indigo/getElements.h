#pragma once
#include "inputChecks.h"

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

int getActiveRow()
{
    std::string activeR = "";
    getline(std::cin, activeR, '\n');
    int length = activeR.length(), checkRLimit = 12;

    while (true)
    {
        if (length == 1)
        {
            if (checkInput(activeR, checkRLimit))
            {
                break;
            }
            else
            {
                printPositionErrorMessage(checkRLimit);
                getline(std::cin, activeR, '\n');
                if (checkInput(activeR, checkRLimit))
                {
                    break;
                }
            }
        }
        else
        {
            printPositionErrorMessage(checkRLimit);
            getline(std::cin, activeR, '\n');
            if (checkInput(activeR, checkRLimit))
            {
                break;
            }
        }
    }

    int activeRInt = stoi(activeR);

    return activeRInt;
}

int getActiveColumn()
{
    std::string activeC = "";
    getline(std::cin, activeC, '\n');
    int length = activeC.length(), checkCLimit = 5;

    while (true)
    {
        if (length == 1)
        {
            if (checkInput(activeC, checkCLimit))
            {
                break;
            }
            else
            {
                printPositionErrorMessage(checkCLimit);
                getline(std::cin, activeC, '\n');
                if (checkInput(activeC, checkCLimit))
                {
                    break;
                }
            }
        }
        else
        {
            printPositionErrorMessage(checkCLimit);
            getline(std::cin, activeC, '\n');
            if (checkInput(activeC, checkCLimit))
            {
                break;
            }
        }
    }

    int activeRInt = stoi(activeC);

    return activeRInt;
}
