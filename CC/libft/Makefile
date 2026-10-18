NAME = test
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
SRCS = $(wildcard *.c)

$(NAME) : $(SRCS) libft.h 
	$(CC)  $(SRCS) -o $(NAME)

all: $(NAME)

clean :
	rm -f $(NAME)

re: clean all 

.PHONY: all clean re
