NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
INCLUDES = -I.

SRCS = main.c \
	   init.c \
	   parse_args.c \
	   simulation.c \
	   safe_thing.c \
	   utils.c \
	   clean_exit.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) philo.h
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 