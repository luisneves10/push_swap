/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:08:51 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/12 14:35:02 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_operation(t_stacks *stacks, char *str)
{
	if (ft_strncmp(str, "sa", 2) == 0)
		swap_a(stacks);
	if (ft_strncmp(str, "sb", 2) == 0)
		swap_b(stacks);
	if (ft_strncmp(str, "ss", 2) == 0)
		swap_both(stacks);
	if (ft_strncmp(str, "ra", 2) == 0)
		rotate_a(stacks);
	if (ft_strncmp(str, "rb", 2) == 0)
		rotate_b(stacks);
	if (ft_strncmp(str, "rr", 3) == 0)
		rotate_both(stacks);
	if (ft_strncmp(str, "rra", 3) == 0)
		rrotate_a(stacks);
	if (ft_strncmp(str, "rrb", 3) == 0)
		rrotate_b(stacks);
	if (ft_strncmp(str, "rrr", 3) == 0)
		rrotate_both(stacks);
	if (ft_strncmp(str, "pa", 2) == 0)
		push_a(stacks);
	if (ft_strncmp(str, "pb", 2) == 0)
		push_b(stacks);
	ft_printf("%s\n", str);
}
