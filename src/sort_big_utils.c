/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:44:48 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/30 05:20:52 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tmp_check_group(t_list *head, int step)
{
	while (head)
	{
		if (head->i_tmp < step)
			return (1);
		head = head->next;
	}
	return (0);
}

int	tmp_find_min(t_list **head, int group_count)
{
	int		min_val;
	t_list	*current;

	current = *head;
	min_val = INT_MAX;
	while (current != NULL && group_count)
	{
		if (current->data <= min_val)
		{
			min_val = current->data;
		}
		current = current->next;
		group_count--;
	}
	return (min_val);
}

int	tmp_find_max(t_list *head, int count)
{
	int		max_val;
	t_list	*found;

	max_val = INT_MIN;
	while (head != NULL && count)
	{
		if (head->data >= max_val)
		{
			max_val = head->data;
			found = head;
		}
		head = head->next;
		count--;
	}
	return (found->i_tmp);
}
