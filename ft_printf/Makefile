NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = libftprintf.h
SRCS = 	ft_printf.c \
		ft_printchr.c \
		ft_printmem.c \
		ft_printnbr.c

OBJS = $(SRCS:.c=.o)

all:$(NAME)
	$(MAKE) -C libft

$(NAME):$(OBJS) $(INCLUDE)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean clean_bonus
	rm -f $(NAME)
	$(MAKE) fclean -C libft

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libft

clean_bonus:
	rm -f $(BONUS_OBJS)

re: fclean all
