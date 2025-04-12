#include <one.h>
//lfo9 1
//ltehet 1
#define GO_UP -1
#define GO_DOWN 1

void	mouse_wheel_move(int *position, int speed, t_app_canvas app_canvas)
{
	int	mouse_wheel_position;
	int	factor;

	factor = 0;
	mouse_wheel_position = GetMouseWheelMove();
	while (factor < speed)
	{
		if ((mouse_wheel_position != GO_DOWN || *position <= -10)
				&& !(mouse_wheel_position < 0 && ((-1 * *position) > ((app_canvas.apps_number - 1)
				* (app_canvas.app_rec_dimention.height + app_canvas.margin.vertical)
					- GetScreenHeight() + app_canvas.app_rec_dimention.height + app_canvas.padding))))
		{
			*position += mouse_wheel_position * factor;
		}
		else
			break;
		factor += 10;
	}
	//printf("%d %d\n", *position, (app_canvas.apps_number - 1) * (app_canvas.app_rec_dimention.height + app_canvas.margin.vertical) - GetScreenHeight() + app_canvas.app_rec_dimention.height);
}
