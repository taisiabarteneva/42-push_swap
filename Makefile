NAME = push_swap

DIR_SRC = src
DIR_OBJ = obj
SRC =			commands1.c			commands2.c		commands3.c\
				index_elems.c		main.c			list_functions.c\
				merge_sort_extra.c	parse.c			sort_big_extra.c\
				sort_big_utils.c	sort_big.c		sort_middle.c\
				sort_small.c 		conversion.c	algorythm_extra.c\
				presort_middle.c	sort_middle_extra.c\

SRC := $(SRC:%.c=$(DIR_SRC)/%.c)
OBJ = $(SRC:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)
INCLUDES	=	push_swap.h

COLOR = \033[48;5;57m
NO_COLOR =	\033[0m 

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@gcc $(OBJ) -o $(NAME)
	@echo "$(COLOR)You compiled the mandatory part of project.$(NO_COLOR)"

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c $(INCLUDES)
	@mkdir -p $(DIR_OBJ)
	@gcc $(FLAGS) -I . -c $< -o $@
	@echo "[$<] ---> [$@]"

clean :
	@rm -rf $(DIR_OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY :
	all clean fclean re