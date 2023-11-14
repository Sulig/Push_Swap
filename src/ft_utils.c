/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:28:11 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/14 19:49:56 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(char **stack)
{
	size_t	ln;
	size_t	next;
	int		st;
	int		nx;
	int		ok;

	ok = 1;
	ln = 0;
	if (!stack)
		return (0);
	while (stack[ln])
	{
		st = ft_atoi(stack[ln]);
		next = ln + 1;
		while (stack[next])
		{
			nx = ft_atoi(stack[next]);
			if (st > nx)
				ok = 0;
			next++;
		}
		ln++;
	}
	return (ok);
}

size_t	ft_where_is_min(char **stack)
{
	size_t	cnt;
	size_t	pos;
	int		act;
	int		min;

	cnt = 0;
	pos = 0;
	if (!stack)
		return (0);
	min = ft_atoi(stack[0]);
	while (stack[cnt])
	{
		act = ft_atoi(stack[cnt]);
		if (act < min)
		{
			min = act;
			pos = cnt;
		}
		cnt++;
	}
	return (pos);
}

size_t	ft_where_is_max(char **stack)
{
	size_t	cnt;
	size_t	pos;
	int		act;
	int		max;

	cnt = 0;
	pos = 0;
	if (!stack)
		return (0);
	max = ft_atoi(stack[0]);
	while (stack[cnt])
	{
		act = ft_atoi(stack[cnt]);
		if (act > max)
		{
			max = act;
			pos = cnt;
		}
		cnt++;
	}
	return (pos);
}
