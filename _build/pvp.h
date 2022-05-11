#pragma once
#include "raylib.h"
#include <stdlib.h> // rand, srand
#include <time.h> // time

// card stuct
struct card
{
    int type;
    bool result;
    Texture2D texture;
};

// Get the order of the 6 intial binaries
int *getIntialBinaryOrder(int Array[6]);

// Manage cards according to their type
void manageNewCards(card altCard, int Array[6]);