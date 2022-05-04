#include <iostream>
#include <string>
#include <stdlib.h> 
#include <Windows.h>
#include "inputChecks.h"
#include "getElements.h"
#include "printElements.h"
/*#include "../../raylib/raylib-master/src/raylib.h"*/

using namespace std;

int main()
{
    bool cardStack[13][7]; // the foundation of the game
    int cardStackRows = 12, cardStackColumns = 6;

    srand(time(NULL)); // Change the seed for rand()

    // Fill the base of the game
    for (int i = 0; i < cardStackRows; i++)
    {
        for (int j = 0; j < cardStackColumns; j++)
        {
            if (i == 5)
            {
                cardStack[i][j] = rand() % 2; // Randomise the intial binaries
                if (cardStack[i][j] == 1) // Assign true or false for 1 or 0
                {
                    cardStack[i][j] = true;
                }
                else
                {
                    cardStack[i][j] = false;
                }
                cardStack[i + 1][j] = !(cardStack[i][j]); // Add the other half of the intial binaries
            }
            else if (i != 6)
            {
                cardStack[i][j] = false; // Assign intial value to every other element
            }
        }
    }

    // Print the base of the game
    printCardStack(cardStack, cardStackRows, cardStackColumns);

    int playerSequence = startPlayerCheck(); // Get the first player
    system("cls");
    printCardStack(cardStack, cardStackRows, cardStackColumns);

    int activeRow, activeColumn; // the row and column of the current move
    const int firstPlayer = playerSequence; // base of the player to player move sequence

    // Fill the remaing open spaces in the game
    for (int x = 1; x <= 30; x++)
    {     
        if (playerSequence % 2 != 0) // Fill empty space in the top side
        {
            // Assign the row and column of the current move
            printPlayerQuestion(firstPlayer, playerSequence);
            cout << "Row: ";
            activeRow = getActiveRow() - 1;
            cout << "Column: ";
            activeColumn = getActiveColumn() - 1;
            cout << endl;

            // Print the row and column of the current move
            system("cls");
            printCardStack(cardStack, cardStackRows, cardStackColumns);
            cout << "Playing on: " << endl;
            cout << "Row: " << activeRow + 1 << ", Column: " << activeColumn + 1 << endl << endl;
            printOperationInstructions();

            // Calculate the outcome of the current move
            cardStack[activeRow][activeColumn] = getCardResult(cardStack[activeRow + 1][activeColumn], cardStack[activeRow + 1][activeColumn + 1]);
            system("cls");
            printCardStack(cardStack, cardStackRows, cardStackColumns);
        }
        else // Fill empty space in the bottom side
        {
            // Assign the row and column of the current move
            printPlayerQuestion(firstPlayer, playerSequence);
            cout << "Row: ";
            activeRow = getActiveRow() - 1;
            cout << "Column: ";
            activeColumn = getActiveColumn() - 1;
            cout << endl;

            // Print the row and column of the current move
            system("cls");
            printCardStack(cardStack, cardStackRows, cardStackColumns);
            cout << "Playing on: " << endl;
            cout << "Row: " << activeRow + 1 << ", Column: " << activeColumn + 1 << endl << endl;
            printOperationInstructions();

            // Calculate the outcome of the current move
            cardStack[activeRow][activeColumn] = getCardResult(cardStack[activeRow - 1][activeColumn], cardStack[activeRow - 1][activeColumn + 1]);
            system("cls");
            printCardStack(cardStack, cardStackRows, cardStackColumns);
        }
        playerSequence++; // Drive the player sequence forward
    }

    
    int topSidestart = 5, topSideindent = 1;
    int bottomSidestart = 6, bottomSideindent = 1;
    
    for (int x = 1; x <= 6; x++)
    {
        for (int y = topSidestart; y < topSidestart + 1; y++)
        {
            for (int z = 0; z < cardStackColumns - topSideindent; z++)
            {
                cardStack[y - 1][z] = getCardResult(cardStack[y][z], cardStack[y][z + 1]);
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
                cardStack[y + 1][z] = getCardResult(cardStack[y][z], cardStack[y][z + 1]);
                system("cls");
                printCardStack(cardStack, cardStackRows, cardStackColumns);
            }
        }

        bottomSidestart++;
        bottomSideindent++;
    }
}

