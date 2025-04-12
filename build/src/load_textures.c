#include <one.h>

void	load_logos(char **logo_name, Texture2D *logo_texture)
{
	char	*tmp;
	char	*image_name;
	int		index;

	index = 0;
	while (logo_name[index])
	{
		tmp = ft_strjoin("./assets/logos/", logo_name[index]);
		if (tmp == NULL)
		{
			//add something here
			exit (99);
		}
		image_name = ft_strjoin(tmp, ".png");	
		if (image_name == NULL)
		{
			free(tmp);
			exit (100);
		}
		logo_texture[index] = LoadTexture(image_name);
		free(image_name);
		free(tmp);
		index++;
	}	
}
