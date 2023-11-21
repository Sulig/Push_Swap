/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:57:23 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/21 20:33:21 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big_sort(char ***stack_a, char ***stack_b)
{
	t_cost_moves	moves;

	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	while (ft_arr_strlen(*stack_a) != 3)
	{
		moves = ft_best_move(stack_a, stack_b);

	}
}
