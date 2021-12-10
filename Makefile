NAME = push_swap

SOURCES =	main.c			ft_list_functions.c		ft_standard_functions.c\
			ft_commands.c

OBJ = $(patsubst %.c,%.o,$(SOURCES))

INCLUDES	=	push_swap.h

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) 
	@gcc $(OBJ) -o $(NAME)
	@echo You compiled the mandatory part of project.

%.o : %.c $(INCLUDES)
	gcc $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY :
	all clean fclean re