/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:46:02 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/07 15:23:46 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_case1(t_stacks *stacks)
{
	if ((stacks->stack_a[1] < stacks->stack_a[2])
		&& (stacks->stack_a[0] > stacks->stack_a[2]))
	{
		sort_operation(stacks, "ra");
		return ;
	}
	if ((stacks->stack_a[1] > stacks->stack_a[2])
		&& (stacks->stack_a[0] > stacks->stack_a[2]))
	{
		sort_operation(stacks, "ra");
		sort_operation(stacks, "sa");
		return ;
	}
	if ((stacks->stack_a[1] < stacks->stack_a[2])
		&& (stacks->stack_a[0] < stacks->stack_a[2]))
		sort_operation(stacks, "sa");
}

static void	sort_three_case2(t_stacks *stacks)
{
	sort_operation(stacks, "rra");
	if (stacks->stack_a[1] < stacks->stack_a[0])
		sort_operation(stacks, "sa");
}

void	sort_three(t_stacks *stacks)
{
	if (stacks->stack_a[1] < stacks->stack_a[0])
		sort_three_case1(stacks);
	else if (stacks->stack_a[1] > stacks->stack_a[0])
		sort_three_case2(stacks);
}
