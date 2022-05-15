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
            DrawTextureEx(binaryCard.textures[0], Vector2{posX, 20}, 0, 1, RAYWHITE);
            DrawTextureEx(binaryCard.textures[0], Vector2{scrWidth + posX - 735, scrHeight - binaryCard.textures[0].height - 20}, 0, 1, RAYWHITE);
        }
        else
        {
            // Draw corresponding texture
            DrawTextureEx(binaryCard.textures[0], Vector2{posX + 100, 170}, 180, 1, RAYWHITE);
            DrawTextureEx(binaryCard.textures[0], Vector2{(scrWidth + posX - 735) + 100, (scrHeight - binaryCard.textures[0].height) + 130}, 180, 1, RAYWHITE);
        }

        posX += 105;
    }
    // Reset posX
    posX = 0;
}

void drawInitailPlayerDecks(dealCords dealSpots[8], int& index, std::vector<Card>& deckOfCards, bool whichTurn)
{
    for (int i = 0; i < 8; i++)
    {
        deckOfCards[i].coordinates.x = dealSpots[i].pos.x;
        deckOfCards[i].coordinates.y = dealSpots[i].pos.y;
        if (i < 4)
        {
            DrawTextureEx(deckOfCards[i].textures[0], Vector2{deckOfCards[i].coordinates.x, deckOfCards[i].coordinates.y}, 0, 1, RAYWHITE);
        }
        else
        {
            DrawTextureEx(deckOfCards[i].textures[1], Vector2{deckOfCards[i].coordinates.x, deckOfCards[i].coordinates.y}, 0, 1, RAYWHITE);
        }
        
        index++;
    }
}

// Draw newly drawn card based on type
void drawNewlyDrawnCard(Texture2D texture[2], float x, float y)
{
    // Draw the newly drawn card
    DrawTextureEx(texture[0], Vector2{x,y}, 0, 1, RAYWHITE);
}
