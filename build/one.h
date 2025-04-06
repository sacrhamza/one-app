#ifndef ONE_H
# define ONE_H
# include <raylib.h>
# include <stdbool.h>
# include "cfreamwork.h"
# include "stdio.h"
# define MAX_SCREEN_WIDTH 400

typedef struct screen_dimention
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

//this function based on a condition dipslays a cursor deponds on the condition
//the cursor number
void set_cursor(t_mouse_state mouse_state);
#endif

