NAME = philo
CFLAGS = -Wall -Werror -Wextra
CC = cc

SRCS = philo.c pars.c utlis.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
