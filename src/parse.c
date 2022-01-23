/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:45:29 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/30 05:19:25 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_atoi(av[i]);
		i++;
	}
	return (0);
}

void	check_duplicate_values(t_list *head)
{
	t_list	*current;
	t_list	*following;

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

int	list_is_sorted(t_list *a, t_list *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}
