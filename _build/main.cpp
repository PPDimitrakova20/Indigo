#include "menu.h"
#include "pvp.h"
#include "drawCards.h"
#include <vector>
#include <utility>

int main()
{
	const int screenWidth = 1920;
	const int screenHeight = 1080;
	InitWindow(screenWidth, screenHeight, "dev window");
	SetTargetFPS(60);

	/*ToggleFullscreen();*/

	//srand(time(0)); // Randomise seed for rand()

	// Variables for choosing gamemode
	int gameMode; // selected gamemode
	bool isGameModeChosen = false;

	// Vector stores card type with its coordinates
	std::vector<std::pair<Card, Vector2>> deckOfCard;

	// Fill vector with cards and initial coordinates
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			deckOfCard.push_back(std::make_pair(Card(i), Vector2{ 910, 464 }));
		}
	}

	// Variable for drawing the intial binary cards
	int initialBinaries[6]; // Order of intial binary cards
	int* ptr = getIntialBinaryOrder(initialBinaries);
	ptr = initialBinaries;

	// Variables for drawing newly drawn card
	bool continueDrawing = false;

	Texture2D background = LoadTexture("././resources/Background.png");
	Card coverCard(6);
	Card binaryCard(7);

	// Variables for moving the cards
	int xcord = 910;
	int ycord = 464;
	bool canMoveCard = false;

	bool isDeckOfCardDrawn = false;

	int index = -1;

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
			drawInitialBinaries(initialBinaries, screenWidth, screenHeight, binaryCard);

			for (const auto& c : deckOfCard)
			{
				DrawTexture(c.first.texture, c.second.x, c.second.y, RAYWHITE);
			}

			// Check if card pile is clicked
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (GetMouseX() >= 910 && GetMouseX() <= 1010) && (GetMouseY() >= 455 && GetMouseY() <= 605))
			{
				continueDrawing = true;
				index++;
			}

			//DrawTexture(coverCard.texture, 910, 464, RAYWHITE);
			if (!(index > 47))
			{
				// Keep drawing newly drawn card
				if (continueDrawing)
				{
					drawNewlyDrawnCard(deckOfCard[index].first.texture, deckOfCard[index].second.x, deckOfCard[index].second.y);
					if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
					{
						deckOfCard[index].second.x = GetMouseX() - 50;
						deckOfCard[index].second.y = GetMouseY() - 50;
					}
				}
			}
			else
			{
				DrawText("Out of cards", 910 - 36*4, 464, 36, RED);
			}

			// Remember to reset the value of continueDrawing after the card moves out of its place !
			isGameModeChosen = true; // Update gamemode
		}

		EndDrawing();
	}

	CloseWindow();
}