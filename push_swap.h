#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
//  delete later
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
void    fill_list(t_list **head, int ac, char **av);
void    list_add_back(t_list *head, int data);
int     count_nodes(t_list *head);
void    free_list(t_list **head);

void    print_list(t_list *a, t_list *b);

/* error handling */
void    fatal_error(int err_num);

/* parse */
int	    ft_atoi(const char *str);
void    check_duplicate_values(t_list *head);
int     check_args(int ac, char **av);

/* commands */
void    swap_shell(t_list **stack_a, t_list **stack_b);
void    push_shell(t_list **stack_a, t_list **stack_b, char dest);
void    rotate_shell(t_list **stack_a, t_list **stack_b);
void    reverse_rotate_shell(t_list **stack_a, t_list **stack_b);

/* algorythm prerequisites */
void    index_elems(t_list **head);
void    side_index_elems(t_list **head, int min, int count);

/* middle list */
void    sort_middle_list(t_list **head_a, t_list **head_b);

/* small list */
void    sort_three(t_list **head);
void    sort_small_list(t_list **a, t_list **b);

/* utils */
int     find_max(t_list *head);
int     find_min(t_list **head);

/* extra shet */
int     list_is_sorted(t_list *a, t_list *b);

#endif