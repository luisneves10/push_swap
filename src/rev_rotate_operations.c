/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:00:14 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/07 15:09:30 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stacks *stacks)
{
	int		i;
	long	tmp;

	if (!stacks || !stacks->stack_a)
		return ;
	i = stacks->len_a - 1;
	tmp = stacks->stack_a[i];
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[i] = tmp;
}

void	rrotate_b(t_stacks *stacks)
{
	int		i;
	long	tmp;

	if (!stacks || !stacks->stack_b)
		return ;
	i = stacks->len_b - 1;
	tmp = stacks->stack_b[i];
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[i] = tmp;
}

void	rrotate_both(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->stack_a)
		rrotate_a(stacks);
	if (stacks->stack_b)
		rrotate_b(stacks);
}
