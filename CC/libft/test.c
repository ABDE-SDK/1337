#include "libft.h"
#include <stdio.h>

int main()
{
	printf("the result :%s\n", ft_itoa(1337));
	printf("the result :%s\n", ft_itoa(0));
	printf("the result :%s\n", ft_itoa(-1337));
	printf("the result :%s\n", ft_itoa(-2147483648));
	printf("the result :%s\n", ft_itoa(2147483647));
	printf("the result :%s\n", ft_itoa(42));
}
