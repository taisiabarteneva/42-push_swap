#include "push_swap.h"

#define FIRST_ELEM   1
#define LIST_START   2

void ft_fatal_error(int err_num)
{
    if (err_num == 1)
    {
        write(1, "Error.\n", 8);
    }
    else if (err_num == 2)
    {
        write(1, "Memory allocation failed.\n", 27);
    }
    exit(EXIT_FAILURE);
}

int ft_check_args(int ac, char **av)
{
    int     i;

    i = FIRST_ELEM;
    while (i < ac)
    {
        ft_atoi(av[i]);
        i++;
    }
    return (0);
}

void ft_check_duplicate_values(t_list *head)
{
    t_list  *current;
    t_list  *following;
    
    current = head;
    while (current->next != NULL)
    {
        following = current->next;
        while (following)
        {
            if (current->data == following->data)
                ft_fatal_error(DEFAULT_ERR);
            following = following->next;
        }
        current = current->next;
    }
}

void ft_fill_list(int ac, char **av)
{
    t_list  *head;
    int     val;
    int     i;
    int     elem_num;

    head = (t_list *)malloc(sizeof(t_list));
    if (!head)
        ft_fatal_error(MEM_ERR);
    val = ft_atoi(av[FIRST_ELEM]);
    head->data = val;
    head->i = 0;
    head->next = NULL;
    i = LIST_START;
    elem_num = 1;
    while (i < ac)
    {
        val = ft_atoi(av[i]);
        ft_list_add_back(head, val, elem_num);
        i++;
        elem_num++;
    }
    ft_check_duplicate_values(head);
    /* 
    t_list *stack;
    stack = (t_list *)malloc(sizeof(t_list));
    stack->data = 10;
    stack->i = 0;
    stack->next = NULL;
    ft_list_add_back(stack, 80, 1);
    */
    ft_print_list(head);
    printf("reverse rotate : ");
    ft_reverse_rotate(&head);
    ft_print_list(head);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (1);
    else if (ac < 4)
        ft_fatal_error(DEFAULT_ERR);
    ft_check_args(ac, av);
    ft_fill_list(ac, av);
    return (0);
}