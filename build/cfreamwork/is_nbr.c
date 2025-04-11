#include "libft.h"
//#include <stdio.h>
#include "cfreamwork.h"


int	is_nbr(char *str)
{
	int	index;
	int	word_len;

	index = 0;
	word_len = 0;
	while (str[index])
	{
		while (str[index] == ' ')
			index++;
		if (str[index] == '\0')
			break ;
		if (ft_issign(str[index]) && !ft_isdigit(str[index + 1]))
			return (FALSE);
		if (ft_issign(str[index]))
			index++;
		while (str[index] != ' ' && str[index] != '\0')
		{
			if (!ft_isdigit(str[index]))
				return (FALSE);
			index++;
		}
		word_len++;
	}
	if (word_len == 0)
		return (FALSE);
	return (TRUE);
}

//int main()
//{
//	printf("%d\n", is_nbr("      -3 -2 -1      1  1 -1 89 0"));
//	return (0);	
//}
