#include <one.h>

//
//void	join_abs_path(char **asset)
//{
	//char	*str;
//
	//str = *asset;
	//*asset = ft_strjoin("/home/hsacr/COMMON_CORE/one-app/build/", str);
	//free(str);
//}

void	load_status_assets(char **str, Texture2D *assets, size_t array_length)
{
	char		*asset;
	int		index;

	index = 0;
	while (str[index])
	{
		asset = join(array_length, "assets/icons/", str[index], ".png");
		if (asset == NULL)
			clean_and_exit(2);
		assets[index] = LoadTexture(asset);
		free(asset);
		index++;
	}
}

void	status_bar(t_screen_dimention screen_dimention)
{
	Rectangle	bar;
	int		count;
	int		margin;
	int		tabs_count;
	t_rectangle	navigation_item;
	static Texture2D	*assets;
	char		*str[] = {"apps", "update", "settings", NULL};
	int		icon_size;

	icon_size = 30;

	tabs_count = count_str_array(str);
	if (!assets)
	{
		assets = malloc(tabs_count * sizeof(Texture2D));
		load_status_assets(str, assets, tabs_count);
	}
	navigation_item = (t_rectangle){
		(Rectangle){.width = 200, .height = 60},
			.color = GetColor(0x6272A4ff),
			.roundness = 0.1
	};
	count = 0;
	bar = (Rectangle){0, screen_dimention.height - 60, screen_dimention.width, 60};
	DrawRectangleRounded(bar, 0.1, 1, GetColor(0x6272A4ff));
	//margin = (screen_dimention.width - (tabs_count * navigation_item.rec.width) - (2 * 50)) / (tabs_count - 1);
	margin = screen_dimention.width - (2 * 50 + 3 * 30);
	int hey_size = (2 * 150 + 3 * 30);
	int	hey = screen_dimention.width - hey_size;
	while (count < tabs_count)
	{
		navigation_item.rec.x = hey / 2 + 150 * count + count * 30 * (count > 0);
		navigation_item.rec.y = screen_dimention.height - bar.height + (bar.height - navigation_item.rec.height) / 2;
		//DrawCircle(navigation_item.rec.x + (bar.height / 2), navigation_item.rec.y + (bar.height / 2), 30, navigation_item.color);
		DrawTexture(assets[count], navigation_item.rec.x, navigation_item.rec.y, WHITE);
		count++;
	}
}
