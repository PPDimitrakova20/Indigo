#pragma once
#include "pvp.h"
#include "raylib.h"
#include <stdlib.h> // rand, srand
#include <time.h> // time

// Draw 6 intial binary cards
void drawInitialBinaries(int initialBinaries[6], float scrWidth, float scrHeight, Card binaryCard);

void drawInitailPlayerDecks(dealCords dealSpots[8], int& index, std::vector<Card>& deckOfCards, bool whichTurn);

void drawNewlyDrawnCard(Texture2D texture[2], float x, float y);