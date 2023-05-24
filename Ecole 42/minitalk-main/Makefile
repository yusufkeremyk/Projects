NAME_C = client
NAME_S = server
FLAGS = -Wall -Wextra -Werror
FILE1 = client.c 
FILE2 = server.c
CC = gcc

all: $(NAME_C) $(NAME_S)

$(NAME_C):
	$(CC) $(FLAGS) $(FILE1) -o $(NAME_C) 

$(NAME_S):
	$(CC) $(FLAGS) $(FILE2) -o $(NAME_S)
 
clean:
	rm -f server
	rm -f client

fclean: 
	rm -f $(NAME_C)
	rm -f $(NAME_S)

re: fclean all

.PHONY: all clean fclean re
