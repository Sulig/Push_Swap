/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:29:57 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/23 16:41:41 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *s)
{
	size_t	tmp_v;
	size_t	tmp_i;

	if (s->len > 1)
	{
		tmp_v = s->arr[0].value;
		tmp_i = s->arr[0].index;
		s->arr[0].value = s->arr[1].value;
		s->arr[0].index = s->arr[1].index;
		s->arr[1].value = tmp_v;
		s->arr[1].index = tmp_i;
	}
}

void	ft_sa(t_stack *a)
{
	if (a->len > 1)
	{
		ft_swap(a);
		ft_printf("sa\n");
	}
}

void	ft_sb(t_stack *b)
{
	if (b->len > 1)
	{
		ft_swap(b);
		ft_printf("sb\n");
	}
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
