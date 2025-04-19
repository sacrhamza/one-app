#include <one.h>

void	load_logos(char **logo_name, Texture2D *logo_texture)
{
	char	*image_name;
	size_t		index;

	index = 0;
	while (logo_name[index])
	{
		image_name = join(3, "./assets/logos/", logo_name[index], ".png");
		logo_texture[index] = LoadTexture(image_name);
		free(image_name);
		index++;
	}	
}
