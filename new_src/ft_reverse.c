/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:04:06 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/23 17:06:27 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack *s)
{
	size_t	act;
	size_t	bef;
	t_piece	last;

	if (s->len)
	{
		last = s->arr[s->len - 1];
		act = s->len;
		while (act--)
		{
			bef = act - 1;
			if (bef < s->len)
				s->arr[act] = s->arr[bef];
		}
		s->arr[0] = last;
	}
}

void	ft_rra(t_stack *a)
{
	if (a->len)
	{
		ft_reverse(a);
		ft_printf("rra\n");
	}
}

void	ft_rrb(t_stack *b)
{
	if (b->len)
	{
		ft_reverse(b);
		ft_printf("rrb\n");
	}
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse(a);
	ft_reverse(b);
	ft_printf("rrr\n");
}
