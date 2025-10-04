NAME = philo

CC = clang
CFLAGS = -Wall -Wextra -Werror -g -I. -Iinclude -Ift_printf/libft -Ift_printf
RM = rm -f

SRC = ./atoi.c \
	./main.c \
	./monitor.c \
	./philo_routine.c \
	./philo_utils.c \
	./simulation.c \
	./utils.c


all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(FT_DIR)/libft clean
	@$(MAKE) -C $(FT_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
