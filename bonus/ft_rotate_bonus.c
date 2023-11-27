/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:56:45 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/27 16:28:13 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		ft_rotate(a);
}

void	ft_rb(t_stack *b)
{
	if (b->len > 1)
		ft_rotate(b);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
}
