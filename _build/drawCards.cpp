#include "drawCards.h"

void setTexture(Card& card)
{
    switch (card.type)
    {
    case 0:
        card.texture = LoadTexture("././resources/OR0.png");
        break;
    case 1:
        card.texture = LoadTexture("././resources/OR1.png");
        break;
    case 2:
        card.texture = LoadTexture("././resources/AND0.png");
        break;
    case 3:
        card.texture = LoadTexture("././resources/AND1.png");
        break;
    case 4:
        card.texture = LoadTexture("././resources/XOR0.png");
        break;
    case 5:
        card.texture = LoadTexture("././resources/XOR1.png");
        break;
    case 6:
        card.texture = LoadTexture("././resources/CoverCard.png");
        break;
    case 7:
        card.texture = LoadTexture("././resources/IntialBinaryCard.png");
        break;
    }
}

// Draw 6 intial binary cards
void drawInitialBinaries(int initialBinaries[6], float scrWidth, float scrHeight)
{
    Card binaryCard;
    binaryCard.type = 7;
    setTexture(binaryCard);
    float posX = 50;

    // Loop between array elements
    for (int i = 0; i < 6; i++)
    {
        // Check if value equals 0
        if (initialBinaries[i] == false)
        {
            // Draw corresponding texture 750
            DrawTextureEx(binaryCard.texture, Vector2{ posX, 0 }, 0, 1, RAYWHITE);
            DrawTextureEx(binaryCard.texture, Vector2{ scrWidth + posX - 750, scrHeight - binaryCard.texture.height }, 0, 1, RAYWHITE);
        }
        else
        {
            // Draw corresponding texture
            DrawTextureEx(binaryCard.texture, Vector2{ posX + 100, 150 }, 180, 1, RAYWHITE);
            DrawTextureEx(binaryCard.texture, Vector2{ (scrWidth + posX - 750) + 100, (scrHeight - binaryCard.texture.height) + 150 }, 180, 1, RAYWHITE);
        }

        posX += 110;
    }
    // Reset posX
    posX = 0;
}

// Draw card pile 
void drawCardPile()
{
    Card coverCard;
    coverCard.type = 6;
    setTexture(coverCard);

    // Draw cover card (representing the card stack)
    DrawTexture(coverCard.texture, (GetScreenWidth() - coverCard.texture.width) / 2, (GetScreenHeight() - coverCard.texture.height) / 2 - 110, RAYWHITE);
}

// Draw newly drawn card based on type
void drawNewlyDrawnCard(int cardType)
{
    Card newCard;
    newCard.type = cardType;
    setTexture(newCard);
    // Draw the newly drawn card
    DrawTexture(newCard.texture, (GetScreenWidth() - newCard.texture.width) / 2, (GetScreenHeight() - newCard.texture.height) / 2 + 100, RAYWHITE);
}