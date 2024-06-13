/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:01:41 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/13 14:02:20 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	common_ops(t_stacks *stacks, int index_a, int index_b)
{
	int	total;

	total = 0;
	if ((index_a <= stacks->len_a / 2) && (index_b <= stacks->len_b / 2))
	{
		if (index_a > index_b)
			total = index_a;
		else
			total = index_b;
	}
	else if ((index_a > stacks->len_a / 2) && (index_b > stacks->len_b / 2))
	{
		if ((stacks->len_a - index_a) > (stacks->len_b - index_b))
			total = stacks->len_a - index_a;
		else
			total = stacks->len_b - index_b;
	}
	return (total);
}

int	total_ops(t_stacks *stacks, int index_a)
{
	int	index_b;
	int	total;

	index_b = 0;
	stacks->topush = stacks->stack_a[index_a];
	stacks->next_smallest = find_next_smallest(stacks->stack_b,
			stacks->len_b, stacks->topush);
	while (stacks->stack_b[index_b] != stacks->next_smallest)
		index_b++;
	total = common_ops(stacks, index_a, index_b);
	if ((index_a <= stacks->len_a / 2) && (index_b > stacks->len_b / 2))
		total = index_a + (stacks->len_b - index_b);
	else if ((index_a > stacks->len_a / 2) && (index_b <= stacks->len_b / 2))
		total = (stacks->len_a - index_a) + index_b;
	return (total);
}

int	find_cheapest(t_stacks *stacks)
{
	int	min_ops;
	int	best_index;
	int	index_a;
	int	ops;

	index_a = 0;
	min_ops = 2147483647;
	best_index = -1;
	while (index_a < stacks->len_a)
	{
		ops = total_ops(stacks, index_a);
		if (ops < min_ops)
		{
			min_ops = ops;
			best_index = index_a;
		}
		index_a++;
	}
	return (best_index);
}
