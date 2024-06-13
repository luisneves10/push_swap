/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:45:58 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/12 11:20:06 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_init(t_stacks *stacks)
{
	int	smallest;
	int	i;

	smallest = find_smallest(stacks->stack_a, stacks->len_a);
	if (stacks->len_a == 2 && stacks->stack_a[0] > stacks->stack_a[1])
		sort_operation(stacks, "sa");
	else if (stacks->len_a == 3)
		sort_three(stacks);
	else if (stacks->len_a > 3 && !is_organized(stacks->stack_a, stacks->len_a))
		sort_big_stack(stacks);
	if (!is_sorted(stacks) && is_organized(stacks->stack_a, stacks->len_a))
	{
		i = 0;
		while (stacks->stack_a[i] != smallest)
			i++;
		while (stacks->stack_a[0] != smallest)
		{
			if (i <= stacks->len_a / 2)
				sort_operation(stacks, "ra");
			else
				sort_operation(stacks, "rra");
		}
	}
	return ;
}
