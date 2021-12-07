#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c < 58)
		return (1);
	return (0);
}

static int ft_check_rmd(const char *str)
{
    int flag;
    int i = 0;

    flag = 0;
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
    int     flag;

	val = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
    flag = ft_check_rmd(str);
    if (flag == 1)
        ft_fatal_error(DEFAULT_ERR);
	while (*str >= '0' && *str <= '9')
	{
		val = val * 10 + *str - '0';
		if (val > 2147483648 && sign == -1)
			ft_fatal_error(DEFAULT_ERR);
		else if (val > 2147483648)
			ft_fatal_error(DEFAULT_ERR);
		str++;
	}
	return (val * sign);
}