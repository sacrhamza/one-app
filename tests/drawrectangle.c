#include <raylib.h>
#include <stdio.h>


int main()
{
	InitWindow(500, 500, "rectangle");

	int	i = 200, j = 0, k = 0, l = 255;

	Color color = (Color){i, j, k};

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground((Color){68,71,90, 255});	

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_UP))
		{
			i += 20, j += 20, k += 20;
		}
		int i = 0;
		while (i < 5)
		{
			DrawRectangle(500 - 150 - 10, i * 60 + 10, 150, 50, (Color){i, j, k, l});
			i++;
		}
		EndDrawing();
	}

	CloseWindow();
}
