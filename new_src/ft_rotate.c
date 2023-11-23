/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:06:37 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/23 17:14:54 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *s)
{
	size_t	act;
	size_t	nex;
	t_piece	first;

	if (s->len > 1)
	{
		first = s->arr[0];
		act = 0;
		while (act < s->len)
		{
			nex = act + 1;
			if (nex < s->len)
				s->arr[act] = s->arr[nex];
			act++;
		}
		s->arr[s->len -1] = first;
	}
}

void	ft_ra(t_stack *a)
{
	if (a->len > 1)
	{
		ft_rotate(a);
		ft_printf("ra\n");
	}
}

void	ft_rb(t_stack *b)
{
	if (b->len > 1)
	{
		ft_rotate(b);
		ft_printf("rr\n");
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
