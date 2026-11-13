#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
// int a = ft_printf("%%hi this %s has %d like %s and that a facking %x pointer", "", 21, NULL);
// printf("\n\n");
//
	int x = 4;
	int *p = &x;
//
// int b = printf("%%hi this %p has %d like %s and that a facking %x pointer", p);
// printf("\n %d characters\n\n%d characters", b);
//
	// int a = printf("%%%") ;
	int a = printf("%ksdfghjklkjbvgfertyuih") ;
	printf("\n");
	int b = ft_printf("%ksdfghjklkjbvgfertyuih") ;
	printf("\nthe original :%d\n ", a);
	printf("\nmine         :%d\n ", b);
}
