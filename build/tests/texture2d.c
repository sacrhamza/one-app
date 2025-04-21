#include <raylib.h>

int main()
{
	Texture2D	sprite;

	InitWindow(800, 450, "raylib window");

	sprite = LoadTexture("one.png");
	while (!WindowShouldClose())
	{
		ClearBackground((Color){133, 133, 0});
		BeginDrawing();
		DrawText("raylib window",  190, 200, 20, LIGHTGRAY);
		DrawTexture(sprite, 0, 0, WHITE);
		EndDrawing();
	}
	CloseWindow();
	return (0);
}
