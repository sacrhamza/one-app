#include <one.h>

int main()
{
	char *str = join(4, "hey", "hey", "hey", "hshadkfaksdjlkajslkjasdlkjsdljdslkjsdalkjflsa");
	printf("%s\n", str);
	free(str);
	return (0);
}
