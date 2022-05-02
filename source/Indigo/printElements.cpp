#include <iostream>
#include <Windows.h>

// Change the color of the output in the console
// color - 1 to 15 colors to color the output in the console
void changeTextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Print boolean operation instructions
void printOperationInstructions()
{
    std::cout << "Choose the next move to be made on the board:" << std::endl;
    std::cout << "1 --> boolean OR" << std::endl;
    std::cout << "2 --> boolean AND" << std::endl;
    std::cout << "3 --> boolean XOR" << std::endl;
}

// Print spacing before each row of the game
// spacing - how many spaces will be printed
void printIndentation(int spacing)
{
    for (int i = 0; i < spacing; i++)
    {
        std::cout << " ";
    }
}

// Print the main board of the game
// array[13][7] - the foundation of the game
// arrayRows - the number of rows in the array
// arrayColumn - the number of columns in the array
void printCardStack(bool array[13][7], int arrayRows, int arrayColumns)
{
    int cutOff = 5; // how many column less will be printed
    for (int i = 0; i < arrayRows; i++)
    {
        for (int j = 0; j < arrayColumns - cutOff; j++)
        {
            if (i >= 5 && i <= 6) // print intial binaries
            {
                changeTextColor(1);
                std::cout << array[i][j] << " ";
            }
            else // print everything else 
            {
                changeTextColor(15);

                if (j == 0 && (i < 5 || i> 6))
                {
                    switch (i)
                    {
                    case 4:
                    case 7:
                        printIndentation(1); // Add indentation
                        break;
                    case 3:
                    case 8:
                        printIndentation(2);
                        break;
                    case 2:
                    case 9:
                        printIndentation(3);
                        break;
                    case 1:
                    case 10:
                        printIndentation(4);
                        break;
                    case 0:
                    case 11:
                        printIndentation(5);
                        break;
                    }
                }
                std::cout << array[i][j] << " ";
            }
        }
        std::cout << std::endl;
        if (i < 6) // Manage column cutOff
        {
            if (i != 5)
            {
                cutOff--;
            }
        }
        else
        {
            cutOff++;
        }
    }
}

// Print player sequence
// fPlayer - const integer for the number of the first player
// sequence - tracks the sequence in which the players take turns
void printPlayerQuestion(int fPlayer, int sequence)
{
    if (fPlayer % 2 != 0)
    {
        std::cout << "Player " << sequence % 2 + 1 << ", where is your next move ? " << std::endl;
    }
    else
    {
        std::cout << "Player " << sequence % 2 + 1 << ", where is your next move ? " << std::endl;
    }
}