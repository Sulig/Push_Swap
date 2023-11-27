/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:53:41 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/27 16:27:27 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		  ft_pop(b);
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (a->len)
	{
		if (ft_push(b, a->arr[0]))
		  ft_pop(a);
	}
}
