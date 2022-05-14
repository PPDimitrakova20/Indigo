#include "drawCards.h"

// Draw 6 intial binary cards
void drawInitialBinaries(int initialBinaries[6], float scrWidth, float scrHeight, Card binaryCard)
{
    float posX = 50;

    // Loop between array elements
    for (int i = 0; i < 6; i++)
    {
        // Check if value equals 0
        if (initialBinaries[i] == false)
        {
            // Draw corresponding texture 750
            DrawTextureEx(binaryCard.texture, Vector2{ posX, 20 }, 0, 1, RAYWHITE);
            DrawTextureEx(binaryCard.texture, Vector2{ scrWidth + posX - 735, scrHeight - binaryCard.texture.height - 20}, 0, 1, RAYWHITE);
        }
        else
        {
            // Draw corresponding texture
            DrawTextureEx(binaryCard.texture, Vector2{ posX + 100, 170 }, 180, 1, RAYWHITE);
            DrawTextureEx(binaryCard.texture, Vector2{ (scrWidth + posX - 735) + 100, (scrHeight - binaryCard.texture.height) + 130 }, 180, 1, RAYWHITE);
        }

        posX += 105;
    }
    // Reset posX
    posX = 0;
}

// Draw newly drawn card based on type
void drawNewlyDrawnCard(int cardType, int x, int y)
{
    Card newCard(cardType);

    // Draw the newly drawn card
    DrawTexture(newCard.texture, x, y, RAYWHITE);
}
