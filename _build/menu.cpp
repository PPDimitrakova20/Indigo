#include "menu.h"

void drawMenuText()
{
	DrawText("Press f to play against another player\nPress j to play against computer", (GetScreenWidth() * 2) / 100, (GetScreenHeight() * 2) / 100, 69, GREEN);
}

int getPlayOption()
{
	if (IsKeyPressed(KEY_F))
		return 1;
	else if (IsKeyPressed(KEY_J))
		return 0;
}