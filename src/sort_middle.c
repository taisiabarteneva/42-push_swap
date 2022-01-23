/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:45:04 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/31 05:36:53 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	locate_max_elems_stack_b_extra(t_list *stack, t_info **group,
										int max)
{
	if (stack->i == max - 1)
		(*group)->max_one = 1;
	if (stack->i == max - 2)
		(*group)->max_two = 1;
	if (stack->i == max - 3)
		(*group)->max_three = 1;
}

int	locate_max_elems_stack_b(t_list *stack_b, int flag, int max)
{
	t_info	*group;
	int		total;

	init_info_struct(&group);
	if (flag == 0)
	{
		while (stack_b->i != max)
		{
			locate_max_elems_stack_b_extra(stack_b, &group, max);
			stack_b = stack_b->next;
		}
	}
	else if (flag == 1)
	{
		while (stack_b->i != max)
			stack_b = stack_b->next;
		while (stack_b)
		{
			locate_max_elems_stack_b_extra(stack_b, &group, max);
			stack_b = stack_b->next;
		}
	}
	total = calculate_elems_to_push(group);
	free(group);
	return (total);
}

void	handle_max_neighbours(t_list **stack_a, t_list **stack_b,
							int pull_elems)
{
	if (pull_elems)
		swap_shell(stack_a, stack_b, 'a');
	if (pull_elems == 2)
		reverse_rotate_shell(stack_a, NULL);
	if (pull_elems == 3)
	{
		reverse_rotate_shell(stack_a, NULL);
		reverse_rotate_shell(stack_a, NULL);
		if ((*stack_a)->i > (*stack_a)->next->i)
			swap_shell(stack_a, stack_b, 'a');
	}
}

int	sort_middle_list_extra(t_list **stack_a, t_list **stack_b,
							int max_index, int flag)
{
	int	pull_elems;

	pull_elems = locate_max_elems_stack_b(*stack_b, flag, max_index);
	while ((*stack_b)->i != max_index)
	{
		if ((*stack_b)->i >= max_index - pull_elems)
		{
			push_shell(stack_a, stack_b, 'a');
			if ((*stack_a)->i == max_index - 2
				|| (*stack_a)->i == max_index - 3)
				rotate_shell(stack_a, NULL);
		}
		else if (flag == 0)
			rotate_shell(NULL, stack_b);
		else
			reverse_rotate_shell(NULL, stack_b);
	}
	return (pull_elems);
}

void	sort_middle_list(t_list **stack_a, t_list **stack_b)
{
	int	max_index;
	int	flag;
	int	pull_elems;

	push_to_b(stack_a, stack_b, NULL);
	while (*stack_b)
	{
		max_index = find_max(*stack_b);
		flag = locate_elem_stack_b(stack_b, max_index);
		pull_elems = sort_middle_list_extra(stack_a, stack_b, max_index, flag);
		push_shell(stack_a, stack_b, 'a');
		handle_max_neighbours(stack_a, stack_b, pull_elems);
	}
}
