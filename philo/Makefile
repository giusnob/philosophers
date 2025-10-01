NAME = philo

CC = clang
CFLAGS = -Wall -Wextra -Werror -g -I. -Iinclude -Ift_printf/libft -Ift_printf
RM = rm -f

SRC = ./philo/atoi.c \
	./philo/main.c \
	./philo/monitor.c \
	./philo/philo_routine.c \
	./philo/simulation.c


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
