#include <stdio.h>

typedef struct	s_lst
{
	va_list		*ap;
	const char	*f;
	int			result;
}				t_lst;

int main()
{
	t_lst		lst;
	const char	*a = "dsfdsf";

	lst.f = a;
	printf("%c \n", *(lst.f + 1));
}
