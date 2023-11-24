/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:49:52 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/24 11:43:44 by sadoming         ###   ########.fr       */
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

int	ft_where_is(t_stack *stack, int val, char c)
{
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	if (!c)
	{
		while (stack->arr[i].value != val)
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
