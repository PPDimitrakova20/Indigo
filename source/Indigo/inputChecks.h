#pragma once

bool checkInput(std::string str, int max)
{
    if (str == "1")
    {
        if (max == 1)
        {
            return true;
        }
    }
    else if (str == "2")
    {
        if (max <= 2)
        {
            return true;
        }
    }
    else if (str == "3")
    {
        if (max <= 3)
        {
            return true;
        }
    }
    else if (str == "4")
    {
        if (max <= 4)
        {
            return true;
        }
    }
    else if (str == "5")
    {
        if (max <= 5)
        {
            return true;
        }
    }
    else if (str == "6")
    {
        if (max <= 6)
        {
            return true;
        }
    }
    else if (str == "7")
    {
        if (max <= 7)
        {
            return true;
        }
    }
    else if (str == "8")
    {
        if (max <= 8)
        {
            return true;
        }
    }
    else if (str == "9")
    {
        if (max <= 9)
        {
            return true;
        }
    }
    else if (str == "10")
    {
        if (max <= 10)
        {
            return true;
        }
    }
    else if (str == "11")
    {
        if (max <= 11)
        {
            return true;
        }
    }
    else if (str == "12")
    {
        if (max <= 12)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

void printPositionErrorMessage(int limit)
{
    switch (limit)
    {
    case 1:
        std::cout << "Invaild input please stick to 1..." << std::endl;
        break;
    case 2:
        std::cout << "Invaild input please stick to 1, 2..." << std::endl;
        break;
    case 3:
        std::cout << "Invaild input please stick to 1, 2, 3..." << std::endl;
        break;
    case 4:
        std::cout << "Invaild input please stick to 1, 2, 3, 4..." << std::endl;
        break;
    case 5:
        std::cout << "Invaild input please stick to 1, 2, 3, 4, 5..." << std::endl;
        break;
    case 6:
        std::cout << "Invaild input please stick to 1, 2, 3, 4, 5, 6..." << std::endl;
        break;
    case 7:
        std::cout << "Invaild input please stick to 1, 2, 3, 4, 5, 6, 7..." << std::endl;
        break;
    case 8:
        std::cout << "Invaild input please stick to 1, 2, 3, 4, 5, 6, 7, 8..." << std::endl;
        break;
    case 9:
        std::cout << "Invaild input please stick to 1, 2, 3, 4, 5, 6, 7, 8, 9..." << std::endl;
        break;
    case 10:
        std::cout << "Invaild input please stick to 1, 2, 3, 4, 5, 6, 7, 8, 9, 10..." << std::endl;
        break;
    case 11:
        std::cout << "Invaild input please stick to 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11..." << std::endl;
        break;
    case 12:
        std::cout << "Invaild input please stick to 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12..." << std::endl;
        break;
    }
}

int cardResultCheck()
{
    std::string operation;
    getline(std::cin, operation, '\n');
    int length = operation.length();

    while (true)
    {
        if (length == 1)
        {
            if (checkInput(operation, 3))
            {
                break;
            }
            else
            {
                printPositionErrorMessage(3);
                getline(std::cin, operation, '\n');
                if (checkInput(operation, 3))
                {
                    break;
                }
            }
        }
        else
        {
            printPositionErrorMessage(3);
            getline(std::cin, operation, '\n');
            if (checkInput(operation, 3))
            {
                break;
            }
        }
    }

    int processedOperation = stoi(operation);

    return processedOperation;
}

int startPlayerCheck()
{
    std::string str = "";
    std::cout << "Which player is first?" << std::endl;
    getline(std::cin, str, '\n');
    int length = str.length();

    while (true)
    {
        if (length == 1)
        {
            if (checkInput(str, 2))
            {
                break;
            }
            else
            {
                printPositionErrorMessage(2);
                getline(std::cin, str, '\n');
                if (checkInput(str, 2))
                {
                    break;
                }
            }
        }
        else
        {
            printPositionErrorMessage(2);
            getline(std::cin, str, '\n');
            if (checkInput(str, 2))
            {
                break;
            }
        }
    }

    int Player = stoi(str);

    return Player;
}
