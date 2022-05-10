#pragma once
#include "pvp.h"
#include "raylib.h"
#include <stdlib.h> // rand, srand
#include <time.h> // time
Texture2D getTexture(card card);
bool drawInitialBinaries(bool isAssigned, int initialBinaries[6]);
void drawNewCards();
void drawCardCover();
void drawNewlyDrawnCard();