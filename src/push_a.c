/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:02:32 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/12 11:35:07 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rearr_stacks(t_stacks *stacks, long *new_stack_a, long *new_stack_b)
{
	int	i;

	i = 1;
	new_stack_a[0] = stacks->stack_b[0];
	while (i < stacks->len_a + 1)
	{
		new_stack_a[i] = stacks->stack_a[i - 1];
		i++;
	}
	i = 0;
	while (i < stacks->len_b - 1)
	{
		new_stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
}

void	push_a(t_stacks *stacks)
{
	long	*new_stack_a;
	long	*new_stack_b;

	new_stack_a = malloc(sizeof(long) * (stacks->len_a + 1));
	new_stack_b = malloc(sizeof(long) * (stacks->len_b - 1));
	if (!new_stack_a || !new_stack_b)
		return ;
	rearr_stacks(stacks, new_stack_a, new_stack_b);
	free (stacks->stack_a);
	free (stacks->stack_b);
	stacks->stack_a = new_stack_a;
	stacks->stack_b = new_stack_b;
	stacks->len_a ++;
	stacks->len_b --;
}
