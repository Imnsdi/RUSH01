NAME	:= rush-01
CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror

SRCS	:= main.c io.c parse.c words.c
OBJS	:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
