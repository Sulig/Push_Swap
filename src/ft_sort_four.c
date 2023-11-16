/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:24 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/16 13:14:41 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_in_one(char **stack_a)
{
	size_t	min;
	size_t	max;

	min = ft_where_is_min(stack_a);
	max = ft_where_is_max(stack_a);
	if (min == 1 && max == 3)
		if (ft_is_smaller_than(stack_a[0], stack_a[2]))
			ft_swap_a(stack_a);
	if (min == 1 && max == 0)
		if (ft_is_smaller_than(stack_a[2], stack_a[3]))
			ft_rotate_a(stack_a);
	if (min == 3 && max == 2)
		if (ft_is_smaller_than(stack_a[0], stack_a[1]))
			ft_reverse_a(stack_a);
	if (ft_is_sorted(stack_a))
		return (1);
	return (0);
}

static int	ft_sort_in_two(char **stack_a)
{
	size_t	min;
	size_t	max;

	min = ft_where_is_min(stack_a);
	max = ft_where_is_max(stack_a);
	if (min == 3 && max == 2)
		if (!ft_is_smaller_than(stack_a[0], stack_a[1]))
			ft_swap_a(stack_a);
	if (min == 3 && max == 1)
		if (ft_is_smaller_than(stack_a[0], stack_a[2]))
			ft_swap_a(stack_a);
	if (min == 0 && max == 1)
		if (ft_is_smaller_than(stack_a[2], stack_a[3]))
			ft_swap_a(stack_a);
	return (ft_sort_in_one(stack_a));
}

void	ft_sort_four(char ***stack_a, char ***stack_b)
{
	size_t	min;

	min = ft_where_is_min(*stack_a);
	if (ft_sort_in_two(*stack_a))
		return ;
	if (min == 1)
		ft_swap_a(*stack_a);
	else if (min == 3)
		ft_reverse_a(*stack_a);
	else if (min == 2)
	{
		ft_rotate_a(*stack_a);
		ft_rotate_a(*stack_a);
	}
	ft_push_b(stack_a, stack_b);
	ft_sort_tree(*stack_a);
	ft_push_a(stack_a, stack_b);
}
