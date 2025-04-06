#include "one.h"

void	check_rectangle_collision(int rec_count, int *collision)
{
	int	count;
	t_screen_dimention	screen_dimention;

	screen_dimention = (t_screen_dimention){GetScreenWidth(), GetScreenHeight()};

	count = 0;
	while (count < rec_count)
	{
		if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){screen_dimention.width - 150 - 10, count * 60 + 10, 150, 50}))
			*collision = true;
		count++;
	}
}

int main()
{

	int	count;
	int	app_size;
	int	i;
	int goal;
	int collision;
	int j;
	char	*image_name;
	t_screen_dimention screen_dimention;

	char *str[] = {"brave", "kitty", "nvim", "ghostty", "vivaldi"};
	count = 0;
	app_size = 5;
	screen_dimention = (t_screen_dimention){800, 800};
	goal = 0;
	i = 0;
	j = 0;

	Texture2D	sprite [5];

	int	sprite_count = 0;



	SetConfigFlags(FLAG_WINDOW_RESIZABLE);    // Window configuration flags
	InitWindow(screen_dimention.width, screen_dimention.height, "rectangle");


	while (sprite_count < app_size)
	{
		image_name = ft_strjoin(str[sprite_count], ".png");
		sprite[sprite_count] = LoadTexture(image_name);
		//printf("%d\n", sprite[sprite_count].width);
		free(image_name);
		sprite_count++;
	}

	while (!WindowShouldClose())
	{
		collision = 0;
		screen_dimention.width = GetScreenWidth();
		screen_dimention.height = GetScreenHeight();

		BeginDrawing();

		ClearBackground((Color){68,71,90, 255});

		if (IsKeyPressed('Q'))
			break ;

		i = 0;
		while (i < app_size)
		{
			DrawRectangle(10, 10 + i * 94, screen_dimention.width - 20, 64, BLUE);
			i++;
		}
		i = 0;
		while (i < app_size)
		{
			if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){screen_dimention.width - 150 - 10, 10 + i * 94, 150, 64}))
				collision = 1;
			i++;
		}
		set_cursor((t_mouse_state) {collision, 4, 1});
		i = 0;
		while (i < app_size)
		{
			check_rectangle_collision(5, &collision);
			if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){screen_dimention.width - 150 - 10, 10 + i * 94, 150, 64}))
			{
				DrawRectangle(screen_dimention.width - 150 - 10, i * 94 + 10, 150, 64, RED);
			}
			else
				DrawRectangle(screen_dimention.width - 150 - 10, i * 94 + 10, 150, 64, YELLOW);
			DrawText("install", screen_dimention.width - 150 - 10 + (150 - (MeasureText("install", 20))) / 2, i * 94 + 10 + 20, 20, LIGHTGRAY);
			DrawTexture(sprite[i], 10, i * 64 + 10 + i * 30, WHITE);
			DrawText(str[i], 20 + 64, i * 94 + 20, 20, WHITE);
			i++;
		}
		EndDrawing();
	}

	CloseWindow();
}
