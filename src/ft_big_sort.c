/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:57:23 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/22 20:55:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calculate_mov(char **stack_b, char *num, size_t pos, t_cst_ms mov)
{
	int	max;
	int	num_p;

	num_p = ft_atoi(num);
	max = ft_atoi(stack_b[ft_where_is_max(stack_b)]);
	mov.ra = pos;
	mov.total = pos;
	if ()
}

t_cst_ms	ft_best_move(char ***stack_a, char ***stack_b)
{
	t_cst_ms	act;
	t_cst_ms	better;
	size_t		cnt;

	cnt = 1;
	ft_calculate_mov(*stack_b, *stack_a[0], 0, better);
	while (*stack_a[cnt])
	{
		ft_calculate_mov(*stack_b, *stack_a[cnt], cnt, act);
		if (act.total < better.total)
			better = act;
		cnt++;
	}
	return (better);
}

void	ft_big_sort(char ***stack_a, char ***stack_b)
{
	/*t_cst_ms	moves;

	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	while (ft_arr_strlen(*stack_a) != 3 && !ft_is_sorted(*stack_a))
	{
		moves = ft_best_move(stack_a, stack_b);

	}*/
}
