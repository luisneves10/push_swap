/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:46:14 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/13 10:44:29 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_biggest(long *stack, int len, int value)
{
	int	i;
	int	next_biggest;

	i = 0;
	next_biggest = find_biggest(stack, len);
	while (i < len)
	{
		if (stack[i] > value && stack[i] < next_biggest)
			next_biggest = stack[i];
		i++;
	}
	if (next_biggest < value)
		return (find_smallest(stack, len));
	return (next_biggest);
}

int	find_next_smallest(long *stack, int len, int value)
{
	int	i;
	int	next_smallest;

	i = 0;
	next_smallest = find_smallest(stack, len);
	while (i < len)
	{
		if (stack[i] < value && stack[i] > next_smallest)
			next_smallest = stack[i];
		i++;
	}
	if (next_smallest > value)
		return (find_biggest(stack, len));
	return (next_smallest);
}

void	prepare_stack_a(t_stacks *stacks, int value)
{
	int	i;
	int	next_biggest;

	i = 0;
	next_biggest = find_next_biggest(stacks->stack_a, stacks->len_a, value);
	while (i < stacks->len_a)
	{
		if (stacks->stack_a[i] == next_biggest)
			break ;
		i++;
	}
	while (stacks->stack_a[0] != next_biggest)
	{
		if (i <= stacks->len_a / 2)
			sort_operation(stacks, "ra");
		else
			sort_operation(stacks, "rra");
	}
}

void	rotate_together(t_stacks *stacks, int best_index, int i)
{
	while ((stacks->stack_a[0] != stacks->topush)
		&& (stacks->stack_b[0] != stacks->next_smallest))
	{
		if ((best_index <= stacks->len_a / 2) && (i <= stacks->len_b / 2))
			sort_operation(stacks, "rr");
		else if ((best_index > stacks->len_a / 2) && (i > stacks->len_b / 2))
			sort_operation(stacks, "rrr");
		else if ((best_index <= stacks->len_a / 2) && (i > stacks->len_b / 2))
		{
			sort_operation(stacks, "ra");
			sort_operation(stacks, "rrb");
		}
		else if ((best_index > stacks->len_a / 2) && (i <= stacks->len_b / 2))
		{
			sort_operation(stacks, "rb");
			sort_operation(stacks, "rra");
		}
	}
}

void	finalize_push_cheapest(t_stacks *stacks, int best_index, int i)
{
	while (stacks->stack_a[0] != stacks->topush)
	{
		if (best_index <= stacks->len_a / 2)
			sort_operation(stacks, "ra");
		else
			sort_operation(stacks, "rra");
	}
	while (stacks->stack_b[0] != stacks->next_smallest)
	{
		if (i <= stacks->len_b / 2)
			sort_operation(stacks, "rb");
		else
			sort_operation(stacks, "rrb");
	}
}
