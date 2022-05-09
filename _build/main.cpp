#include "raylib.h"
#include "menu.h"
#include <stdlib.h> // rand, srand
#include <time.h> // time

// card stuct
struct card 
{
    int type;
    bool result;
};

/* Card Types
   0 -> OR result 0
   1 -> OR result 1
   2 -> AND result 0
   3 -> AND result 1
   4 -> XOR result 0
   5 -> XOR result 1
*/

// Manage cards according to their type
void manageNewCards(card altCard, int Array[6])
{
    // Update number of cards left from any given type
    Array[altCard.type]--; 

    // Check if there are no more cards from any given type
    while (Array[altCard.type] < 0) 
    {
        Array[altCard.type]++;
        altCard.type = rand() % 6;
        Array[altCard.type]--;
    }

    // Assign corespoding result based on the card's type
    if (altCard.type % 2 == 0)
    {
        altCard.result = false;
    }
    else
    {
        altCard.result = true;
    }
}

int main()
{
    const float screenWidth = 1920;
    const float screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "dev window");
    SetTargetFPS(60);

    /*ToggleFullscreen();*/

    // Load textures for cards -------------------------------
        // Load OR cards ---------------------------------------------------------------
        Texture2D cardOr0 = LoadTexture("././resources/OR0.png");
        Texture2D cardOr1 = LoadTexture("././resources/OR1.png");
        // -----------------------------------------------------------------------------

        // Load AND cards -----------------------------------------------------------
        Texture2D cardAnd0 = LoadTexture("././resources/AND0.png");
        Texture2D cardAnd1 = LoadTexture("././resources/AND1.png");
        // --------------------------------------------------------------------------

        // Load XOR cards ----------------------------------------------------------------
        Texture2D cardXor0 = LoadTexture("././resources/XOR0.png");
        Texture2D cardXor1 = LoadTexture("././resources/XOR1.png");
        // -------------------------------------------------------------------------------

        // Load Intial binaries ---------------------------------------------------------
        Texture2D initialBinary = LoadTexture("././resources/Intial Binary Card.png");
        // -------------------------------------------------------------------------------------------

        // Load Cover card -----------------------------------------------
        Texture2D coverCard = LoadTexture("././resources/CoverCard.png");
        // ---------------------------------------------------------------
    
    // -------------------------------------------------------

    srand(time(NULL)); // Randomise seed for rand()

    // Block for intial binaries ----------------------------------------------

        bool initialBinaries[6]; // array of 0s and 1s

        float posX = 50;

        for (int i = 0; i < 6; i++)
        {
            initialBinaries[i] = rand() % 2; // Assign random value between 0 and 1
        }
    // ----------------------------------------------------------------------------

    // Block for drawing new cards -----------------------------------------------
        
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
    // ---------------------------------------------------------------------------

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        /*printMenu();*/
        
        // Draw the 6 iniatial binaries

        // Loop between array elements
        for (int i = 0; i < 6; i++)
        {
            // Check if value equals 0
            if (initialBinaries[i] == 0)
            {
                // Draw corresponding texture
                DrawTextureEx(initialBinary, Vector2{ posX, 0 }, 0, 1, RAYWHITE);
                DrawTextureEx(initialBinary, Vector2{ screenWidth - posX - 100, screenHeight - initialBinary.height }, 0, 1, RAYWHITE);
            }
            else
            {
                // Draw corresponding texture
                DrawTextureEx(initialBinary, Vector2{ posX + 100, 150 }, 180, 1, RAYWHITE);
                DrawTextureEx(initialBinary, Vector2{ (screenWidth - posX - 100) + 100, (screenHeight - initialBinary.height) + 150 }, 180, 1, RAYWHITE);
            }

            posX += 110;
        }

        // Draw cover card (representing the card stack)
        DrawTexture(coverCard, (screenWidth - coverCard.width) / 2, (screenHeight - coverCard.height) / 2 - 110, RAYWHITE);

        // Draw the newly drawm card
        switch (newCard.type)
        {
        case 0:
            DrawTexture(cardOr0, (screenWidth - coverCard.width) / 2, (screenHeight - coverCard.height) / 2 + 100, RAYWHITE);
            break;
        case 1:
            DrawTexture(cardOr1, (screenWidth - coverCard.width) / 2, (screenHeight - coverCard.height) / 2 + 100, RAYWHITE);
            break;
        case 2:
            DrawTexture(cardAnd0, (screenWidth - coverCard.width) / 2, (screenHeight - coverCard.height) / 2 + 100, RAYWHITE);
            break;
        case 3:
            DrawTexture(cardAnd1, (screenWidth - coverCard.width) / 2, (screenHeight - coverCard.height) / 2 + 100, RAYWHITE);
            break;
        case 4:
            DrawTexture(cardXor0, (screenWidth - coverCard.width) / 2, (screenHeight - coverCard.height) / 2 + 100, RAYWHITE);
            break;
        case 5:
            DrawTexture(cardXor1, (screenWidth - coverCard.width) / 2, (screenHeight - coverCard.height) / 2 + 100, RAYWHITE);
            break;
        }

        // Reset posX
        posX = 0;
        EndDrawing();
    }

    CloseWindow();
}