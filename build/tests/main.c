#include <raylib.h>

int main()
{
	InitWindow(600, 600, "one");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		DrawRectangleRounded((Rectangle){10, 10, 100, 100}, 0.3f, 1, WHITE);
		EndDrawing();
	}
	CloseWindow();
}
