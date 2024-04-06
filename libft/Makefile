NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = libft.h
SRCS =  ft_split.c \
        ft_isalpha.c \
	ft_isdigit.c \
        ft_isascii.c \
      	ft_isalnum.c \
        ft_isprint.c \
        ft_tolower.c \
        ft_toupper.c \
        ft_strchr.c \
        ft_strrchr.c \
        ft_strncmp.c \
        ft_memset.c \
        ft_memchr.c \
        ft_bzero.c \
        ft_isprint.c \
        ft_strlen.c \
        ft_memcpy.c \
        ft_memcmp.c \
        ft_memmove.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_atoi.c \
        ft_strnstr.c \
        ft_calloc.c \
        ft_strdup.c \
        ft_substr.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
        ft_putchar_fd.c \
        ft_putstr_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \

BONUS_SRCS = ft_lstnew.c \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS: .c=.o)

all:$(NAME) bonus

bonus: %(BONUS_OBJS) $(INCLUDE)


$(NAME):$(OBJS) $(INCLUDE)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all
