#include <stdio.h>
#include "ft_printf.h"

void	test(char *arr)
{
	arr[0] = '3';
}

int	main()
{
	char te[] =  {'1', '2', '3'};
	printf("%s\n", te);
	test(te);
	printf("%s", te);

}
