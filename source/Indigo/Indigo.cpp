#include <iostream>
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
}
