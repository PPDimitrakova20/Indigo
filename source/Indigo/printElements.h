#pragma once

void textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printOperationInstructions()
{
    std::cout << "Choose the next move to be made on the board:" << std::endl;
    std::cout << "1 --> boolean OR" << std::endl;
    std::cout << "2 --> boolean AND" << std::endl;
    std::cout << "3 --> boolean XOR" << std::endl;
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
                std::cout << array[i][j] << " ";
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
                        std::cout << " ";
                        break;
                    case 3:
                    case 8:
                        std::cout << "  ";
                        break;
                    case 2:
                    case 9:
                        std::cout << "   ";
                        break;
                    case 1:
                    case 10:
                        std::cout << "    ";
                        break;
                    case 0:
                    case 11:
                        std::cout << "     ";
                        break;
                    }
                }
                std::cout << array[i][j] << " ";
            }
        }
        std::cout << std::endl;
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

void printPlayerQuestion(int fPlayer, int sequence)
{
    if (fPlayer % 2 != 0)
    {
        if (sequence % 2 != 0)
        {
            std::cout << "Player 1, where is your next move?" << std::endl;
        }
        else
        {
            std::cout << "Player 2, where is your next move?" << std::endl;
        }
    }
    else
    {
        if (sequence % 2 != 0)
        {
            std::cout << "Player 2, where is your next move?" << std::endl;
        }
        else
        {
            std::cout << "Player 1, where is your next move?" << std::endl;
        }
    }
}
