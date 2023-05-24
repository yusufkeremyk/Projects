OS			= $(shell uname)
LIBFTPATH	= Libft

NAME		= so_long
HEADER		= incs/so_long.h

BONUSNAME	= so_long_bonus
BONUSHEADER	= so_long_bonus.h

# For MacOS
MINILIBX	= minilibx_opengl/
# For Linux
ifeq ($(OS),Linux)
    MINILIBX = minilibx-linux/
endif

CC			= gcc -g
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
ECHO		= echo

# For MacOS
OPENGL		= -framework OpenGL -framework AppKit

# For MacOS
MINILIBXCC	= -I mlx -L $(MINILIBX) -lmlx
# For Linux
ifeq ($(OS),Linux)
    MINILIBXCC	= -L$(MINILIBX) -lmlx -lXext -lX11 -lm -lbsd
endif

COMPILEPRM	= $(MINILIBXCC) $(OPENGL) -o $(NAME) libft.a $(MINILIBX)/libmlx.a
COMPILEPRMB	= $(MINILIBXCC) $(OPENGL) -o $(BONUSNAME) libft.a $(MINILIBX)/libmlx.a
ifeq ($(OS),Linux)
COMPILEPRM	= $(HEADER) $(MINILIBXCC) libft.a -o $(NAME)
COMPILEPRMB = $(BONUSHEADER	$(MINILIBXCC) libft.a -o $(BONUSNAME)
endif

ALLFILES = $(wildcard src/*.c)

MANDATORYFILES	= $(filter-out so_long_bonus.c, $(ALLFILES))
BONUSFILES		= $(filter-out so_long.c, $(ALLFILES))

MANDATORYOBJ	=	$(MANDATORYFILES:.c=.o)
BONUSOBJ		=	$(BONUSFILES:.c=.o)

start:
			@make all

all:		$(NAME)

$(NAME):	$(MANDATORYOBJ)
			@make -s -C $(MINILIBX)
			@make -C $(LIBFTPATH)
			@make bonus -C $(LIBFTPATH)
			@cp $(LIBFTPATH)/libft.a .
			@$(CC) $(CFLAGS) $(MANDATORYOBJ) $(COMPILEPRM)

bonus:		$(BONUSNAME)

$(BONUSNAME):	$(BONUSOBJ)
			@make -s -C $(MINILIBX)
			@make -C $(LIBFTPATH)
			@make bonus -C $(LIBFTPATH)
			@cp $(LIBFTPATH)/libft.a .
			@$(CC) $(CFLAGS) $(BONUSOBJ) $(COMPILEPRMB)

clean:
			@$(RM) -r $(MANDATORYOBJ)
			@$(RM) -r $(NAME)
			@$(RM) -r $(BONUSOBJ)
			@$(RM) -r $(BONUSNAME)
			@make clean -C $(MINILIBX)
			@make clean -C $(LIBFTPATH)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) -rf $(LIBFTPATH)/libft.a
			@$(RM) -rf libft.a


re:			fclean all
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [so_long]!$(DEF_COLOR)\n"

norm:
	@norminette $(wildcard Libft/*.c) $(wildcard Libft/*.h) $(wildcard src/*.c) $(wildcard incs/*.h) 


.PHONY:		all clean fclean re norm