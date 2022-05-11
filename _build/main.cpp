#include "menu.h"
#include "pvp.h"
#include "drawCards.h"

/* Card Types
   0 -> OR result 0
   1 -> OR result 1
   2 -> AND result 0
   3 -> AND result 1
   4 -> XOR result 0
   5 -> XOR result 1
*/

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
            drawInitialBinaries(initialBinaries, screenWidth, screenHeight);
            drawNewCards();
            drawCardCover();
            drawNewlyDrawnCard();
            isGameModeChosen = true; // Update gamemode
        }

        EndDrawing();
    }

    CloseWindow();
}