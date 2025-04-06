#include "one.h"

static t_bcolor get_suitable_colors()
{
	t_bcolor	color;


	color = (t_bcolor){GREEN, GREEN};
	if (GetScreenWidth() < 400)
		color.first_color = RED;
	if (GetScreenHeight() < 400)
		color.second_color = RED;
	return (color);
}

static t_align align(t_screen_dimention screen_dimention, int size)
{
	t_align suitable_padding;

	suitable_padding.horizontal = (screen_dimention.width - size) / 2;
	suitable_padding.vertical = (screen_dimention.height - size) / 2;
	return (suitable_padding);
}

void	display_screen_size_warning()
{
	char	*width_size;
	int	font_size;
	t_bcolor	color;
	char	*height_size;
	t_screen_dimention screen_dimention;

	color = (t_bcolor){GREEN, GREEN};
	font_size = 20;
	screen_dimention = (t_screen_dimention){GetScreenWidth(), GetScreenHeight()};
	width_size = ft_itoa(screen_dimention.width);
	height_size = ft_itoa(screen_dimention.height);

	color = get_suitable_colors();

	DrawText("Widow size too small: ", align(screen_dimention, MeasureText("Window size too small:", 20)).horizontal, 10, font_size, BLACK);
	DrawText("Width = ", align(screen_dimention, MeasureText("Width = ", 20) + MeasureText(width_size, 20)).horizontal, 10 + 1 * 30, 20, BLACK);
	DrawText(width_size, align(screen_dimention, MeasureText("Width = ", 20) + MeasureText(width_size, 20)).horizontal + MeasureText("Width = ", 20), 10 + 30, font_size, color.first_color);
	DrawText("Height = ", 10, 10 + 2 * 30, 20, BLACK);
	DrawText(height_size, 10 + MeasureText("Height = ", font_size), 10 + 2 * 30, font_size, color.second_color);

	free(width_size);
	free(height_size);
}
