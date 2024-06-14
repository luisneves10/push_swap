/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:20:17 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/14 14:45:25 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	if (argc > 2)
		stacks = params_to_stack(argv + 1, stacks);
	else if (argc == 2)
		stacks = str_to_stack(argv[1], stacks);
	if (!stacks)
		return (print_error());
	if (!is_sorted(stacks))
		sort_init(stacks);
	free_stacks(stacks);
	return (0);
}
