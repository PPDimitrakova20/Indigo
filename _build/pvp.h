#pragma once
#include "raylib.h"
#include <stdlib.h> // rand, srand
#include <time.h> // time
#include <string> // time
#include <vector> // vector
#include <utility>
#include <iostream>

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

// Drag cords
struct Coordinates{
    Vector2 collisionCords; // Rectangle for collision check
    Vector2 placementCords; // Where a dragged card will clip to
};

// player cards struct
struct player 
{
    int type;
    bool isFull;
};

// Timer struct
typedef struct
{
    float Lifetime;
}Timer;

// Start or restart a timer with a specific lifetime
void startTimer(Timer* timer, float lifetime);


// Update a timer with the current frame time
void updateTimer(Timer* timer);

// Check if a timer is done
bool timerDone(Timer* timer);

// Get the order of the 6 intial binaries
int *getIntialBinaryOrder(int Array[6]);

// Shuffles cards
void shuffleDeck(std::vector<std::pair<Card, Vector2>> &deck);

// Deal cards
void dealCards(int &index, std::vector<std::pair<Card, Vector2>> &deckOfCard, int& whichPlaceholder, bool whichTurn);

// Get CollisionRentagels X and Y
Coordinates* getCollisionRentagelsCords(Coordinates cords[30]);