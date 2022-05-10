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


// Manage cards according to their type
void manageNewCards(card altCard, int Array[6]);