#pragma once
#include "pvp.h"
#include "raylib.h"
#include <stdlib.h> // rand, srand
#include <time.h> // time

Texture2D getTexture(card card);

void drawInitialBinaries(int initialBinaries[6], float scrWidth, float scrHeight);

void drawNewCards();

void drawCardCover();

void drawNewlyDrawnCard();