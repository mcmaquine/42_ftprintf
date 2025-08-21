NAME = libftprintf.a

CC = cc

WFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_printf_utils.c

OBJS = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(WFLAGS) -c -g $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f main

re: fclean all

#compilando com a lib estática
main: main.c $(NAME)
	cc -g main.c -static ./$(NAME) -o $@
	./main