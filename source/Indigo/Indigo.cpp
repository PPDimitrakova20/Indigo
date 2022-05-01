#include <iostream>
#include <string>
#include <stdlib.h> 
#include <Windows.h>
#include "inputChecks.h"
#include "getElements.h"
#include "printElements.h"

using namespace std;

int main()
{
    bool cardStack[13][7];
    int cardStackRows = 12, cardStackColumns = 6;

    srand(time(NULL));

    for (int i = 0; i < cardStackRows; i++)
    {
        for (int j = 0; j < cardStackColumns; j++)
        {
            if (i == 5)
            {
                cardStack[i][j] = rand() % 2;
                if (cardStack[i][j] == 1)
                {
                    cardStack[i][j] = true;
                }
                else
                {
                    cardStack[i][j] = false;
                }
                cardStack[i + 1][j] = !(cardStack[i][j]);
            }
            else if (i != 6)
            {
                cardStack[i][j] = false;
            }
        }
    }

    printCardStack(cardStack, cardStackRows, cardStackColumns);

    int topSidestart = 5, topSideindent = 1;
    int bottomSidestart = 6, bottomSideindent = 1;

    int playerSequence = startPlayerCheck();
    system("cls");
    printCardStack(cardStack, cardStackRows, cardStackColumns);

    int activeRow, activeColumn;
    const int firstPlayer = playerSequence;

    for (int x = 1; x <= 30; x++)
    {
        if (playerSequence % 2 != 0)
        {
            printPlayerQuestion(firstPlayer, playerSequence);
            cout << "Row: ";
            activeRow = getActiveRow() - 1;
            cout << "Column: ";
            activeColumn = getActiveColumn() - 1;
            cout << endl;

            system("cls");
            printCardStack(cardStack, cardStackRows, cardStackColumns);
            cout << "Playing on: " << endl;
            cout << "Row: " << activeRow + 1 << ", Column: " << activeColumn + 1 << endl << endl;
            printOperationInstructions();

            cardStack[activeRow][activeColumn] = getCardResult(cardStack[activeRow + 1][activeColumn], cardStack[activeRow + 1][activeColumn + 1]);
            system("cls");
            printCardStack(cardStack, cardStackRows, cardStackColumns);
        }
        else
        {
            printPlayerQuestion(firstPlayer, playerSequence);
            cout << "Row: ";
            activeRow = getActiveRow() - 1;
            cout << "Column: ";
            activeColumn = getActiveColumn() - 1;
            cout << endl;

            system("cls");
            printCardStack(cardStack, cardStackRows, cardStackColumns);
            cout << "Playing on: " << endl;
            cout << "Row: " << activeRow + 1 << ", Column: " << activeColumn + 1 << endl << endl;
            printOperationInstructions();

            cardStack[activeRow][activeColumn] = getCardResult(cardStack[activeRow - 1][activeColumn], cardStack[activeRow - 1][activeColumn + 1]);
            system("cls");
            printCardStack(cardStack, cardStackRows, cardStackColumns);
        }
        playerSequence++;
    }

    /*for (int x = 1; x <= 6; x++)
    {
        for (int y = topSidestart; y < topSidestart + 1; y++)
        {
            for (int z = 0; z < cardStackColumns - topSideindent; z++)
            {
                cardStack[y - 1][z] = cardResult(cardStack[y][z], cardStack[y][z + 1]);
                system("cls");
                printCardStack(cardStack, cardStackRows, cardStackColumns);
            }
        }

        topSidestart--;
        topSideindent++;
    }

    for (int x = 1; x <= 6; x++)
    {
        for (int y = bottomSidestart; y < bottomSidestart + 1; y++)
        {
            for (int z = 0; z < cardStackColumns - bottomSideindent; z++)
            {
                cardStack[y + 1][z] = cardResult(cardStack[y][z], cardStack[y][z + 1]);
                system("cls");
                printCardStack(cardStack, cardStackRows, cardStackColumns);
            }
        }

        bottomSidestart++;
        bottomSideindent++;
    }*/
}

