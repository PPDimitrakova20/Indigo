#include "pvp.h"

Card::Card(int type)
{
	char* textureSource[8] = {
	"./../resources/OR0.png",
	"./../resources/OR1.png",
	"./../resources/AND0.png",
	"./../resources/AND1.png",
	"./../resources/XOR0.png",
	"./../resources/XOR1.png",
	"./../resources/CoverCard.png",
	"./../resources/IntialBinaryCard.png"
	};
	this->cardType = type;
	texture = LoadTexture(textureSource[cardType]);
}

//Card::~Card()
//{
//    UnloadTexture(texture);
//}

// Get the order of the 6 intial binaries
int* getIntialBinaryOrder(int Array[6])
{
	for (int i = 0; i < 6; i++)
	{
		Array[i] = rand() % 2; // Assign random value between 0 and 1
	}

	return Array;
}

// Shuffles cards
void shuffleDeck(std::vector<std::pair<Card, Vector2>>& deck)
{
	int randShuffles = rand() % 5 + 1;

	for (int i = 0; i < randShuffles; i++)
	{
		int randNum = rand() % deck.size() + 1;
		for (int j = 0; j < randNum; j++)
		{
			std::swap(deck[j], deck[rand() % deck.size()]);
		}
	}
}

// Deal cards
void dealCards(int& index, std::vector<std::pair<Card, Vector2>>& deckOfCard, int& whichPlaceholder, bool whichTurn)
{
	// Check if card index is out of bounds
	if (index < 48)
	{
		// Check whose turn it is
		if (whichTurn)
		{
			// Check if whichPlaceholder is out of bounds
			if (whichPlaceholder > 3)
			{
				whichPlaceholder = 0;
			}
			// Set card coordinates according to placeHolder
			deckOfCard[index].second.x = 760 + (135 * whichPlaceholder);
			deckOfCard[index].second.y = 96;
			whichPlaceholder++;
		}
		else
		{
			// Check if whichPlaceholder is out of bounds
			if (whichPlaceholder > 3)
			{
				whichPlaceholder = 0;
			}
			// Set card coordinates according to placeHolder
			deckOfCard[index].second.x = 655 + (135 * whichPlaceholder);
			deckOfCard[index].second.y = 833;
			whichPlaceholder++;
		}
	}
}

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

// Get collisionRentagels X and Y
Coordinates* getCollisionRentagelsCords(Coordinates cords[30])
{
	// Player1's side strating X and Y
	int p1Xspacing = 0;
	int p1Yspacing = 75;

	// Player1's side strating X and Y
	int p2Xspacing = 0;
	int p2Yspacing = 955;

	// Additonal variables
	int cutOff = 0; // how many colounm will be saved in the array
	int temp; // spacing between rectagles on each line
	int index = 0; // the index on which the next cords will be saved on
	Vector2 disposition = {0,0}; // accounts for horizontal and vertical disposition

	// Player1's CollisionRentagels cords
	for (int i = 0; i < 5; i++)
	{	
		// Update X and Y and reset temp for next row
		p1Xspacing = 105 + i * 57;
		p1Yspacing += 160;
		temp = 0;

		// Assign value for horizontal and vertical disposition
		switch (i)
		{
		case 0:
			disposition.x = 0;
			disposition.y = 0;
			break;
		case 1:
			disposition.x = 0;
			disposition.y = 2;
			break;
		case 2:
		case 3:
			disposition.x = 1;
			disposition.y = 3;
			break;
		case 4:
			disposition.x = 2;
			disposition.y = 3;
			break;
		}

		// Assign X and Y to array index
		for (int j = 0; j < 5 - cutOff; j++)
		{
			// Assign X and Y for collision rectangles
			cords[index].collisionCords.x = p1Xspacing + temp * 115;  
			cords[index].collisionCords.y = p1Yspacing;

			// Assign X and Y for placement
			cords[index].placementCords.x = cords[index].collisionCords.x - 26 + disposition.x;
			cords[index].placementCords.y = cords[index].collisionCords.y - 48 + disposition.y;
			temp++;

			// Move on to next index
			index++;
		}

		// Update cutOff
		cutOff++;
	}

	// reset cutOff
	cutOff = 0;

	// Player2's CollisionRentagels cords
	for (int i = 0; i < 5; i++)
	{
		// Update X and Y and reset temp for next row
		p2Xspacing = 1293 + i * 57;
		p2Yspacing -= 160;
		temp = 0;

		// Assign value for horizontal and vertical disposition
		switch (i)
		{
		case 0:
			disposition.x = 2;
			disposition.y = 1;
			break;
		case 1:
			disposition.x = 3;
			disposition.y = 3;
			break;
		case 2:
		case 3:
			disposition.x = 4;
			disposition.y = 4;
			break;
		case 4:
			disposition.x = 5;
			disposition.y = 5;
			break;
		}

		// Assign X and Y to array index
		for (int j = 0; j < 5 - cutOff; j++)
		{
			// Assign X and Y for collision rectangles
			cords[index].collisionCords.x = p2Xspacing + temp * 115;
			cords[index].collisionCords.y = p2Yspacing;

			// Assign X and Y for placement
			cords[index].placementCords.x = cords[index].collisionCords.x - 26 + disposition.x;
			cords[index].placementCords.y = cords[index].collisionCords.y - 48 - disposition.y;
			temp++;

			// Move on to next index
			index++;
		}

		// Update cutOff
		cutOff++;
	}

	return cords;
}

