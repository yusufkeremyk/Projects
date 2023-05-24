CC		= gcc -g
NAME	= push_swap
FLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard src/*.c Libft/*.c)
OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	rm -rf $(OBJS)

fclean:	clean		
	rm -rf $(NAME)

git:
	git add .
	git commit -m "$c"
	git push git@github.com:yeaktas/push_swap.git

norm:
	@norminette $(wildcard Libft/*.c)
	@norminette $(wildcard src/*.c)
	@norminette $(wildcard inc/*.h)

.PHONY: all re clean fleanc git norm