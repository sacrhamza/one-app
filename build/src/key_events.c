#include <one.h>

void	up_down_event(int *position, int speed, t_app_canvas app_canvas)
{
	int	factor;

	factor = 0;
	if (IsKeyDown(KEY_UP))
	{
		while (*position != 0 && factor < speed)
		{
			*position += factor;
			factor += 10;
		}
	}
	else if (IsKeyDown(KEY_DOWN))
	{
		while ((-1 * *position) < ((app_canvas.apps_number - 1)
			* (app_canvas.app_rec_dimention.height + app_canvas.margin.vertical)
			+ app_canvas.app_rec_dimention.height)
		- GetScreenHeight() + app_canvas.padding && factor < speed)
	{
			*position -= factor;
			factor += 10;
	}
	}
}
