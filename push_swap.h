#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_list
{
    int             data;
    int             i;
    struct s_list  *next;
}               t_list;

#define DEFAULT_ERR  1
#define MEM_ERR      2
#define FIRST_ELEM   1
#define LIST_START   2

/* list functions */
void    ft_list_add_back(t_list *head, int data);
void    ft_print_list(t_list *node);
int     ft_count_nodes(t_list **head);

/* error handling */
void    ft_fatal_error(int err_num);

/* std functions */
int	    ft_atoi(const char *str);

/* commands */
void    ft_swap(t_list **_head);
void    ft_push(t_list **head_dst, t_list **head_src);
void    ft_rotate(t_list **head);
void    ft_reverse_rotate(t_list **head);

/* оболочки для команд */

/* algorythm prerequisites */
int     ft_find_min(t_list **head);
void    ft_index_elems(t_list **head);
void    ft_side_index_elems(t_list **head, int min, int count);

/* algorythm */
void    ft_swap_indexed_elems(t_list **head);

#endif