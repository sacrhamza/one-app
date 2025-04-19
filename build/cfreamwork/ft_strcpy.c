#include "libft.h"

char	*ft_strcpy(char *dest, const char *source)
{
	size_t	i;

	if (dest == NULL || source == NULL)
		return (0);
	i = 0;
	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
