#pragma once
#include "pvp.h"
#include "raylib.h"
#include <stdlib.h> // rand, srand
#include <time.h> // time

// Draw 6 intial binary cards
void drawInitialBinaries(int initialBinaries[6], float scrWidth, float scrHeight);

// Draw card pile 
void drawCardPile();

// Draw newly drawn card based on type
void drawNewlyDrawnCard(int cardType, int x, int y);