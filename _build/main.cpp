#include "menu.h"
#include "pvp.h"
#include "drawCards.h"

int main()
{
    const float screenWidth = 1920;
    const float screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "dev window");
    SetTargetFPS(60);

    /*ToggleFullscreen();*/

    srand(time(NULL)); // Randomise seed for rand()

    // Variables for choosing gamemode
    int gameMode; // selected gamemode
    bool isGameModeChosen = false;
    
    // Variable for drawing the intial binary cards
    int initialBinaries[6]; // Order of intial binary cards
    int *ptr = getIntialBinaryOrder(initialBinaries);
    ptr = initialBinaries;

    // Variables for drawing newly drawn card
    Card newlyDrawnCard;
    int cardType = getNewlyDrawnCardType(newlyDrawnCard);
    bool continueDrawing = false;
    
    Texture background = LoadTexture("././resources/Background.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Clean frame buffer
        ClearBackground(RAYWHITE);
        
        

        // Check if the a gamemode has been selected
        if (!isGameModeChosen)
        {
            drawMenuText();
            gameMode = getPlayOption();
        }

        // Draw gamemode Player vs Player
        if (gameMode == 1)
        {
            DrawTexture(background, 0, 0, RAYWHITE);
            drawInitialBinaries(initialBinaries, screenWidth, screenHeight);

            getNewCard();

            drawCardPile();

            // Check if card pile is clicked
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (GetMouseX() >= 910 && GetMouseX() <= 1010) && (GetMouseY() >= 464 && GetMouseY() <= 564))
            {
                drawNewlyDrawnCard(cardType);
                continueDrawing = true;
            }

            // Keep drawing newly drawn card
            if (continueDrawing == true)
            {
                drawNewlyDrawnCard(cardType);
            }
            // Remember to reset the value of continueDrawing after the card moves out of its place !
            isGameModeChosen = true; // Update gamemode
        }

        EndDrawing();
    }

    CloseWindow();
}