/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:40:46 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/13 11:32:15 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cheapest(t_stacks *stacks)
{
	int	best_index;
	int	i;

	i = 0;
	best_index = find_cheapest(stacks);
	stacks->topush = stacks->stack_a[best_index];
	stacks->next_smallest = find_next_smallest(stacks->stack_b, stacks->len_b,
			stacks->topush);
	while (i < stacks->len_b)
	{
		if (stacks->stack_b[i] == stacks->next_smallest)
			break ;
		i++;
	}
	rotate_together(stacks, best_index, i);
	finalize_push_cheapest(stacks, best_index, i);
	sort_operation(stacks, "pb");
}

void	push_back_to_a(t_stacks *stacks)
{
	prepare_stack_a(stacks, stacks->stack_b[0]);
	sort_operation(stacks, "pa");
}

void	sort_big_stack(t_stacks *stacks)
{
	sort_operation(stacks, "pb");
	if (stacks->len_a > 3)
		sort_operation(stacks, "pb");
	while (stacks->len_a > 3)
		push_cheapest(stacks);
	if (!is_sorted(stacks))
		sort_three(stacks);
	while (stacks->len_b > 0)
		push_back_to_a(stacks);
}
