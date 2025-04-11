#include "one.h"

void	load_logos(char **logo_name, Texture2D *logo_texture)
{
	char	*tmp;
	char	*image_name;
	int		index;

	index = 0;
	while (logo_name[index])
	{
		tmp = ft_strjoin("./assets/logos/", logo_name[index]);
		if (tmp == NULL)
		{
			//add something here
			exit (99);
		}
		image_name = ft_strjoin(tmp, ".png");	
		if (image_name == NULL)
		{
			free(tmp);
			exit (100);
		}
		logo_texture[index] = LoadTexture(image_name);
		free(image_name);
		free(tmp);
		index++;
	}	
}

Color	button_state_color(t_state state)
{
	Color button_colors[4];

	button_colors[uninstalled] = (Color){64, 112, 244, 255};
	button_colors[installed] = RED;

	return (button_colors[state]);
}

int main()
{

	int	count;
	int	app_size;
	int	i;
	int goal;
	int collision;
	int j;
	t_screen_dimention screen_dimention;
	Rectangle	box;
	int		parent_box_size = 64;

	app_size = 6;
	char *str[] = {"nvim", "ghostty", "vivaldi", "firefox", "zen", "firefox-developer", NULL};
	count = 0;
	screen_dimention = (t_screen_dimention){800, 800};
	goal = 0;
	i = 0;
	j = 0;
	Color color;
	box = (Rectangle){.width = 100, .height = 35};

	Texture2D	sprite [app_size];
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);    // Window configuration flags
	InitWindow(screen_dimention.width, screen_dimention.height, "rectangle");
	SetTargetFPS(60);

	//load logos for every package
	load_logos(str, sprite);

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
				if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){screen_dimention.width - box.width - 10, i * (parent_box_size + 30) + 10 + ((parent_box_size - box.height) / 2), box.width, box.height}))
					collision = 1;
				i++;
			}

			set_cursor((t_mouse_state) {collision, MOUSE_CURSOR_POINTING_HAND, MOUSE_CURSOR_ARROW});

			i = 0;
			while (i < app_size)
			{
				color =  button_state_color(0);
				if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){screen_dimention.width - box.width - 10, i * (parent_box_size + 30) + 10 + ((parent_box_size - box.height) / 2), box.width, box.height}))
					color = GetColor(0x70e000FF);

				//IMPORTANT
				DrawRectangleRounded((Rectangle){screen_dimention.width - box.width - 10, i * (parent_box_size + 30) + 10 + ((parent_box_size - box.height) / 2), box.width, box.height}, 0.1f, 1, color);

				//TEXT: INSTALL REMOVE INSTALLED REMOVED
				DrawText("install", screen_dimention.width - box.width - 10 + (box.width - (MeasureText("install", 15))) / 2, i * (parent_box_size + 30) + 10 + (parent_box_size - 15) / 2, 15, BLACK);

				DrawTexture(sprite[i], 10, i * parent_box_size + (parent_box_size - 64)/2 + 10 + i * 30, WHITE);
				DrawText(str[i], 20 + 64, i * (parent_box_size + 30) + 20, 20, WHITE);
				i++;
			}
		}
		else
			display_screen_size_warning();
		EndDrawing();
	}

	CloseWindow();
}
