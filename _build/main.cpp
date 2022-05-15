#include "menu.h"
#include "pvp.h"
#include "drawCards.h"

int main()
{
	const int screenWidth = 1920;
	const int screenHeight = 1080;
	InitWindow(screenWidth, screenHeight, "dev window");
	SetTargetFPS(60);

	/*ToggleFullscreen();*/

	// Variables for choosing gamemode
	int gameMode; // selected gamemode
	bool isGameModeChosen = false;

	// Vector stores card type with its coordinates
	std::vector<std::pair<Card, Vector2>> deckOfCards;

	// Fill vector with cards and initial coordinates
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			deckOfCards.push_back(std::make_pair(Card(i), Vector2{ 910, 464 }));
		}
	}

	// Shuffer the order of cards in the vector
	shuffleDeck(deckOfCards);

	// Variable for drawing the intial binary cards
	int initialBinaries[6]; // Order of intial binary cards
	int* ptr = getIntialBinaryOrder(initialBinaries);
	ptr = initialBinaries;

	// Variables for drawing newly drawn card
	bool continueDrawing = false;

	// Textures
	Texture2D background = LoadTexture("./../resources/Background.png");
	Card coverCard(6);
	Card binaryCard(7);

	// Variables for moving the cards
	int xcord = 910;
	int ycord = 464;
	bool canMoveCard = false;

	// Variables for deckOfCards
	bool isDeckOfCardDrawn = false;
	int index = -1;

	// Timer variables
	float textLife = 2.0f;
	Timer textTimer = { 0 };

	// Dealing cards variables
	int whichPlaceholder[2] = { 0, 0 };
	bool whichTurn = 1;

	// CollisionRectangles variables
	Coordinates cords[30];
	Coordinates* ptrCords = getCollisionRentagelsCords(cords);
	ptrCords = cords;

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
			// Draw background
			DrawTexture(background, 0, 0, RAYWHITE);

			// Draw initial binary cards
			drawInitialBinaries(initialBinaries, screenWidth, screenHeight, binaryCard);

			// Draw every element in the vector
			for (const auto& c : deckOfCards)
			{
				DrawTexture(c.first.texture, c.second.x, c.second.y, RAYWHITE);
			}

			// Check if card pile is clicked
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (GetMouseX() >= 910 && GetMouseX() <= 1010) && (GetMouseY() >= 455 && GetMouseY() <= 605))
			{
				continueDrawing = true;
				// Continue player based sequence
				whichTurn = !whichTurn;
				index++;
				// Deal new cards
				dealCards(index, deckOfCards, whichPlaceholder[whichTurn], whichTurn);
			}

			if (!(index > 47))
			{
				// Draw cover cards
				DrawTexture(coverCard.texture, 910, 464, RAYWHITE);

				// Keep drawing newly drawn card
				if (continueDrawing)
				{
					drawNewlyDrawnCard(deckOfCards[index].first.texture, deckOfCards[index].second.x, deckOfCards[index].second.y);

					/*if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
					{
						deckOfCards[index].second.x = GetMouseX() - 50;
						deckOfCards[index].second.y = GetMouseY() - 50;
					}*/
				}

				// Starts timer
				startTimer(&textTimer, textLife);
			}
			else
			{	
				// Checks if timer hasn't ran out
				if (!timerDone(&textTimer))
				{
					DrawText("Out of cards", 910 - 36*2, 464, 36, RED);	
				}

				// Updates timer
				updateTimer(&textTimer);
			}

			// Draw collisionRectangles 
			// Warning: the color of every rectangle is BLANK(transparent) so they won't visualy display
			for (int i = 0; i < 30; i++)
			{
				DrawRectangle(cords[i].collisionCords.x, cords[i].collisionCords.y, 50, 50, BLANK); // Change this color for visual display
			}

			// Remember to reset the value of continueDrawing after the card moves out of its place !
			isGameModeChosen = true; // Update gamemode
		}

		EndDrawing();
	}

	CloseWindow();
}