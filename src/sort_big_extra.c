/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:39:48 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/31 05:29:42 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort_base_case_b(t_list **stack_a, t_list **stack_b,
							int group_count)
{
	int	i;

	i = 0;
	if (group_count == 2)
	{
		if ((*stack_b)->data < (*stack_b)->next->data)
			swap_shell(stack_a, stack_b, 'b');
	}
	else if (group_count == 3)
	{
		sort_three_if_full(stack_a, stack_b, 'b');
	}
	while (i < group_count)
	{
		push_shell(stack_a, stack_b, 'a');
		i++;
	}
}

void	merge_sort_base_case_a(t_list **stack_a, t_list **stack_b,
							int group_count)
{
	if (group_count == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			swap_shell(stack_a, stack_b, 'a');
	}
	else if (group_count == 3)
		sort_three_if_full(stack_a, stack_b, 'a');
}

int	merge_sort_divide_b(t_list **stack_a, t_list **stack_b, int group_count,
						int *pushed)
{
	int	rotated;
	int	spec;
	int	med;

	rotated = 0;
	med = group_count / 2;
	spec = med;
	if (group_count % 2 == 1)
		spec++;
	while (*pushed < med)
	{
		if ((*stack_b)->i_tmp >= spec)
		{
			push_shell(stack_a, stack_b, 'a');
			(*pushed)++;
		}
		else
		{
			rotate_shell(NULL, stack_b);
			rotated++;
		}
	}
	return (rotated);
}

int	merge_sort_divide_a(t_list **stack_a, t_list **stack_b, int group_count,
						int *pushed)
{
	int	med;
	int	rotated;

	med = group_count / 2;
	rotated = 0;
	while (*pushed < med)
	{
		if ((*stack_a)->i_tmp < med)
		{
			push_shell(stack_a, stack_b, 'b');
			(*pushed)++;
		}
		else
		{
			rotate_shell(stack_a, NULL);
			rotated++;
		}
	}
	return (rotated);
}
