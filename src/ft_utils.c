/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:49:52 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/30 14:30:00 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_null(t_stack *s)
{
	if (!s)
		return (1);
	if (!s->arr)
		return (1);
	if (!s->len)
		return (1);
	return (0);
}

int	ft_is_sorted(t_stack *stack)
{
	size_t	ln;
	size_t	nx;
	int		ok;

	ok = 1;
	ln = 0;
	if (!stack)
		return (0);
	while (ln < stack->len)
	{
		nx = ln + 1;
		while (nx < stack->len)
		{
			if (stack->arr[ln].value > stack->arr[nx].value)
				ok = 0;
			nx++;
		}
		ln++;
	}
	return (ok);
}

int	ft_is_sorted_inverse(t_stack *stack)
{
	size_t	ln;
	size_t	nx;
	int		ok;

	ok = 1;
	ln = stack->len;
	if (!stack)
		return (0);
	while (ln--)
	{
		nx = ln;
		while (nx--)
			if (stack->arr[ln].value > stack->arr[nx].value)
				ok = 0;
	}
	return (ok);
}

size_t	ft_where_is(t_stack *stack, size_t index, char c)
{
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	if (!c)
	{
		while (stack->arr[i].index != index && i < stack->len)
			i++;
		return (i);
	}
	while (i < stack->len)
	{
		if (c == '<')
			if (stack->arr[i].index < stack->arr[pos].index)
				pos = i;
		if (c == '>')
			if (stack->arr[i].index > stack->arr[pos].index)
				pos = i;
		i++;
	}
	return (pos);
}

void	ft_set_last_five(t_stack *s, t_chunk *chunk)
{
	size_t	i;
	size_t	last_five;

	i = 0;
	chunk->chunks++;
	last_five = s->len - 5;
	while (i < s->len)
	{
		if (s->arr[i].index >= last_five)
		{
			s->arr[i].last_five = 1;
			s->arr[i].g_chunk++;
		}
		else
			s->arr[i].last_five = 0;
		i++;
	}
	chunk->g_chunks[chunk->chunks - 1].max = s->len - 1;
	chunk->g_chunks[chunk->chunks - 1].min = last_five;
}
