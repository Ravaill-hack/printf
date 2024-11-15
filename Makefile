NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_FILES =  \
	ft_char.c \
	ft_number.c \
	ft_printf.c

OBJS = $(SRCS_FILES:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
