#ifndef ONE_H
# define ONE_H
# include <raylib.h>
# include <stdbool.h>
# include <stdio.h>
# include "cfreamwork.h"
# define MAX_SCREEN_WIDTH 400
# define MIN_SCREEN_WIDTH 400
# define MIN_SCREEN_HEIGHT 400

typedef struct s_screen_dimention
{
	int	width;
	int	height;
}	t_screen_dimention;

typedef struct s_dimention
{
	int	width;
	int	height;
}	t_dimention;

typedef struct s_mouse_state
{
	bool	condition;
	int	first_value;
	int	second_value;
}	t_mouse_state;

typedef struct s_bcolor
{
	Color first_color;
	Color second_color;
}	t_bcolor;

typedef struct s_margin
{
	int	horizontal;
	int	vertical;
}	t_margin;

typedef	enum e_state
{
	uninstalled,
	installed
}	t_state;

typedef struct s_package
{
	char	*name;
	t_state	state;
	char	*url_source;
	char	*description;
}	t_package;

typedef struct s_app_canvas
{
	t_margin margin;
	int	padding;
	int	apps_number;
	t_dimention	app_rec_dimention;
}	t_app_canvas;

//this function based on a condition dipslays a cursor deponds on the condition
//the cursor number
void	set_cursor(t_mouse_state mouse_state);
void	display_screen_size_warning();
void	mouse_wheel_move(int *position, int speed, t_app_canvas app_canvas);
void	load_logos(char **logo_name, Texture2D *logo_texture);
void	up_down_event(int *position, int speed, t_app_canvas app_canvas);
#endif

