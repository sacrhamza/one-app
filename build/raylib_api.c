#include <raylib.h>


bool	mouse_collision_rec(Vector2 point, Rectangle rectangle)
{
	return (CeckCollisionPointRec(point, rectangle));
}

void	init_window(t_screen_dimention screen_dimention, const char *title)
{
	InitWindow(screen_dimention.width, screen_dimention.height, title);
}
