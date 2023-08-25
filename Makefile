NAME = libftprintf.a
SRCS = ft_printf.c utils.c parse/parse.c print_utils/print_utils.c \
	print_utils/print_utils_digits.c print_utils/print_utils_padding.c \
	print_utils/print_utils_prefix.c print/print.c print/print_cs.c \
	print/print_duxX.c print/print_p.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
