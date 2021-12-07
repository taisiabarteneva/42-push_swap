// ◦ write
// ◦ read
// ◦ malloc
// ◦ free
// ◦ exit

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

// check args
int ft_check_args(int ac, char **av)
{
    int     i;
    long    val;

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

    head = (t_list *)malloc(sizeof(t_list));
    if (!head)
        ft_fatal_error(MEM_ERR);
    val = ft_atoi(av[FIRST_ELEM]);
    head->data = val;
    head->next = NULL;
    i = LIST_START;
    while (i < ac)
    {
        val = ft_atoi(av[i]);
        ft_list_add_back(head, val);
        i++;
    }
    ft_check_duplicate_values(head);
    ft_print_list(head);
    ft_swap_a(&head);
    ft_print_list(head);
}

int main(int ac, char **av)
{
    if (ac == 1)
        ft_fatal_error(DEFAULT_ERR);
    ft_check_args(ac, av);
    ft_fill_list(ac, av);
    return (0);
}