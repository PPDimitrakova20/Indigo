#include <iostream>
#include <string>
#include <stdlib.h> // for NUll
#include <Windows.h>

using namespace std;

void textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printCardStack(bool array[13][7], int arrayRows, int arrayColumns)
{
    int cutoff = 5;
    for (int i = 0; i < arrayRows; i++)
    {
        for (int j = 0; j < arrayColumns - cutoff; j++)
        {
            if (i >= 5 && i <= 6)
            {
                textcolor(1);
                cout << array[i][j] << " ";
            }
            else
            {
                textcolor(15);

                if (j == 0 && (i < 5 || i> 6))
                {
                    switch (i)
                    {
                    case 4:
                    case 7:
                        cout << " ";
                        break;
                    case 3:
                    case 8:
                        cout << "  ";
                        break;
                    case 2:
                    case 9:
                        cout << "   ";
                        break;
                    case 1:
                    case 10:
                        cout << "    ";
                        break;
                    case 0:
                    case 11:
                        cout << "     ";
                        break;
                    }
                }
                cout << array[i][j] << " ";
            }
        }
        cout << endl;
        if (i < 6)
        {
            if (i != 5)
            {
                cutoff--;
            }
        }
        else
        {
            cutoff++;
        }
    }
}

bool additionalcheck(string str)
{
    if (str == "1")
    {
        return true;
    }
    else if (str == "2")
    {
        return true;
    }
    else if (str == "3")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool cardResult(bool card1, bool card2)
{
    string operation;
    getline(cin, operation, '\n');
    int length = operation.length();

    while (true)
    {
        if (length == 1)
        {
            if (additionalcheck(operation))
            {
                break;
            }
            else
            {
                cout << "Invaild input please stick 1, 2, 3..." << endl;
                getline(cin, operation, '\n');
                if (additionalcheck(operation))
                {
                    break;
                }
            }
        }
        else
        {
            cout << "Invaild input please stick 1, 2, 3..." << endl;
            getline(cin, operation, '\n');
            if (additionalcheck(operation))
            {
                break;
            }
        }
    }

    int processedOperation = stoi(operation);

    switch (processedOperation)
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

    int startRow = 5, indent = 1;

    for (int x = 1; x <= 6; x++)
    {
        for (int y = startRow; y < startRow + 1; y++)
        {
            for (int z = 0; z < cardStackColumns - indent; z++)
            {
                cardStack[y - 1][z] = cardResult(cardStack[y][z], cardStack[y][z + 1]);
                system("cls");
                printCardStack(cardStack, cardStackRows, cardStackColumns);
            }
        }

        startRow--;
        indent++;
    }

    startRow = 6;
    indent = 1;

    for (int x = 1; x <= 6; x++)
    {
        for (int y = startRow; y < startRow + 1; y++)
        {
            for (int z = 0; z < cardStackColumns - indent; z++)
            {
                cardStack[y + 1][z] = cardResult(cardStack[y][z], cardStack[y][z + 1]);
                system("cls");
                printCardStack(cardStack, cardStackRows, cardStackColumns);
            }
        }

        startRow++;
        indent++;
    }
}
