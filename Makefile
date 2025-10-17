NAME = tic-tac-toe

SRCS = tic-tac-toe.c \
	board.c \
	bot.c \
	win.c

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all