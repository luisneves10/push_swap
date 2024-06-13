/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:25:19 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/07 10:56:18 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*params_to_stack(char **params, t_stacks *stacks)
{
	int		i;

	if (!params || !stacks)
		return (NULL);
	stacks->stack_b = NULL;
	stacks->len_b = 0;
	stacks->len_a = count_strings(params);
	stacks->stack_a = malloc(sizeof(long) * (stacks->len_a));
	if (!stacks->stack_a)
		return (NULL);
	i = 0;
	while (params[i])
	{
		if (!args_are_n(params))
			return (free_stacks(stacks), NULL);
		stacks->stack_a[i] = ft_atol((const char *)params[i]);
		i++;
	}
	if (!no_duplicates(stacks) || !is_all_int(stacks))
		return (free_stacks(stacks), NULL);
	return (stacks);
}

t_stacks	*str_to_stack(char *s, t_stacks *stacks)
{
	int		i;
	char	**as;

	if (!s || !stacks)
		return (NULL);
	stacks->stack_a = 0;
	as = ft_split(s, ' ');
	if (!as)
		return (NULL);
	i = 0;
	stacks = params_to_stack(as, stacks);
	while (as[i])
		free (as[i++]);
	free (as);
	return (stacks);
}
