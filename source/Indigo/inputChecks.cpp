#include <iostream>
#include <string>

// Check if input in between 1 and max
// max - maximal value fot the range (1 - max)  
bool checkInput(std::string str, int max)
{
    return std::stoi(str) <= max;
}

// Print error messages
void printPositionErrorMessage(int limit)
{
    std::cout << "Invaild input please stick to ";
    for (int i = 1; i <= limit; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Check if operation input is in intended range
// operation - boolean operations (OR, AND, XOR)
int cardResultCheck()
{
    char operation;
    std::cin >> operation;

    if (operation - '0' < 4)
    {
        return operation - '0';
    }
    else
    {
        printPositionErrorMessage(operation - '0');
    }
}

// Check if player input is in intended range
// playerNum - which player is first
int startPlayerCheck()
{
    char playerNum;
    std::cout << "Which player is first?" << std::endl;
    std::cin >> playerNum;

    if (playerNum - '0' < 3)
    {
        return playerNum - '0';
    }
    else
    {
        printPositionErrorMessage(playerNum - '0');
    }

}