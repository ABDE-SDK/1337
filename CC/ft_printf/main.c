#include <stdio.h>
#include "ft_printf.h"

void	test(char *arr)
{
	arr[0] = '3';
}

int	main()
{
	// dprintf(2, "mine :     %d", ft_printf("%%%"));
	dprintf(2, "\norigin : %d", printf("%%%"));
}
