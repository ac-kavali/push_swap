# push_swap
NAME            = push_swap

PUSHSWAP_SRC    = src/stack.c \
                  src/stack2.c \
                  src/helpers.c \
                  src/push_swap.c \
                  src/validator.c \
                  src/short_sort.c \
                  src/modern_times.c \
                  src/modern_times2.c \
                  src/moves/ft_push.c \
                  src/moves/ft_swap.c \
                  src/moves/ft_rotate.c \
                  src/moves/ft_reverse_rotate.c

OBJS            = $(PUSHSWAP_SRC:.c=.o)

# bonus
NAME_BONUS      = checker

BONUS_SRC       = src/stack.c \
                  src/stack2.c \
                  src/helpers.c \
                  src/validator.c \
                  src/checker_bonus.c \
                  src/moves/ft_push.c \
                  src/moves/ft_swap.c \
                  src/moves/ft_rotate.c \
                  src/moves/ft_reverse_rotate.c

OBJSBNS         = $(BONUS_SRC:.c=.o)

LIBFT           = libft.a
LIBFT_SRC       = ./libft/

CC              = gcc
RM              = rm -f
CFLAGS          = -Wall -Werror -Wextra

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft bonus

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(OBJSBNS)
	$(CC) $(CFLAGS) $(OBJSBNS) $(LIBFT_SRC)$(LIBFT) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJSBNS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean bonus re
