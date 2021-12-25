#include "push_swap.h"

int check_group(t_list *head, int step)
{
	while (head)
	{
		if (head->i < step)
			return (1);
		head = head->next;
	}
	return (0);
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

/* Перекинуть элементы из В в А в зависимости от их положения в стеке В */
void get_sorted_list(t_list **stack_a, t_list **stack_b)
{
	int 	max_index;
	int		flag;
	int 	count;

	while (*stack_b)
	{	
		count = 0;
		max_index = find_max(*stack_b);
		flag = locate_elem_stack_b(stack_b, max_index);
		while ((*stack_b)->i != max_index)
		{
			if (flag == 0)
			{
				// if ((*stack_b)->i == max_index - 1) 
				// {	
				// 	dprintf(2, "blyat\n");
				// 	push_shell(stack_a, stack_b, 'a');
				// 	count++;
				// }
				rotate_shell(NULL, stack_b);
			}
			else
			{
				if ((*stack_b)->i == max_index - 1)
				{
					push_shell(stack_a, stack_b, 'a');
					count++;
				}
				reverse_rotate_shell(NULL, stack_b);
			}
		}
		push_shell(stack_a, stack_b, 'a');
		if (count)
		{
			if (*stack_b && (*stack_b)->next &&
			((*stack_b)->data < (*stack_b)->next->data))
			{	
				swap_shell(stack_a, stack_b);
			}
			else
				swap_shell(stack_a, NULL);
		}
	}
}

static int count_step(t_list *stack)
{
    int     step;
    int     group_count;
    int     num_count;

    num_count = count_nodes(stack);
    step = 0;
    /* max rmd = 2 */
    if (num_count <= 50)
    {
        group_count = 3;
    }
    /* max rmd = 4 */
    else if (num_count > 50 && num_count <= 100)
    {
        group_count = 5;
    }
	else
	{
		group_count = 12;
	}
	step = num_count / group_count;
    return (step);
}

// int locate_group(t_list *stack, int min, int max)
// {
// 	int		medium;
// 	int		before_med;
// 	int		after_med;
// 	int		i;

// 	i = 0;
// 	before_med = 0;
// 	after_med = 0;
// 	medium = count_nodes(stack) / 2;
// 	while (stack)
// 	{
// 		if (stack->i >= min && stack->i < max)
// 		{
// 			if (i < medium)
// 				before_med++;
// 			else
// 				after_med++;
// 		}
// 		stack = stack->next;
// 		i++;
// 	}
// 	if (before_med > after_med)
// 		return (0);
// 	return (1);
// }

/* Перекинуть по группам элементы из стека А в В, пока в А не останется трех элементов */
void sort_middle_list(t_list **head_a, t_list **head_b)
{
    t_list  *stack_a;
    t_list  *stack_b;
	int		step;
	int		max;
	int 	const_step;

    stack_a = *head_a;
    stack_b = *head_b;
	max = find_max(stack_a);
	const_step = count_step(stack_a);
	step = const_step;
    while (count_nodes(stack_a) > 3)
    {
		// int way = 0;
		// way = locate_group(stack_a, step-const_step, step);
		// dprintf(2, "step is: %d | way is %s\n", step, way ? "DOWN" : "UP");
		// print_list(stack_a, stack_b);
		// dprintf(2, "current step is: %d\n", step);
        while (count_nodes(stack_a) > 3 && check_group(stack_a, step) == 1)
        {
            if (stack_a->i < step && stack_a->i < (max - 2))
            {
                push_shell(&stack_a, &stack_b, 'b');
            }
            else
            {
				// if (locate_group(stack_a, step - const_step, step))
				// if (way)
					// reverse_rotate_shell(&stack_a, NULL);
				// else
					rotate_shell(&stack_a, NULL);
            }
        }
        step += const_step;
		// print_list(stack_a, stack_b);
    }
    sort_three(&stack_a);
	get_sorted_list(&stack_a, &stack_b);
	*head_a = stack_a;
	*head_b = stack_b;
	// if (list_is_sorted(stack_a, stack_b))
	// {
	// 	dprintf(2, "IT'S FUCKING SORTED\n");
	// }
	// else
	// {
	// 	dprintf(2, "IT'S NOT SORTED, U SHOUD KILL URSELF!111!\n");
	// }
	// print_list(stack_a);
	// printf("\n");
}