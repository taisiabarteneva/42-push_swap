/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:45:59 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/31 05:26:36 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c < 58)
		return (1);
	return (0);
}

static int	check_rmd(const char *str)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			flag = 1;
		i++;
	}
	return (flag);
}

int	ft_atoi(const char *str)
{
	long	val;
	int		sign;
	int		flag;

	val = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	flag = check_rmd(str);
	if (flag == 1)
		fatal_error(DEFAULT_ERR);
	while (*str >= '0' && *str <= '9')
	{
		val = val * 10 + *str - '0';
		if (val > (long)(INT_MAX) + 1 && sign == -1)
			fatal_error(DEFAULT_ERR);
		else if (val > INT_MAX && sign != -1)
			fatal_error(DEFAULT_ERR);
		str++;
	}
	return (val * sign);
}
