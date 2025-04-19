#include <one.h>

static char	*join_args(va_list list, char *joined_string, size_t nmember)
{
	char	*string;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (i < nmember)
	{
		string = va_arg(list, char *);
		ft_strcpy(joined_string + len, string);
		len += ft_strlen(string);
		i++;
	}
	return (joined_string);
}


static size_t	args_total_len(va_list list, size_t nmember)
{
	size_t	i;
	size_t	total_len;
	char	*string;

	i = 0;
	total_len = 0;
	while (i < nmember)
	{
		string = va_arg(list, char *);
		total_len += ft_strlen(string);
		i++;
	}
	return (total_len);
}

char	*join(size_t nmember, ...)
{
	va_list	list;
	va_list	cpy_list;
	char	*joined_string;
	size_t	size;

	va_start(list, nmember);
	va_copy(cpy_list, list);
	size = args_total_len(cpy_list, nmember);
	joined_string = ft_calloc(size + 1, sizeof(char));
	if (joined_string == NULL)
		return (NULL);
	join_args(list, joined_string, nmember);
	return (joined_string);
}
