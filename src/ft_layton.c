/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_layton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:24:08 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/14 20:09:44 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tree(char **stack_a)
{
	size_t	min;
	size_t	max;

	min = ft_where_is_min(stack_a);
	max = ft_where_is_max(stack_a);
	if (min == 1 && max == 2)
		ft_swap_a(stack_a);
	else if (min == 1 && max == 0)
		ft_rotate_a(stack_a);
	else if (min == 2 && max == 1)
		ft_reverse_a(stack_a);
	else if (min == 0 && max == 1)
	{
		ft_swap_a(stack_a);
		ft_rotate_a(stack_a);
	}
	else if (min == 2 && max == 0)
	{
		ft_swap_a(stack_a);
		ft_reverse_a(stack_a);
	}
}

void	ft_switch_lenght(char ***stack_a, char ***stack_b)
{
	size_t	len;

	len = ft_arr_strlen(*stack_a);
	if (ft_is_sorted(*stack_a))
		return ;
	else if (len == 2)
		ft_swap_a(*stack_a);
	else if (len == 3)
		ft_sort_tree(*stack_a);
	ft_printf("", stack_b);
}