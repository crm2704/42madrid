NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = libftprintf.h
SRCS = 

OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS) $(INCLUDE)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean clean_bonus
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

clean_bonus:
	rm -f $(BONUS_OBJS)

re: fclean all
