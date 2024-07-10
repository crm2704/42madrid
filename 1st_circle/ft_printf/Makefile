NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ft_printf.h
SRCS = 	ft_printf.c \
		ft_printchr.c \
		ft_printmem.c \
		ft_printnbr.c \
		ft_additional.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS)  $(INCLUDE)
	ar rcs $(NAME) $(OBJS)

fclean: clean clean_bonus
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all
