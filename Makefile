NAME = libftprintf.a
CC	= gcc
SRC = ft_printf.c \
conversions.c

OBJFILES = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

all	: $(NAME)

$(NAME) : $(OBJFILES)
	ar -csr $(NAME) $(OBJFILES)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all