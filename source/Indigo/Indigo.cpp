#include <iostream>
#include <stdlib.h> // for NULL

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
}
