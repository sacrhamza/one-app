#include <one.h>

static t_bcolor get_suitable_colors()
{
	t_bcolor	color;


	color = (t_bcolor){GREEN, GREEN};
	if (GetScreenWidth() <= MIN_SCREEN_WIDTH)
		color.first_color = RED;
	if (GetScreenHeight() <= MIN_SCREEN_HEIGHT)
		color.second_color = RED;
	return (color);
}

static int align(int dimention, int size)
{
	int suitable_margin;

	suitable_margin = (dimention - size) / 2;
	return (suitable_margin);
}

void	display_screen_size_warning()
{
	char	*width_size;
	char	*height_size;
	int	fontsize;
	t_bcolor	color;
	t_screen_dimention screen_dimention;
	t_margin	margin[2];
	int	char_height;
	int	in_between;

	in_between = 30;
	color = (t_bcolor){GREEN, GREEN};
	fontsize = 20;
	screen_dimention = (t_screen_dimention){GetScreenWidth(), GetScreenHeight()};

	width_size = ft_itoa(screen_dimention.width);
	height_size = ft_itoa(screen_dimention.height);

	color = get_suitable_colors();

	margin[0].horizontal = align(screen_dimention.width, MeasureText("Width = ", fontsize) + MeasureText(width_size, fontsize));
	margin[1].horizontal = align(screen_dimention.width, MeasureText("Height = ", fontsize) + MeasureText(height_size, fontsize));

	char_height = MeasureTextEx(GetFontDefault(), "A", fontsize, 0).y;
	margin[0].vertical = align(screen_dimention.height, char_height);

	DrawText("Widow size too small: ", align(screen_dimention.width, MeasureText("Window size too small:", fontsize)), margin[0].vertical - in_between, fontsize, BLACK);

	//WIDTH
	DrawText("Width = ", margin[0].horizontal, margin[0].vertical, 20, BLACK);
	DrawText(width_size, margin[0].horizontal + MeasureText("Width = ", fontsize), margin[0].vertical, fontsize, color.first_color);

	//HEIGHT
	DrawText("Height = ", margin[1].horizontal, margin[0].vertical + in_between, fontsize, BLACK);
	DrawText(height_size, margin[1].horizontal + MeasureText("Height = ", fontsize), margin[0].vertical + 30, fontsize, color.second_color);

	free(width_size);
	free(height_size);
}
