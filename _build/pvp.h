#pragma once
#include "raylib.h"
#include <stdlib.h> // rand, srand
#include <time.h> // time
#include <string> // time

/* Card Types
   0 -> OR result 0
   1 -> OR result 1
   2 -> AND result 0
   3 -> AND result 1
   4 -> XOR result 0
   5 -> XOR result 1
   6 -> cover
   7 -> initial binary
*/

// card stuct
struct Card
{
    int cardType;
    Texture2D texture;

    // Load texture for card type
    Card(int);
  
    // Unload textures
     //~Card();
};

// player cards struct
struct player 
{
    int type;
    bool isFull;
};

// Get the order of the 6 intial binaries
int *getIntialBinaryOrder(int Array[6]);

// Manage cards according to their type
void manageNewCards(Card altCard, int Array[6]);