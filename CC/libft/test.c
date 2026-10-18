
#include <stdio.h>
#include <string.h>
#include "libft.h"

static void	test_strchr(const char *s, int c)
{
	char		*expected;
	char		*actual;

	expected = strchr(s, c);
	actual = ft_strchr(s, c);
	printf("String: \"%s\", c: %d\n", s, c);
	printf("  strchr:    %s\n",
		expected ? "FOUND" : "NULL");
	printf("  ft_strchr: %s\n",
		actual ? "FOUND" : "NULL");
	if (expected == actual)
		printf("  SAME ADDRESS\n");
	else if (expected && actual && expected - s == actual - s)
		printf("  PASS: same position\n");
	else
		printf("  FAIL: different results\n");
	if (expected)
		printf("  Expected position: %ld\n", (long)(expected - s));
	if (actual)
		printf("  Actual position:   %ld\n", (long)(actual - s));
	printf("\n");
}




int	main(void)
{
	char	empty[] = "";
	char	repeated[] = "banana";
	char	high_bytes[] = "abc";
	char	high_byte_str[] = {'h', 'i', (char)255, '\0'};

	printf("=== Basic cases ===\n");
	test_strchr("hello", 'h');
	test_strchr("hello", 'o');
	test_strchr("hello", 'l');
	test_strchr("hello", 'x');

	printf("=== Edge cases ===\n");
	test_strchr(empty, '\0');
	test_strchr(empty, 'a');
	test_strchr("hello", '\0');
	test_strchr(repeated, 'a');
	test_strchr("hello", 'H');
	test_strchr("hello", 0);
	test_strchr("hello,", 300);
	test_strchr("hello", 256);
	test_strchr("hello", 255);
	test_strchr("hello", -1);
	test_strchr(high_bytes, 'c');
	test_strchr(high_byte_str, 255);

	return (0);
}


