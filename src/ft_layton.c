/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_layton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:24:08 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/29 20:48:33 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tree(t_stack *a)
{
	size_t	min;
	size_t	max;

	min = ft_where_is(a, 0, '<');
	max = ft_where_is(a, 0, '>');
	if (min == 1 && max == 2)
		ft_sa(a);
	else if (min == 1 && max == 0)
		ft_ra(a);
	else if (min == 2 && max == 1)
		ft_rra(a);
	else if (min == 0 && max == 1)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (min == 2 && max == 0)
	{
		ft_sa(a);
		ft_rra(a);
	}
}

void	ft_in_first(t_stack *s, t_piece first, char move)
{
	size_t	pos;

	pos = ft_where_is(s, first.index, '\0');
	if (pos < ((s->len - 1) / 2))
	{
		while (s->arr[0].value != first.value)
		{
			if (move == 'a')
				ft_ra(s);
			else if (move == 'b')
				ft_rb(s);
		}
	}
	else
	{
		while (s->arr[0].value != first.value)
		{
			if (move == 'a')
				ft_rra(s);
			else if (move == 'b')
				ft_rrb(s);
		}
	}
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	size_t	pos;

	pos = ft_where_is(a, 0, '<');
	ft_in_first(a, a->arr[pos], 'a');
	if (!ft_is_sorted(a))
	{
		ft_pb(a, b);
		ft_sort_four(a, b);
		ft_pa(a, b);
	}
}

void	ft_switch_lenght(t_stack *a, t_stack *b)
{
	if (ft_is_sorted(a))
		return ;
	else if (a->len == 2)
		ft_sa(a);
	else if (a->len == 3)
		ft_sort_tree(a);
	else if (ft_can_sort_in_one(a))
		return ;
	else if (a->len == 4)
		ft_sort_four(a, b);
	else if (a->len == 5)
		ft_sort_five(a, b);
	else
		ft_big_sort(a, b);
}
