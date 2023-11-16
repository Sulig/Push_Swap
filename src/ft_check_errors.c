/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:22:53 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/16 14:09:38 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_acceptable(int c)
{
	int		ok;

	ok = 0;
	if (c >= '0' && c <= '9')
		ok = 1;
	else if (c == '-' || c == '+')
		ok = 2;
	else if (c == ' ')
		ok = 3;
	return (ok);
}

int	ft_check_digit(char *str)
{
	size_t	cnt;
	int		ok;

	cnt = 0;
	ok = 1;
	while (str[cnt])
	{
		if (!ft_is_acceptable(str[cnt]))
			ok = 0;
		else if (ft_is_acceptable(str[cnt]) == 2)
		{
			if (str[cnt + 1] == ' ' || !str[cnt + 1])
				ok = 0;
			if (ft_is_acceptable(str[cnt + 1]) == 2)
				ok = 0;
			if (ft_is_acceptable(str[cnt - 1]) == 1)
				ok = 0;
		}
		cnt++;
	}
	if (!ok)
		ft_printf("Error\n");
	return (ok);
}

int	ft_check_max(char **arr)
{
	size_t	cnt;
	long	act;

	cnt = 0;
	while (arr[cnt])
	{
		act = ft_atol(arr[cnt]);
		if (act < -2147483648 || act > 2147483647)
		{
			ft_printf("Error\n");
			return (0);
		}
		cnt++;
	}
	return (1);
}

int	ft_check_double(char **stack)
{
	size_t	ln;
	size_t	next;
	int		st;
	int		nx;
	int		ok;

	ok = 1;
	ln = 0;
	while (stack[ln])
	{
		st = ft_atoi(stack[ln]);
		next = ln + 1;
		while (stack[next])
		{
			nx = ft_atoi(stack[next]);
			if (st == nx)
				ok = 0;
			next++;
		}
		ln++;
	}
	if (!ok)
		ft_printf("Error\n");
	return (ok);
}
