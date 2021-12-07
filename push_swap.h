#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int             data;
    struct s_list  *next;
}               t_list;       


#define DEFAULT_ERR  1
#define MEM_ERR      2

// list functions
int ft_list_add_back(t_list *head, int data);
void ft_print_list(t_list *node);

// error handling
void ft_fatal_error(int err_num);

// std functions
int	ft_atoi(const char *str);

// cmds
void ft_swap(t_list **_head);

#endif