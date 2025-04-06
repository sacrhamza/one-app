#include "one.h"

void	set_cursor(t_mouse_state mouse_state)
{
	if (mouse_state.condition)
		SetMouseCursor(mouse_state.first_value);	
	else
		SetMouseCursor(mouse_state.second_value);	
}
