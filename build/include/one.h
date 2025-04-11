#ifndef ONE_H
# define ONE_H
# include <raylib.h>
# include <stdbool.h>
# include "cfreamwork.h"
# include "stdio.h"
# define MAX_SCREEN_WIDTH 200
# define MIN_SCREEN_WIDTH 200
# define MIN_SCREEN_HEIGHT 200

typedef struct s_screen_dimention
{
	int	width;
	int	height;
}	t_screen_dimention;

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

//this function based on a condition dipslays a cursor deponds on the condition
//the cursor number
void	set_cursor(t_mouse_state mouse_state);
void	display_screen_size_warning();
#endif

