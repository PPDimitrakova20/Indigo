#pragma once
#include "pvp.h"
#include "raylib.h"
#include <stdlib.h> // rand, srand
#include <time.h> // time

// Draw 6 intial binary cards
void drawInitialBinaries(int initialBinaries[6], float scrWidth, float scrHeight, Card binaryCard);

// Draw intial player decks
void drawInitailPlayerDecks(dealCords dealSpots[8], int& index, std::vector<Card>& deckOfCards, bool whichTurn);
