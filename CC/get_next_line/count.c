int counter(void)
{
	static int n = 0; /* set to 0 once, not on every call */
	n++;
	return n;
}

#include <stdio.h>
int main()
{
	printf("%i",counter());
	printf("%i",counter());
	printf("%i",counter());
}
