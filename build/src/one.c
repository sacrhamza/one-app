#include <one.h>

Color	button_state_color(t_state state)
{
	Color button_colors[4];

	button_colors[uninstalled] = (Color){64, 112, 244, 255};
	button_colors[installed] = RED;

	return (button_colors[state]);
}

int	count_str_array(char **str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
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

	t_app_canvas	app_canvas;
	Font	jetbrain_font;

	char *str[] = {"android-studio", "atom", "bitwarden", "blender", "brave", "code", "codium", "cursor", "datagrip", "discord", "edge", "ffmpeg", "firefox-developer", "firefox", "ghostty", "google-chrome", "kitty", "krita", "min", "netbeans", "nvim", "obsidian", "opera", "phpstorm", "postman", "qbittorent", "rider", "rubymine", "rustover", "seamonkey", "shotcut", "simplenote", "slack", "telegram", "theia", "thunderbird", "tor", "vivaldi", "warp", "waveterm", "webstorm", "wezterm", "zed", "zen", NULL};
	app_size = count_str_array(str);

	app_canvas = (t_app_canvas){
		.margin = (t_margin){0, 10},
		.padding = 10,
		.apps_number = count_str_array(str),
		.app_rec_dimention = (t_dimention){0, 64}
			
	};

	count = 0;
	screen_dimention = (t_screen_dimention){800, 800};
	goal = 0;
	i = 0;
	j = 0;
	int	mouse_wheel = 0;
	Color color;
	box = (Rectangle){.width = 100, .height = 35};

	Texture2D	sprite [app_size];

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);    // Window configuration flags

	InitWindow(screen_dimention.width, screen_dimention.height, "one");
	SetTargetFPS(60);

	SetWindowMinSize(300, 300);

	//load logos for every package
	load_logos(str, sprite);

	//load Jet Brain Regular Font

	jetbrain_font = LoadFontEx("/home/hsacr/COMMON_CORE/one-app/build/assets/fonts/JetBrainsMonoNerdFont-Regular.ttf", 22, 0, 250);

	SetTextLineSpacing(16);

	while (!WindowShouldClose())
	{
		collision = 0;

		screen_dimention.width = GetScreenWidth();
		screen_dimention.height = GetScreenHeight();

		BeginDrawing();
		ClearBackground((Color){22, 22, 23, 255});

		if (IsKeyPressed(KEY_Q))
			break ;

		i = 0;
		if (screen_dimention.width > MAX_SCREEN_WIDTH && screen_dimention.height > MAX_SCREEN_WIDTH)
		{
			//HANDLE MOUSE WHEEL MOVES [ UP DOWN ]
			mouse_wheel_move(&mouse_wheel, 60, app_canvas);

			//HANDLE KEY EVENT [ KEY_UP KEY_DOWN ]
			up_down_event(&mouse_wheel, 20, app_canvas);

			while (i < app_size)
			{
				if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){screen_dimention.width - box.width - 10, i * (parent_box_size + app_canvas.margin.vertical) + 10 + ((parent_box_size - box.height) / 2) + mouse_wheel, box.width, box.height}))
					collision = 1;
				i++;
			}
			set_cursor((t_mouse_state) {collision, MOUSE_CURSOR_POINTING_HAND, MOUSE_CURSOR_ARROW});

			i = 0;
			while (i < app_size)
			{
				color =  button_state_color(i % 2);
				if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){screen_dimention.width - box.width - 10, i * (parent_box_size + app_canvas.margin.vertical) + 10 + ((parent_box_size - box.height) / 2) + mouse_wheel, box.width, box.height}))
					color = GetColor(0x70e000FF);

				//IMPORTANT
				DrawRectangleRounded((Rectangle){screen_dimention.width - box.width - 10, i * (parent_box_size + app_canvas.margin.vertical) + 10 + ((parent_box_size - box.height) / 2) + mouse_wheel, box.width, box.height}, 0.1f, 1, color);

				//TEXT: INSTALL REMOVE INSTALLED REMOVED
				DrawText("install", screen_dimention.width - box.width - 10 + (box.width - (MeasureText("install", 15))) / 2, i * (parent_box_size + app_canvas.margin.vertical) + 10 + (parent_box_size - 15) / 2 + mouse_wheel, 15, BLACK);

				DrawTexture(sprite[i], 10, i * parent_box_size + (parent_box_size - 64)/2 + 10 + i * app_canvas.margin.vertical + mouse_wheel, WHITE);
				//DrawText(str[i], 20 + 64, i * (parent_box_size + 30) + 20 + mouse_wheel, 20, WHITE);
				DrawTextEx(jetbrain_font, str[i], (Vector2){15 + 64, i * (parent_box_size + app_canvas.margin.vertical) + 15 + mouse_wheel}, (float)jetbrain_font.baseSize, 2, WHITE);
				i++;
			}
			status_bar(screen_dimention);
		}
		else
			display_screen_size_warning();
		EndDrawing();
	}

	CloseWindow();
}
