NAME = push_swap

DIR_SRC = src
DIR_OBJ = obj
# SOURCES =	main.c			list_functions.c		standard_functions.c\
# 			commands.c		algorythm.c				prerequisites.c\
# 			sort_small_list.c

SRC = $(wildcard $(DIR_SRC)/*.c)
OBJ = $(patsubst $(DIR_SRC)/%.c,$(DIR_OBJ)/%.o,$(SRC))
INCLUDES	=	push_swap.h

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) 
	@gcc $(OBJ) -o $(NAME)
	@echo You compiled the mandatory part of project.

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c $(INCLUDES)
	@mkdir -p $(DIR_OBJ)
	gcc $(FLAGS) -I . -c $< -o $@

clean :
	@rm -rf $(DIR_OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY :
	all clean fclean re