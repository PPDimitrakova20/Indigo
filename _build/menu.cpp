#include "menu.h"

// Draw menu
void drawMenu(Texture2D texute)
{
	DrawTexture(texute, 0, 0, RAYWHITE);
}

// Handle keyboard input for differnt gamemodes
int getPlayOption()
{
	if (IsKeyPressed(KEY_F))
	{
		return 1;
	}
	else if (IsKeyPressed(KEY_G))
	{
		return 0;
	}
	else
	{
		return 0;
	}
}