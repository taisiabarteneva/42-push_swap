#include "push_swap.h"

void ft_swap_indexed_elems(t_list **head, int ac)
{
    t_list  *stack_b;
    t_list  *stack_a;
    int     i;

    stack_a = *head;
    stack_b = NULL;
    i = 0;

    ft_push(&stack_b, &stack_a);
}