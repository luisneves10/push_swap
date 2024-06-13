/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:20:27 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/13 12:40:53 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

typedef struct s_stacks
{
	long	*stack_a;
	long	*stack_b;
	int		len_a;
	int		len_b;
	int		topush;
	int		next_smallest;
}				t_stacks;

/*-----------------------------PARSE PARAMS-----------------------------*/
t_stacks	*str_to_stack(char *s, t_stacks *stacks);
t_stacks	*params_to_stack(char **params, t_stacks *stacks);

/*-----------------------------VALID PARAMS-----------------------------*/
int			args_are_n(char **s);
int			no_duplicates(t_stacks *stacks);
int			is_all_int(t_stacks *stacks);

/*-------------------------------SORTING--------------------------------*/
void		sort_init(t_stacks *stacks);
void		sort_three(t_stacks *stacks);
void		sort_big_stack(t_stacks *stacks);

int			find_smallest(long *stack, int len);
int			find_biggest(long *stack, int len);
int			is_organized(long *stack, int len);
int			is_sorted(t_stacks *stacks);

/*---------------------------SORT OPERATIONS---------------------------*/
void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		swap_both(t_stacks *stacks);
void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_both(t_stacks *stacks);
void		rrotate_a(t_stacks *stacks);
void		rrotate_b(t_stacks *stacks);
void		rrotate_both(t_stacks *stacks);
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		sort_operation(t_stacks *stacks, char *str);

/*---------------------------------UTILS--------------------------------*/
void		free_stacks(t_stacks *stacks);
int			print_error(void);
int			count_strings(char **s);
long		ft_atol(const char *s);

/*----------------------------SORT_BIG UTILS----------------------------*/
int			common_ops(t_stacks *stacks, int index_a, int index_b);
int			total_ops(t_stacks *stacks, int index);
int			find_cheapest(t_stacks *stacks);
int			find_next_biggest(long *stack, int size, int value);
int			find_next_smallest(long *stack, int len, int value);
void		prepare_stack_a(t_stacks *stacks, int value);
void		rotate_together(t_stacks *stacks, int best_index, int i);
void		finalize_push_cheapest(t_stacks *stacks, int best_index, int i);

#endif
