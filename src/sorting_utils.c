/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:10:45 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/07 14:51:19 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(long *stack, int len)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = stack[i];
	while (i < len)
	{
		if (stack[i] < smallest)
			smallest = stack[i];
		i++;
	}
	return (smallest);
}

int	find_biggest(long *stack, int len)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = stack[i];
	while (i < len)
	{
		if (stack[i] > biggest)
			biggest = stack[i];
		i++;
	}
	return (biggest);
}

int	is_organized(long *stack, int len)
{
	int	i;
	int	smallest;
	int	biggest;

	i = len - 1;
	smallest = find_smallest(stack, len);
	biggest = find_biggest(stack, len);
	while (i > 0)
	{
		if (stack[i] < stack[i - 1])
		{
			if (stack[i] == smallest && stack[i - 1] == biggest)
				i--;
			else
				return (0);
		}
		else
			i--;
	}
	return (1);
}

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = stacks->len_a - 1;
	while (i > 0)
	{
		if (stacks->stack_a[i] < stacks->stack_a[i - 1])
			return (0);
		i--;
	}
	return (1);
}
