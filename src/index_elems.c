/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:45:52 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/31 05:43:17 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_index_new_iter(t_list **head, int count, int flag)
{
	int		j;
	t_list	*current;

	j = 0;
	current = *head;
	while (j < count)
	{
		if (flag)
			current->i_tmp = 0;
		else
			current->i = 0;
		current = current->next;
		j++;
	}
}

static void	index_elems_extra(t_list **head, int min, int group_count, int flag)
{
	int		i;
	int		tmp;
	t_list	*current;
	t_list	*holder;

	i = 0;
	while (++i < group_count)
	{
		current = *head;
		tmp = INT_MAX;
		while (current)
		{
			if (current->data > min && current->data <= tmp)
			{
				tmp = current->data;
				holder = current;
			}
			current = current->next;
		}
		if (flag)
			holder->i_tmp = i;
		else
			holder->i = i;
		min = holder->data;
	}
}

void	index_elems(t_list **head)
{
	int	min;
	int	count;

	min = find_min(head);
	count = count_nodes(*head);
	clear_index_new_iter(head, count, 0);
	index_elems_extra(head, min, count, 0);
}

void	tmp_index_elems(t_list **head, int group_count)
{
	int		min;

	min = tmp_find_min(head, group_count);
	clear_index_new_iter(head, group_count, 1);
	index_elems_extra(head, min, group_count, 1);
}
