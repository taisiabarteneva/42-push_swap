#include "push_swap.h"

#define FIRST_ELEM   1
#define LIST_START   2

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

static int check_args(int ac, char **av)
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

static void check_duplicate_values(t_list *head)
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
                fatal_error(DEFAULT_ERR);
            following = following->next;
        }
        current = current->next;
    }
}

static void fill_list(t_list **head, int ac, char **av)
{
    int     val;
    int     i;

    *head = (t_list *)malloc(sizeof(t_list));
    if (!head)
        fatal_error(MEM_ERR);
    val = ft_atoi(av[FIRST_ELEM]);
    (*head)->data = val;
    (*head)->i = 0;
    (*head)->next = NULL;
    i = LIST_START;
    while (i < ac)
    {
        val = ft_atoi(av[i]);
        list_add_back(*head, val);
        i++;
    }
    check_duplicate_values(*head); 
    index_elems(head);
}

/* В первой группе элементы с индексом 0 - n,
Последние три элемента остаются в стеке А. */
static int count_step(int ac)
{
    int     step;
    int     group_count;
    int     num_count;

    num_count = ac - 1;
    step = 0;
    /* max rmd = 2 */
    if (num_count <= 50)
    {
        group_count = 3;
        step = num_count / group_count;
    }
    /* max rmd = 4 */
    else if (num_count > 50 && num_count <= 100)
    {
        group_count = 5;
        step = num_count / group_count;
    }
    return (step);
}

int main(int ac, char **av)
{
    t_list  *head;
    int     step;
    
    if (ac == 1)
        return (1);
    else if (ac < 4)
        fatal_error(DEFAULT_ERR);
    // check if sorted
    check_args(ac, av);
    fill_list(&head, ac, av);
    step = count_step(ac);
    // printf("%d\n", step);
    // printf("%d\n", ac - 1);
    push_indexed_elems(&head, step);
    return (0);
}