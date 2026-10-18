/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:27:40 by asidki            #+#    #+#             */
/*   Updated: 2026/10/17 14:11:16 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"
#include <string.h>

void	test_isalpha(void)
{
	printf("=========== TESTING IS ALPHA ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = 'a';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 'A';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 'z';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 'Z';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 's';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 'F';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = ' ';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = '3';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = ',';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 0;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = '`';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = '{';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = '@';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = '[';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
}

void	test_isdigit(void)
{
	printf("\n\n=========== TESTING IS DIGIT ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = '0';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = '9';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = '6';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = 'f';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = '\\';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = ':';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = -1;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
}

void	test_isalnum(void)
{
	printf("\n\n=========== TESTING IS ALPHANUMERIC ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = 'a';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = 'z';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = 'A';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = 'Z';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '0';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '9';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = 'm';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = 'L';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '6';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '@';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '[';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '`';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '{';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '\\';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = ':';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
}

void	test_isascii(void)
{
	printf("\n\n=========== TESTING IS ASCII ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = 0;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isascii(c), (ft_isascii(c) != 0) ? 1 : 0);
	c = 127;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isascii(c), (ft_isascii(c) != 0) ? 1 : 0);
	c = 'a';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isascii(c), (ft_isascii(c) != 0) ? 1 : 0);
	c = -1;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isascii(c), (ft_isascii(c) != 0) ? 1 : 0);
	c = -30;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isascii(c), (ft_isascii(c) != 0) ? 1 : 0);
}

void	test_isprint(void)
{
	printf("\n\n=========== TESTING IS PRINT ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = ' ';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = '~';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = 'a';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = 43;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = 31;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = 127;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = -1;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
}

void	test_strlen(void)
{
	printf("\n\n=========== TESTING STRLEN ============\n\n");

	if (strlen("Hello") == ft_strlen("Hello"))
		printf("OK: expected %zu, got %zu. [test string \"Hello\".]\n", strlen("Hello"), ft_strlen("Hello"));
	else
		printf("Try again: expected %zu, got %zu [test string \" \".]\n", strlen("Hello"), ft_strlen("Hello"));
	
	if (strlen(" ") == ft_strlen(" "))
		printf("OK: expected %zu, got %zu. [test string \" \".]\n", strlen(" "), ft_strlen(" "));
	else
		printf("Try again: expected %zu, got %zu [test string \" \".]\n", strlen(" "), ft_strlen(" "));
	
	
	if (strlen("") == ft_strlen(""))
		printf("OK: expected %zu, got %zu. [test string \"\".]\n", strlen(""), ft_strlen(""));
	else
		printf("Try again: expected %zu, got %zu [test string \"\".]\n", strlen(""), ft_strlen(""));
	
	if (strlen("123456789123456789") == ft_strlen("123456789123456789"))
		printf("OK: expected %zu, got %zu. [test string \"123456789123456789\".]\n", strlen("123456789123456789"), ft_strlen("123456789123456789"));
	else
		printf("Try again: expected %zu, got %zu [test string \"123456789123456789\".]\n", strlen("123456789123456789"), ft_strlen("123456789123456789"));
	
	if (strlen("\0") == ft_strlen("\0"))
		printf("OK: expected %zu, got %zu. [test string \"\\0\".]\n", strlen("\0"), ft_strlen("\0"));
	else
		printf("Try again: expected %zu, got %zu [test string \"\\0\".]\n", strlen("\0"), ft_strlen("\0"));	
}

void	test_memset(void)
{
	printf("\n\n=========== TESTING MEMSET ============\n\n");

	char orsrc[20] = "Hello World";
	char ftsrc[20] = "Hello World";

	if(!strcmp(memset(orsrc, 'o', 3), ft_memset(ftsrc, 'o', 3)))
			printf("OK: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
	else
			printf("Try again: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
	if(!strcmp(memset(orsrc, 'x', 15), ft_memset(ftsrc, 'x', 15)))
			printf("OK: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
	else
			printf("Try again: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
	if(!strcmp(memset(orsrc, '~', 5), ft_memset(ftsrc, '~', 5)))
			printf("OK: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
	else
			printf("Try again: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
}

void	test_bzero(void)
{
	printf("\n\n=========== TESTING BZERO ============\n\n");

	char	sori[20] = "abcdef";
	char	sft[20] = "abcdef";
	bzero(sori, 4);
	ft_bzero(sft, 4);
	int	i;
	i = 0;

	while (i < 6 && sori[i] == sft[i])
		i++;
	if (i == 6)
		printf("OK: expected [%c] [%c] [%c] [%c] [%c] [%c], got [%c] [%c] [%c] [%c] [%c] [%c].\n", sori[0], sori[1], sori[2], sori[3], sori[4], sori[5], sft[0], sft[1], sft[2], sft[3], sft[4], sft[5]);

	else
		printf("Try again: expected [%c] [%c] [%c] [%c] [%c] [%c], got [%c] [%c] [%c] [%c] [%c] [%c].\n", sori[0], sori[1], sori[2], sori[3], sori[4], sori[5], sft[0], sft[1], sft[2], sft[3], sft[4], sft[5]);
}

void	test_memcpy(void)
{
	printf("\n\n=========== TESTING MEMCPY ============\n\n");

	char	dest0[20] = "World";
	char	dest1[20] = "World";

	if(!strcmp(memcpy(dest0, "source", 3), ft_memcpy(dest1, "source", 3)))
		printf("OK: expected \"%s\", got \"%s\".\n", dest0, dest1);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", dest0, dest1);
	if(!strcmp(memcpy(dest0, "123456source", 9), ft_memcpy(dest1, "123456source", 9)))
		printf("OK: expected \"%s\", got \"%s\".\n", dest0, dest1);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", dest0, dest1);
	if(!strcmp(memcpy(dest0, "123456source", 0), ft_memcpy(dest1, "123456source", 0)))
		printf("OK: expected \"%s\", got \"%s\".\n", dest0, dest1);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", dest0, dest1);
}

void	test_toupper(void)
{
	printf("\n\n=========== TESTING TO UPPER ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = 'a';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = 'w';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = 'A';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = ' ';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = '3';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = '~';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = '*';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
}

void	test_tolower(void)
{
	printf("\n\n=========== TESTING TO LOWER ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = 'A';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = 'W';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = 'a';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = ' ';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = '3';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = '~';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = '*';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
}

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_toupper();
	test_tolower();
	return (0);
}
