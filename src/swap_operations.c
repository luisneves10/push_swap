/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:05:20 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/07 15:09:07 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	long	tmp;

	if (!stacks || !stacks->stack_a)
		return ;
	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
}

void	swap_b(t_stacks *stacks)
{
	long	tmp;

	if (!stacks || !stacks->stack_b)
		return ;
	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
}

void	swap_both(t_stacks *stacks)
{
	if (stacks->stack_a)
		swap_a(stacks);
	if (stacks->stack_b)
		swap_b(stacks);
}
