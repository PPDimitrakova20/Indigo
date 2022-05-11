#include "drawCards.h"

// Load textures for cards
Texture2D getTexture(card card)
{
    switch (card.type)
    {
        // Load OR card
    case 0:
        return LoadTexture("././resources/OR0.png");
    case 1:
        return LoadTexture("././resources/OR1.png");

        // Load AND cards
    case 2:
        return LoadTexture("././resources/AND0.png");
    case 3:
        return LoadTexture("././resources/AND1.png");

        // Load XOR cards
    case 4:
        return LoadTexture("././resources/XOR0.png");
    case 5:
        return LoadTexture("././resources/XOR1.png");
    }
}

// Draw 6 intial binary cards
void drawInitialBinaries(int initialBinaries[6], float scrWidth, float scrHeight)
{
    float posX = 50;

    // Loop between array elements
    for (int i = 0; i < 6; i++)
    {

        Texture2D binaryCard = LoadTexture("././resources/IntialBinaryCard.png");
        // Check if value equals 0
        if (initialBinaries[i] == false)
        {
            // Draw corresponding texture 750
            DrawTextureEx(binaryCard, Vector2{ posX, 0 }, 0, 1, RAYWHITE);
            DrawTextureEx(binaryCard, Vector2{ scrWidth + posX - 750, scrHeight - binaryCard.height }, 0, 1, RAYWHITE);
        }
        else
        {
            // Draw corresponding texture
            DrawTextureEx(binaryCard, Vector2{ posX + 100, 150 }, 180, 1, RAYWHITE);
            DrawTextureEx(binaryCard, Vector2{ (scrWidth + posX - 750) + 100, (scrHeight - binaryCard.height) + 150 }, 180, 1, RAYWHITE);
        }

        posX += 110;
    }
    // Reset posX
    posX = 0;
}

// Draw card pile 
void drawCardPile()
{
    Texture2D coverCard = LoadTexture("././resources/CoverCard.png");
    // Draw cover card (representing the card stack)
    DrawTexture(coverCard, (GetScreenWidth() - coverCard.width) / 2, (GetScreenHeight() - coverCard.height) / 2 - 110, RAYWHITE);
}

// Draw newly drawn card based on type
void drawNewlyDrawnCard(int cardType)
{
    card newCard;

    newCard.type = cardType;

    // Draw the newly drawm card
    switch (newCard.type)
    {
    case 0:
        DrawTexture(getTexture(newCard), (GetScreenWidth() - getTexture(newCard).width) / 2, (GetScreenHeight() - getTexture(newCard).height) / 2 + 100, RAYWHITE);
        break;
    case 1:
        DrawTexture(getTexture(newCard), (GetScreenWidth() - getTexture(newCard).width) / 2, (GetScreenHeight() - getTexture(newCard).height) / 2 + 100, RAYWHITE);
        break;
    case 2:
        DrawTexture(getTexture(newCard), (GetScreenWidth() - getTexture(newCard).width) / 2, (GetScreenHeight() - getTexture(newCard).height) / 2 + 100, RAYWHITE);
        break;
    case 3:
        DrawTexture(getTexture(newCard), (GetScreenWidth() - getTexture(newCard).width) / 2, (GetScreenHeight() - getTexture(newCard).height) / 2 + 100, RAYWHITE);
        break;
    case 4:
        DrawTexture(getTexture(newCard), (GetScreenWidth() - getTexture(newCard).width) / 2, (GetScreenHeight() - getTexture(newCard).height) / 2 + 100, RAYWHITE);
        break;
    case 5:
        DrawTexture(getTexture(newCard), (GetScreenWidth() - getTexture(newCard).width) / 2, (GetScreenHeight() - getTexture(newCard).height) / 2 + 100, RAYWHITE);
        break;
    }
}