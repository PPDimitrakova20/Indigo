#include "drawCards.h"

const float screenWidth = 1920;
const float screenHeight = 1080;

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

bool drawInitialBinaries(bool isAssigned, int initialBinaries[6])
{
    float posX = 50;

    if (!isAssigned)
    {
        for (int i = 0; i < 6; i++)
        {
            initialBinaries[i] = rand() % 2; // Assign random value between 0 and 1
        }
        isAssigned = true;
    }

    // Draw the 6 iniatial binaries

    // Loop between array elements
    for (int i = 0; i < 6; i++)
    {

        Texture2D binaryCard = LoadTexture("././resources/IntialBinaryCard.png");
        // Check if value equals 0
        if (initialBinaries[i] == false)
        {
            // Draw corresponding texture
            DrawTextureEx(binaryCard, Vector2{ posX, 0 }, 0, 1, RAYWHITE);
            DrawTextureEx(binaryCard, Vector2{ screenWidth - posX - 100, screenHeight - binaryCard.height }, 0, 1, RAYWHITE);
        }
        else
        {
            // Draw corresponding texture
            DrawTextureEx(binaryCard, Vector2{ posX + 100, 150 }, 180, 1, RAYWHITE);
            DrawTextureEx(binaryCard, Vector2{ (screenWidth - posX - 100) + 100, (screenHeight - binaryCard.height) + 150 }, 180, 1, RAYWHITE);
        }

        posX += 110;
    }
    // Reset posX
    posX = 0;
    return isAssigned;
}

void drawNewCards()
{
    // Block for drawing new cards

    int cardQuanity[6] = { 8,8,8,8,8,8 }; // array for how many cards are left
    card newCard;

    newCard.type = rand() % 6; // Assign a type to the new card

    switch (newCard.type) // sorting algorithm
    {
    case 0:
        manageNewCards(newCard, cardQuanity);
        break;
    case 1:
        manageNewCards(newCard, cardQuanity);
        break;
    case 2:
        manageNewCards(newCard, cardQuanity);
        break;
    case 3:
        manageNewCards(newCard, cardQuanity);
        break;
    case 4:
        manageNewCards(newCard, cardQuanity);
        break;
    case 5:
        manageNewCards(newCard, cardQuanity);
        break;
    }
}

void drawCardCover()
{
    Texture2D coverCard = LoadTexture("././resources/CoverCard.png");
    // Draw cover card (representing the card stack)
    DrawTexture(coverCard, (GetScreenWidth() - coverCard.width) / 2, (GetScreenHeight() - coverCard.height) / 2 - 110, RAYWHITE);
}

void drawNewlyDrawnCard()
{
    card newCard;

    newCard.type = rand() % 6; // Assign a type to the new card

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