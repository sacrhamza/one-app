#include <raylib.h>

int main()
{
	InitWindow(800, 450, "raylib window");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		DrawText("raylib window",  190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}
	CloseWindow();
	return (0);
}
