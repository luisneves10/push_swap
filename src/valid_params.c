/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:51:05 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/13 14:01:02 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_are_n(char **s)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (s[i])
	{
		flag = 1;
		j = 0;
		while (s[i][j])
		{
			if (flag && (s[i][j] == '-' || s[i][j] == '+'))
			{
				j++;
				flag = 0;
			}
			if (ft_isdigit(s[i][j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	no_duplicates(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	if (!stacks || !stacks->stack_a)
		return (0);
	while (i < stacks->len_a - 1)
	{
		j = i + 1;
		while (j < stacks->len_a)
		{
			if (stacks->stack_a[j] == stacks->stack_a[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_all_int(t_stacks *stacks)
{
	int	i;

	if (!stacks || !stacks->stack_a)
		return (0);
	i = 0;
	while (i < stacks->len_a)
	{
		if (stacks->stack_a[i] >= -2147483648
			&& stacks->stack_a[i] <= 2147483647)
			i++;
		else
			return (0);
	}
	return (1);
}
