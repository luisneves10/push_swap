/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:43:58 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/07 15:09:16 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	int		i;
	long	tmp;

	if (!stacks || !stacks->stack_a)
		return ;
	i = 0;
	tmp = stacks->stack_a[0];
	while (i < stacks->len_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[i] = tmp;
}

void	rotate_b(t_stacks *stacks)
{
	int		i;
	long	tmp;

	if (!stacks || !stacks->stack_b)
		return ;
	i = 0;
	tmp = stacks->stack_b[0];
	while (i < stacks->len_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[i] = tmp;
}

void	rotate_both(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->stack_a)
		rotate_a(stacks);
	if (stacks->stack_b)
		rotate_b(stacks);
}
