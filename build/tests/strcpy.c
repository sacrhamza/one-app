#include <string.h>
#include <stdio.h>

int main()
{
	char str[4] = "0000";
	strcpy(str, "1");
	printf("%s\n", str);
}
