#include "push_swap.h"

void fatal_error(int err_num)
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

int main(int ac, char **av)
{
    t_list  *head_a;
    t_list  *head_b;
    
    head_a = NULL;
    head_b = NULL;
    if (ac == 1)
        write(1, "\n", 1);
    else
    {
        check_args(ac, av);
        fill_list(&head_a, ac, av);
         if (list_is_sorted(head_a, head_b))
               {
                   if (ac <= 6)
                       sort_small_list(&head_a, &head_b);
                   else
                       sort_middle_list(&head_a, &head_b);
    }
    free_list(&head_a);
    return (0);
}
