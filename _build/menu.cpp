#include "menu.h"

void printMenu()
{
	int counter = 1;
	Texture2D MenuTextures[4] = { LoadTexture("././resources/Arrow.png"), LoadTexture("././resources/Option2.png"), LoadTexture("././resources/Option1.png"), LoadTexture("././resources/Welcome.png") };

	DrawTexture(MenuTextures[3], (1920 - 429) / 2, (1080 - 240) - 600, RAYWHITE);
	DrawTexture(MenuTextures[2], (1920 - 429) / 2, (1080 - 240) - 400, RAYWHITE);
	DrawTexture(MenuTextures[1], (1920 - 429) / 2, (1080 - 240) - 200, RAYWHITE);
	DrawTexture(MenuTextures[0], ((1920 - 429) / 2) - 170, (1080 - 225) - 600, RAYWHITE);
}