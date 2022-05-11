#include "menu.h"
#include "pvp.h"
#include "drawCards.h"

// Load Intial binaries


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

    ToggleFullscreen();

    srand(time(NULL)); // Randomise seed for rand()

    int gameMode;
    bool isGameModeChosen = false;
    bool isAssigned = false;
    int initialBinaries[6] = { 0,0,0,0,0,0 };
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        if (!isGameModeChosen)
        {
            drawMenuText();
            gameMode = getPlayOption();
        }

        if (gameMode == 1)
        {
            isAssigned = drawInitialBinaries(isAssigned, initialBinaries);
            drawNewCards();
            drawCardCover();
            drawNewlyDrawnCard();
            isGameModeChosen = true;
        }

        EndDrawing();
    }

    CloseWindow();
}