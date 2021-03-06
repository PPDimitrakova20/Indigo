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
	Texture2D gameMenuTexture = LoadTexture("./../resources/Menu.png"); // game menu texture

	// Vector stores card type with its coordinates
	std::vector<Card> deckOfCards;

	// Fill vector with cards and initial coordinates
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			deckOfCards.push_back(Card(i, Vector2{ 910, 464 }));
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
	Card coverCard(6, Vector2{ 0,0 });
	Card binaryCard(7, Vector2{ 0,0 });

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

	// Varibles for dealing cards
	dealCords dealSpots[8];
	dealCords* ptrDealPos = getDealCardsPos(dealSpots);
	ptrDealPos = dealSpots;
	bool intialPlayerDecksDrawn = false;

	// Still inder development
	bool p1Pyramid[6][6]{}; 
	bool p2Pyramid[6][6]{};

	while (!WindowShouldClose())
	{
		BeginDrawing();

		// Clean frame buffer
		ClearBackground(RAYWHITE);

		// Check if the a gamemode has been selected
		if (!isGameModeChosen)
		{
			drawMenu(gameMenuTexture);
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
			for (auto& c : deckOfCards)
			{
				c.drawCard();
			}

			// Check if card pile is clicked
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (GetMouseX() >= 910 && GetMouseX() <= 1010) && (GetMouseY() >= 455 && GetMouseY() <= 605))
			{
				continueDrawing = true;
				// Check if the initail Player decks are already drawn
				if (!intialPlayerDecksDrawn)
				{
					// draw the initial player decks
					drawInitailPlayerDecks(dealSpots, index, deckOfCards, whichTurn);
					intialPlayerDecksDrawn = true;
				}
				// Continue player based sequence
				whichTurn = !whichTurn;
				index++;
				// Deal new cards
				if (intialPlayerDecksDrawn)
				{
					dealCards(index, deckOfCards, whichPlaceholder[whichTurn], whichTurn);
				}
			}

			if (!(index > 47))
			{
				// Draw cover cards
				DrawTexture(coverCard.textures[0], 910, 464, RAYWHITE);

				// Keep drawing newly drawn card
				if (continueDrawing)
				{
					// Check if the player attempts to move any of the logical gate cards
					for (int i = 0; i < 48; i++)
					{
						// Check if the mouse is over the and if the left mouse button is pressed
						if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) &&
							(GetMouseX() >= deckOfCards[i].coordinates.x && GetMouseX() <= deckOfCards[i].coordinates.x + 100) &&
							(GetMouseY() >= deckOfCards[i].coordinates.y && GetMouseY() <= deckOfCards[i].coordinates.y + 150) &&
							(deckOfCards[i].coordinates.x <= 909 || deckOfCards[i].coordinates.x  >= 911) && 
							(deckOfCards[i].coordinates.y <= 463 || deckOfCards[i].coordinates.y >= 465) && deckOfCards[i].isPlaced == false)
						{
							// Update the cards position so it moves with the mouse
							deckOfCards[i].coordinates.x = GetMouseX() - 50;
							deckOfCards[i].coordinates.y = GetMouseY() - 75;

							// Check if the card id dragged over a posible clip point
							for (int j = 0; j < 30; j++)
							{
								if ((GetMouseX() >= cords[j].collisionCords.x && GetMouseX() <= cords[j].collisionCords.x + 50) &&
									(GetMouseY() >= cords[j].collisionCords.y && GetMouseY() <= cords[j].collisionCords.y + 50) && cords[i].isFull == false)
								{
									// Stick the card to a position on the player boards
									deckOfCards[i].coordinates.x = cords[j].placementCords.x;
									deckOfCards[i].coordinates.y = cords[j].placementCords.y;
									deckOfCards[i].isPlaced = true;
									cords[i].isFull = true;
								}
							}
						}
					}
				}
				 
				// Starts timer
				startTimer(&textTimer, textLife);
			}
			else
			{
				// Checks if timer hasn't ran out
				if (!timerDone(&textTimer))
				{
					DrawText("Out of cards", 910 - 36 * 2, 464, 36, RED);
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