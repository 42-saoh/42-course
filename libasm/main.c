#include "libasm.h"
#include <string.h>

int main()
{
	char *a = "asd";
	char b[10];
	char c[10];

	b = strcpy(b, a);
	printf("%s\n", b);
	printf("%s\n", a);
	c = strcpy(c, a);
	printf("%s\n", c);
	printf("%s\n", a);
}
