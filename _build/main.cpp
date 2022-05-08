#include "raylib.h"
#include "menu.h"
#include <stdlib.h> // rand, srand
#include <time.h> // time

int main()
{
    InitWindow(1920, 1080, "dev window");
    SetTargetFPS(60);

    ToggleFullscreen();

    // Load textures for cards -------------------------------
        // Load OR cards ---------------------------------------------------------------
        Texture2D cardOr0 = LoadTexture("././resources/OR 0 Card.png");
        Texture2D cardOr0Inverted = LoadTexture("././resources/OR 0 Card Inverted.png");
        Texture2D cardOr1 = LoadTexture("././resources/OR 1 Card.png");
        Texture2D cardOr1Inverted = LoadTexture("././resources/OR 1 Card Inverted.png");
        // -----------------------------------------------------------------------------

        // Load AND cards -----------------------------------------------------------
        Texture2D cardAnd0 = LoadTexture("././resources/AND 0.png");
        Texture2D cardAnd0Inverted = LoadTexture("././resources/AND 2 Inverted.png");
        Texture2D cardAnd1 = LoadTexture("././resources/AND 1.png");
        Texture2D cardAnd1Inverted = LoadTexture("././resources/AND 3 Inverted.png");
        // --------------------------------------------------------------------------

        // Load XOR cards ----------------------------------------------------------------
        Texture2D cardXor0 = LoadTexture("././resources/XOR 0 Card.png");
        Texture2D cardXor0Inverted = LoadTexture("././resources/XOR 0 Card Inverted.png");
        Texture2D cardXor1 = LoadTexture("././resources/XOR 1 Card.png");
        Texture2D cardXor1Inverted = LoadTexture("././resources/XOR 1 Card Inverted.png");
        // -------------------------------------------------------------------------------

        // Load Intial binaries and Not card ---------------------------------------------------------
        Texture2D initialBinary = LoadTexture("././resources/Intial Binary Card.png");
        Texture2D initialBinaryInverted = LoadTexture("././resources/Intial Binary Card Inverted.png");
        Texture2D notCard = LoadTexture("././resources/Not Card.png");
        // -------------------------------------------------------------------------------------------

        // Load Cover card -----------------------------------------------
        Texture2D coverCard = LoadTexture("././resources/Cover Card.png");
        // ---------------------------------------------------------------
    
    // -------------------------------------------------------
        srand(time(NULL));

        bool initialBinaries[6]; // array of 0s and 1s

        float posX = 50;

        for (int i = 0; i < 6; i++)
        {
            initialBinaries[i] = rand() % 2; // Assign random value between 0 and 1
        }

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw the 6 iniatial binaries

        // Loop between array elements
        for (int i = 0; i < 6; i++)
        {
            // Check if value equals 0
            if (initialBinaries[i] == 0)
            {
                // Draw corresponding texture
                DrawTextureEx(initialBinary, Vector2{ posX, 0 }, 0, 0.25, RAYWHITE);
            }
            else
            {
                // Draw corresponding texture
                DrawTextureEx(initialBinaryInverted, Vector2{ posX, 0 }, 0, 0.25, RAYWHITE);
            }

            posX += 150;
        }

        // Reset posX
        posX = 0;
        
        EndDrawing();
    }

    CloseWindow();
}


/* Structs
struct Ball
{
    float x, y;
    float speedX, speedY;
    float radius;

    void Draw()
    {
        DrawCircle((int)x, (int)y, radius, WHITE);

    }
};

struct Paddle
{
    float x, y;
    float speed;
    float width, height;

    Rectangle GetRect()
    {
        return Rectangle{ x - width / 2, y - height / 2 , 10, 100 };
    }

    void Draw()
    {
        DrawRectangleRec(GetRect(), WHITE);
    }
};
*/

/* Pong Ball
    InitWindow(800, 600 ,"Pong");
    SetWindowState(FLAG_VSYNC_HINT);

    Ball ball;
    ball.x = GetScreenWidth() / 2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    ball.radius = 5;
    ball.speedX = 300;
    ball.speedY = 300;

    Paddle leftPaddle;

    leftPaddle.x = 50;
    leftPaddle.y = GetScreenHeight() / 2;
    leftPaddle.width = 10;
    leftPaddle.height = 100;
    leftPaddle.speed = 500;

    Paddle rightPaddle;

    rightPaddle.x = GetScreenWidth() - 50;
    rightPaddle.y = GetScreenHeight() / 2;
    rightPaddle.width = 10;
    rightPaddle.height = 100;
    rightPaddle.speed = 500;

    const char* winnerText = nullptr;

    while (!WindowShouldClose())
    {
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();

        if (ball.y < 0)
        {
            ball.y = 0;
            ball.speedY *= -1;
        }
        if (ball.y > GetScreenHeight())
        {
            ball.y = GetScreenHeight();
            ball.speedY *= -1;
        }

        if (leftPaddle.y > 600)
        {
            leftPaddle.y = 599;
        }
        if (leftPaddle.y < 0)
        {
            leftPaddle.y = 1;
        }
        if (rightPaddle.y > 600)
        {
            rightPaddle.y = 599;
        }
        if (rightPaddle.y < 0)
        {
            rightPaddle.y = 1;
        }

        if (IsKeyDown(KEY_W))
        {
            leftPaddle.y -= leftPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_S))
        {
            leftPaddle.y += leftPaddle.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_UP))
        {
            rightPaddle.y -= rightPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_DOWN))
        {
            rightPaddle.y += rightPaddle.speed * GetFrameTime();
        }

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, leftPaddle.GetRect()))
        {
            if (ball.speedX < 0)
            {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * ball.speedX;
            }
            
        }
        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, rightPaddle.GetRect()))
        {
            if (ball.speedX > 0)
            {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * - ball.speedX;
            }
        }

        if (ball.x < 0)
        {
            winnerText = "Right Player Wins!";
        }
        if (ball.x > GetScreenWidth())
        {
            winnerText = "Left Player Wins!";
        }

        if (winnerText && IsKeyDown(KEY_SPACE))
        {
            ball.x = GetScreenWidth() / 2;
            ball.y = GetScreenHeight() / 2;
            ball.speedX = 300;
            ball.speedY = 300;
            winnerText = nullptr;
        }

        BeginDrawing();

            ClearBackground(BLACK);

            ball.Draw();
            leftPaddle.Draw();
            rightPaddle.Draw();

            if (winnerText)
            {
                int textwidth = MeasureText(winnerText, 60);
                DrawText(winnerText, GetScreenWidth() / 2 - textwidth / 2 , GetScreenHeight() / 2 - 30, 60, YELLOW);
            }
            DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();


*/