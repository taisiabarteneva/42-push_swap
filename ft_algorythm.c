#include "push_swap.h"

void sort_three_elems(t_list **head)
{
    if ((*head)->data > (*head)->next->data) 
    {
        swap(head);
    }
    if ((*head)->next->data > (*head)->next->next->data)
    {
        reverse_rotate(head);
        swap(head);
    }
    if ((*head)->data > (*head)->next->data) 
    {
        swap(head);
    }
}

int check_group(t_list *head, int step)
{
	while (head)
	{
		if (head->i < step)
		{
			return (1);
		}
		head = head->next;
	}
	return (0);
}

int find_max(t_list *head)
{
	int 	max_val;
	t_list	*found;

	max_val = INT_MIN;
	while (head != NULL)
	{
		if (head->data >= max_val)
		{
			max_val = head->data;
			found = head;
		}
		head = head->next;
	}
	return (found->i);
}

/* Функция для оптимизации алгоритма.
Поиск медианного значения. В зависимости от позиции элемента в списке
применяется команда reverse либо rotate. */
int locate_elem_stack_b(t_list **stack_b, int max_index)
{
	int		medium;
	int		nodes_count;
	int		flag;
	int		i;
	t_list	*current;

	nodes_count = count_nodes(*stack_b);
	medium = nodes_count / 2;
	flag = 0;
	i = 0;
	current = *stack_b;
	while (current)
	{
		if (current->i == max_index)
		{
			if (i < medium)
				flag = 0;
			else
				flag = 1;
			break ;
		}
		current = current->next;
		i++;
	}
	return (flag);
}

void get_sorted_list(t_list **stack_a, t_list **stack_b)
{
	int 	max_index;
	int		flag;

	while (*stack_b)
	{
		max_index = find_max(*stack_b);
		flag = locate_elem_stack_b(stack_b, max_index);
		while ((*stack_b)->i != max_index)
		{
			if (flag == 0)
				rotate(stack_b);
			else
				reverse_rotate(stack_b);
		}
		push(stack_a, stack_b);
	}
}

void push_indexed_elems(t_list **head, int step)
{
    t_list  *stack_b;
    t_list  *stack_a;
    int     i;
	int		max;

    stack_a = *head;
    stack_b = NULL;
    i = 0;
	max = find_max(*head);
	
    /* перекинуть все элементы из А в Б, пока в А не останется трех наибольших */
    while (count_nodes(stack_a) > 3)
    {
        while (count_nodes(stack_a) > 3 && check_group(stack_a, step) == 1)
        {
            // printf("count is %d\n", count_nodes(stack_a));
        	// printf("i is [%d]\n", i);
            // printf("step is [%d]\n", step);
			// printf("current num is [%d:%d]\n", stack_a->data, stack_a->i);
            if (stack_a->i < step && stack_a->i < (max - 2))
            {
				// printf("pa\n");
                push(&stack_b, &stack_a);
            }
            else
            {
				// printf("ra\n");
                rotate(&stack_a);
            }
        }
        i += step;
        step += step;
        // printf("i is [%d]\n", i);
        // printf("step is [%d]\n", step);
    }
    sort_three_elems(&stack_a);
	// if list is sorted, exit
	// else ...
	//  ------
	//  ------
    // printf("------ pre-sorted ------\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
    // print_list(stack_b);
	// printf("\n");
	get_sorted_list(&stack_a, &stack_b);
    printf("------ sorted ------\n");
	printf("stack a : \n");
    print_list(stack_a);
	printf("stack b : \nis empty\n");
    print_list(stack_b);
    // //  ------
	// print_list(stack_a);
    // printf("------\n");
    // print_list(stack_b);
}