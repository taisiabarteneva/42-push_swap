/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:39:13 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/31 06:10:42 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort_b(t_list **stack_a, t_list **stack_b, int group_count)
{
	int	rotated;
	int	pushed;

	pushed = 0;
	if (group_count <= 3)
		merge_sort_base_case_b(stack_a, stack_b, group_count);
	else
	{
		tmp_index_elems(stack_b, group_count);
		rotated = merge_sort_divide_b(stack_a, stack_b, group_count, &pushed);
		while (rotated > 0)
		{
			reverse_rotate_shell(NULL, stack_b);
			rotated--;
		}
		merge_sort(stack_a, stack_b, pushed, 'a');
		merge_sort(stack_a, stack_b, group_count - pushed, 'b');
	}
}

void	merge_sort_a(t_list **stack_a, t_list **stack_b, int group_count)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	if (group_count <= 3)
		merge_sort_base_case_a(stack_a, stack_b, group_count);
	else
	{
		tmp_index_elems(stack_a, group_count);
		rotated = merge_sort_divide_a(stack_a, stack_b, group_count, &pushed);
		while (rotated > 0)
		{
			reverse_rotate_shell(stack_a, NULL);
			rotated--;
		}
		merge_sort(stack_a, stack_b, group_count - pushed, 'a');
		merge_sort(stack_a, stack_b, pushed, 'b');
	}
}

void	merge_sort(t_list **stack_a, t_list **stack_b, int group_count,
				char stack_name)
{
	if (stack_name == 'a')
	{
		merge_sort_a(stack_a, stack_b, group_count);
	}
	else
	{
		merge_sort_b(stack_a, stack_b, group_count);
	}
}

void	big_list_push_to_b(t_list **stack_a, t_list **stack_b,
						t_list **group_count)
{
	int	med;
	int	max;
	int	pushed;

	med = 0;
	tmp_index_elems(stack_a, count_nodes(*stack_a));
	max = tmp_find_max(*stack_a, count_nodes(*stack_a));
	while (count_nodes(*stack_a) > 3)
	{
		tmp_index_elems(stack_a, count_nodes(*stack_a));
		med = count_nodes(*stack_a) / 2;
		pushed = 0;
		while (tmp_check_group(*stack_a, med) == 1)
		{
			if ((*stack_a)->i_tmp < med && (*stack_a)->i_tmp < (max - 1))
			{
				push_shell(stack_a, stack_b, 'b');
				pushed++;
			}
			else
				rotate_shell(stack_a, NULL);
		}
		list_add_front(group_count, pushed);
	}
	sort_three_if_full(stack_a, stack_b, 'a');
}

void	sort_big_list(t_list **stack_a, t_list **stack_b)
{
	t_list	*group_count;

	group_count = NULL;
	big_list_push_to_b(stack_a, stack_b, &group_count);
	while (group_count)
	{
		merge_sort(stack_a, stack_b, group_count->data, 'b');
		group_count = group_count->next;
	}
}
