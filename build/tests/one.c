#include <raylib.h>
#include <stdio.h>


int main()
{

	int	count;
	int	width;
	int	height;
	int	i = 200, j = 0, k = 0, l = 255;
	int goal;
	int i;
	int collistion;
	int j;

	char *str[] = {"brave", "kitty", "nvim", "ghostty", "vivaldi"};
	count = 0;
	width = 800;
	height = 800;
	goal = 0;
	i = 0;
	j = 0;
	collistion = 0;


	SetConfigFlags(FLAG_WINDOW_RESIZABLE);    // Window configuration flags
	InitWindow(width, height, "rectangle");

	Color color = (Color){i, j, k};


	while (!WindowShouldClose())
	{
		width = GetScreenWidth();
		height = GetScreenHeight();
		BeginDrawing();
		ClearBackground((Color){68,71,90, 255});

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_UP))
			i += 20, j += 20, k += 20;

		if (IsKeyPressed('Q'))
			break ;


		while (i < 5)
		{
			while (j < 5)
			{
				if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){width - 150 - 10, j * 60 + 10, 150, 50}))
					collistion = 1;
				j++;
			}

			if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){width - 150 - 10, i * 60 + 10, 150, 50}))
				DrawRectangle(width - 150 - 10, i * 60 + 10, 150, 50, RED);
			else if (goal == i  && !collistion)
			{
				DrawRectangle(width - 150 - 10, goal * 60 + 10, 150, 50, RED);
				//printf("hey %d\n", count++);
			}
			else
				DrawRectangle(width - 150 - 10, i * 60 + 10, 150, 50, (Color){i, j, k, l});
			DrawText(str[i], width - 150 + 10, i * 60 + 20, 20, LIGHTGRAY);
			i++;
		}
		if (IsKeyPressed('J'))
		{
			goal++;
			goal = goal % 5;
		}
		if (IsKeyPressed('K'))
		{
			goal--;
			goal = goal % 5;
			if (goal < 0)
				goal = 4;
		}
		EndDrawing();
	}


	CloseWindow();
}
