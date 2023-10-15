NAME = libftprintf.a
SRCS = ft_printf.c utils.c parse/parse.c print_utils/print_utils.c \
	print_utils/print_utils_digits.c print_utils/print_utils_padding.c \
	print_utils/print_utils_prefix.c print/print.c print/print_cs.c \
	print/print_duxX.c print/print_p.c
OBJS = $(SRCS:.c=.o)
LIBFT = $(LIBFT_FOLDER)/libft.a
LIBFT_FOLDER = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_FOLDER)

bonus: $(NAME)

clean:
	$(RM) -f $(OBJS)
	$(MAKE) -C $(LIBFT_FOLDER) clean

fclean: clean
	$(RM) -f $(NAME)
	$(MAKE) -C $(LIBFT_FOLDER) fclean

re: fclean all

.PHONY: all bonus clean fclean re
