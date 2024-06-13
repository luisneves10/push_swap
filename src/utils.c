/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:08:06 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/07 14:39:44 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->stack_a)
	{
		free (stacks->stack_a);
		stacks->stack_a = NULL;
	}
	if (stacks->stack_b)
	{
		free (stacks->stack_b);
		stacks->stack_b = NULL;
	}
	free (stacks);
	stacks = NULL;
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	count_strings(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_atol(const char *s)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (((s[i] >= 9 && s[i] <= 13) || s[i] == 32) && (s[i] != '\0'))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9') && (s[i] != '\0'))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * sign);
}
