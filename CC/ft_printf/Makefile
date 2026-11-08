NAME = libftprintf.a
CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rsc

SRCS = ft_printf.c ft_putchr.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_puthex.c \
	   ft_putunbr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o:%.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
