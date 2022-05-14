#include "menu.h"
#include "pvp.h"
#include "drawCards.h"

typedef struct
{
	float Lifetime;
}Timer;

// start or restart a timer with a specific lifetime
void startTimer(Timer* timer, float lifetime)
{
	if (timer != NULL)
	{
		timer->Lifetime = lifetime;
	}
}

// update a timer with the current frame time
void updateTimer(Timer* timer)
{
	// subtract this frame from the timer if it's not allready expired
	if (timer != NULL && timer->Lifetime > 0)
	{
		timer->Lifetime -= GetFrameTime();
	}
}

// check if a timer is done.
bool timerDone(Timer* timer)
{
	if (timer != NULL)
	{
		return timer->Lifetime <= 0;
	}

	return false;
}

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
	shuffleDeck(deckOfCard);

	// Variable for drawing the intial binary cards
	int initialBinaries[6]; // Order of intial binary cards
	int* ptr = getIntialBinaryOrder(initialBinaries);
	ptr = initialBinaries;

	// Variables for drawing newly drawn card
	bool continueDrawing = false;

	Texture2D background = LoadTexture("./../resources/Background.png");
	Card coverCard(6);
	Card binaryCard(7);

	// Variables for moving the cards
	int xcord = 910;
	int ycord = 464;
	bool canMoveCard = false;

	bool isDeckOfCardDrawn = false;

	int index = -1;
	float textLife = 2.0f;
	Timer textTimer = { 0 };

	int whichPlaceholder[2] = { 0, 0 };
	bool whichTurn = 1;

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
				whichTurn = !whichTurn;
				index++;
				dealCards(index, deckOfCard, whichPlaceholder[whichTurn], whichTurn);
			}

			if (!(index > 47))
			{
				// Draw cover cards
				DrawTexture(coverCard.texture, 910, 464, RAYWHITE);

				// Keep drawing newly drawn card
				if (continueDrawing)
				{
					drawNewlyDrawnCard(deckOfCard[index].first.texture, deckOfCard[index].second.x, deckOfCard[index].second.y);

					/*if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
					{
						deckOfCard[index].second.x = GetMouseX() - 50;
						deckOfCard[index].second.y = GetMouseY() - 50;
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
			// Remember to reset the value of continueDrawing after the card moves out of its place !
			isGameModeChosen = true; // Update gamemode
		}

		EndDrawing();
	}

	CloseWindow();
}