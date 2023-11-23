/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:24 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/23 20:28:42 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_in_one(t_stack *a)
{
	if (a->arr[0].index == 1 && a->arr[1].index == 0)
		if (a->arr[2].index == 2)
			ft_sa(a);
	if (a->arr[0].index == 1 && a->arr[1].index == 2)
		if (a->arr[2].index == 3)
			ft_rra(a);
	if (a->arr[0].index == 3 && a->arr[1].index == 0)
		if (a->arr[2].index == 1)
			ft_ra(a);
	if (ft_is_sorted(a))
		return (1);
	return (0);
}

static int	ft_sort_in_two(t_stack *a)
{
	if (a->arr[0].index == 0 && a->arr[1].index == 2)
		if (a->arr[2].index == 3)
			ft_rra(a);
	if (a->arr[0].index == 0 && a->arr[1].index == 3)
		if (a->arr[2].index == 1)
			ft_sa(a);
	if (a->arr[0].index == 2 && a->arr[1].index == 1)
		if (a->arr[2].index == 3)
			ft_sa(a);
	if (a->arr[0].index == 2 && a->arr[1].index == 3)
		if (a->arr[2].index == 0)
			ft_rra(a);
	return (ft_sort_in_one(a));
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	size_t	min;

	min = ft_where_is(a, 0, '<');
	if (ft_sort_in_two(a))
		return ;
	if (min == 1)
		ft_sa(a);
	else if (min == 3)
		ft_rra(a);
	else if (min == 2)
	{
		ft_ra(a);
		ft_ra(a);
	}
	ft_pb(a, b);
	ft_sort_tree(a);
	ft_pa(a, b);
}
