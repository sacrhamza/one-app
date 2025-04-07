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
	char	*tmp;

	app_size = 8;
	char *str[] = {"brave", "kitty", "nvim", "ghostty", "vivaldi", "firefox", "google-chrome", "zen"};
	count = 0;
	screen_dimention = (t_screen_dimention){300, 300};
	goal = 0;
	i = 0;
	j = 0;
	Color color;

	Texture2D	sprite [app_size];

	int	sprite_count = 0;



	SetConfigFlags(FLAG_WINDOW_RESIZABLE);    // Window configuration flags
	InitWindow(screen_dimention.width, screen_dimention.height, "rectangle");


	while (sprite_count < app_size)
	{
		tmp = ft_strjoin("./assets/logos/", str[sprite_count]);
		image_name = ft_strjoin(tmp, ".png");
		sprite[sprite_count] = LoadTexture(image_name);
		//printf("%d\n", sprite[sprite_count].width);
		free(image_name);
		free(tmp);
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
		if (screen_dimention.width > MAX_SCREEN_WIDTH && screen_dimention.height > MAX_SCREEN_WIDTH)
		{
			while (i < app_size)
			{
				//DrawRectangle(10, 10 + i * 94, screen_dimention.width - 20, 64,(Color) {189,147,249, 255});
				DrawRectangleRounded((Rectangle){10, 10 + i * 94, screen_dimention.width - 20, 64},0.25, 1, (Color) {189,147,249, 255});
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
				color =  YELLOW;
				check_rectangle_collision(5, &collision);
				if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){screen_dimention.width - 150 - 10, 10 + i * 94, 150, 64}))
					color = RED;
				//dRAWrECtangle(screen_dimention.width - 150 - 10, i * 94 + 10, 150, 64, color);
				DrawRectangleRounded((Rectangle){screen_dimention.width - 150 - 10, i * 94 + 10, 150, 64}, 0.25, 1, color);
				DrawText("install", screen_dimention.width - 150 - 10 + (150 - (MeasureText("install", 20))) / 2, i * 94 + 10 + 20, 20, LIGHTGRAY);
				DrawTexture(sprite[i], 20, i * 64 + 10 + i * 30, WHITE);
				DrawText(str[i], 30 + 64, i * 94 + 20, 20, WHITE);
				i++;
			}
		}
		else
			display_screen_size_warning();
		EndDrawing();
	}

	CloseWindow();
}
