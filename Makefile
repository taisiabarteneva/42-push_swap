NAME = push_swap

SOURCES =	main.c			ft_list_functions.c		ft_standard_functions.c\
			ft_commands.c

OBJ = $(patsubst %.c,%.o,$(SOURCES))

INCLUDES	=	pipex.h
# LIB = libft_new/libft.a
# DIR_LIB = libft_new

# FLAGS = -Wall -Wextra -Werror

all : $(NAME)

# lib :
# 	$(MAKE) -sC $(DIR_LIB)

$(NAME) : $(OBJ) $(LIB)
	@gcc $(OBJ) $(LIB) -o $(NAME)
	@echo You compiled the mandatory part of project.

%.o : %.c $(INCLUDES)
	gcc $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ) $(OBJ_BONUS)
# @$(MAKE) clean -C $(DIR_LIB)

fclean : clean
	@rm -f $(NAME)
# @$(MAKE) fclean -C $(DIR_LIB)

re : fclean all

.PHONY :
	all clean fclean re