NAME = philo
CFLAGS = -Wall -Werror -Wextra -g
CC = cc

SRCS = main.c pars.c utlis.c routine.c handle_errors.c init.c simulation.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
