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

// Draw intial player decks
void drawInitailPlayerDecks(dealCords dealSpots[8], int& index, std::vector<Card>& deckOfCards, bool whichTurn)
{
    for (int i = 0; i < 8; i++)
    {
        // Update card position of a spot in a player deck
        deckOfCards[i].coordinates.x = dealSpots[i].pos.x;
        deckOfCards[i].coordinates.y = dealSpots[i].pos.y;

        // Flip texture base on where it will be drawn
        if (i < 4)
        {
            DrawTextureV(deckOfCards[i].textures[0], deckOfCards[i].coordinates, RAYWHITE);
        }
        else
        {
            DrawTextureV(deckOfCards[i].textures[1], deckOfCards[i].coordinates, RAYWHITE);
        }
        
        index++;
    }
}

// Continue drawing cards from the vector
void Card::drawCard()
{
    // Check where to draw inverted textures
    if (coordinates.x > 1243 || ((coordinates.x > 645 && coordinates.y > GetScreenHeight() / (float)2 -100)))
    {
        DrawTextureEx(textures[1], Vector2{ coordinates.x,coordinates.y }, 0, 1, RAYWHITE);
    }
    else
    {
        DrawTextureEx(textures[0], Vector2{ coordinates.x, coordinates.y }, 0, 1, RAYWHITE);
    }
}

