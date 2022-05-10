#include "menu.h"

bool getPlayOption()
{
	DrawText("Press f to play against another player\nPress j to play against computer", GetScreenWidth() / 2, GetScreenHeight() / 2, 69, GREEN);
	if (IsKeyPressed(KEY_F))
		return 1;
}
