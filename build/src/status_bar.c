#include <one.h>

void	join_abs_path(char **asset)
{
	char	*str;

	str = *asset;
	*asset = ft_strjoin("/home/hsacr/COMMON_CORE/one-app/build/", str);
	free(str);
}

void	load_status_assets(char **str, Texture2D *assets)
{
	char		*asset;
	char		*tmp;
	int		index;

	index = 0;
		while (str[index])
		{
			tmp = ft_strjoin("assets/icons/", str[index]);
			asset = ft_strjoin(tmp, ".png");
			free(tmp);
			join_abs_path(&asset);
			assets[index] = LoadTexture(asset);
			printf("hey [%s]\n", asset);
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
	char		*str[] = {"apps", "settings", "update", NULL};
	int		icon_size;

	icon_size = 30;

	if (!assets)
	{
		assets = malloc(count_str_array(str) * sizeof(Texture2D));
		load_status_assets(str, assets);
	}
	navigation_item = (t_rectangle){
		(Rectangle){.width = 200, .height = 60},
		.color = GetColor(0x6272A4ff),
		.roundness = 0.1
	};
	tabs_count = 3;
	count = 0;
	bar = (Rectangle){0, screen_dimention.height - 60, screen_dimention.width, 60};
	DrawRectangleRounded(bar, 0.1, 1, (Color){40, 42, 54, 255});
	margin = (screen_dimention.width - (tabs_count * navigation_item.rec.width) - (2 * 50)) / (tabs_count - 1);
	while (count < tabs_count)
	{
		navigation_item.rec.x = (margin + navigation_item.rec.width) * count + 50;
		navigation_item.rec.y = screen_dimention.height - bar.height + (bar.height - navigation_item.rec.height) / 2;
		DrawRectangleRounded(navigation_item.rec, navigation_item.roundness, 100, navigation_item.color);
		//DrawCircle(navigation_item.rec.x + (bar.height / 2), navigation_item.rec.y + (bar.height / 2), 30, navigation_item.color);
		DrawTexture(assets[count], navigation_item.rec.x + ((navigation_item.rec.width - icon_size) / 2), navigation_item.rec.y + ((navigation_item.rec.height - icon_size) / 2), WHITE);
		count++;
	}
}
