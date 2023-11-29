/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decide_to_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:14:49 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/29 14:31:05 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_moves_to_first(t_stack *s, t_piece first)
{
	size_t	pos;
	size_t	moves;

	moves = 0;
	pos = ft_where_is(s, first.value, '\0');
	if (pos < ((s->len - 1) / 2))
	{
		while (s->arr[0].value != first.value)
		{
			ft_rotate(s);
			moves++;
		}
	}
	else
	{
		while (s->arr[0].value != first.value)
		{
			ft_reverse(s);
			moves++;
		}
	}
	return (moves);
}

t_piece	ft_decide_to_push(t_stack *s, size_t num_1, size_t num_2)
{
	t_stack	copy_1;
	t_stack	copy_2;
	t_piece	to_push;
	size_t	mv_1;
	size_t	mv_2;

	ft_dup_stack(s, &copy_1);
	ft_dup_stack(s, &copy_2);
	if (num_1 >= s->len)
	{
		to_push.ok = 0;
		ft_free_stacks(&copy_1, &copy_2);
		return (to_push);
	}
	mv_1 = ft_moves_to_first(&copy_1, s->arr[num_1]);
	mv_2 = ft_moves_to_first(&copy_2, s->arr[num_2]);
	if (mv_1 < mv_2)
		to_push = s->arr[num_1];
	if (mv_2 < mv_1)
		to_push = s->arr[num_2];
	else
		to_push = s->arr[num_1];
	to_push.ok = 1;
	ft_free_stacks(&copy_1, &copy_2);
	return (to_push);
}
