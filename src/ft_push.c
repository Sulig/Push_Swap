/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:15:28 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/27 15:32:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack *s, t_piece first)
{
	size_t	i;
	size_t	j;
	t_piece	*new;

	i = 0;
	j = 1;
	new = ft_calloc(sizeof(t_piece), s->len + 2);
	if (!new)
		return (0);
	new[0] = first;
	while (i < s->len)
	{
		new[j] = s->arr[i];
		i++;
		j++;
	}
	free(s->arr);
	s->arr = new;
	s->len++;
	return (1);
}

int	ft_pop(t_stack *s)
{
	size_t	i;
	size_t	j;
	t_piece	*new;

	i = 1;
	j = 0;
	new = ft_calloc(sizeof(t_piece), s->len);
	if (!new)
		return (0);
	while (i < s->len)
	{
		new[j] = s->arr[i];
		i++;
		j++;
	}
	free(s->arr);
	s->arr = new;
	s->len--;
	return (1);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	if (b->len)
	{
		if (ft_push(a, b->arr[0]))
			if (ft_pop(b))
			  ft_printf("pa\n");
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (a->len)
	{
		if (ft_push(b, a->arr[0]))
			if (ft_pop(a))
			  ft_printf("pb\n");
	}
}
