/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:52:13 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/13 14:19:39 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_if_null_args(char **args, int argc)
{
	int		ok;
	size_t	cnt;

	ok = 1;
	cnt = 1;
	if (!args || argc <= 1)
		return (0);
	if (!args[cnt])
		ok = 0;
	while (args[cnt])
	{
		if (!args[cnt][0])
			ok = 0;
		cnt++;
	}
	if (!ok)
		ft_printf_fd(2, "Error\n");
	return (ok);
}

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

	cnt = 0;
	while (str[cnt])
	{
		if (!ft_is_acceptable(str[cnt]))
			return (0);
		else if (ft_is_acceptable(str[cnt]) == 2)
		{
			if (str[cnt + 1] == ' ' || !str[cnt + 1])
				return (0);
			if (ft_is_acceptable(str[cnt + 1]) == 2)
				return (0);
			if (ft_is_acceptable(str[cnt - 1]) == 1)
				return (0);
		}
		cnt++;
	}
	return (1);
}

int	ft_check_max(char **arr)
{
	size_t	cnt;
	size_t	len;
	size_t	i;
	long	act;

	cnt = 0;
	while (arr[cnt])
	{
		i = 0;
		if (arr[cnt][i] == '-')
			i++;
		while (arr[cnt][i] && arr[cnt][i] == '0')
			i++;
		if (arr[cnt][i])
		{
			len = ft_strlen(arr[cnt] + i);
			if (len > 10)
				return (0);
		}
		act = ft_atol(arr[cnt]);
		if (act > 2147483647 || act < -2147483648)
			return (0);
		cnt++;
	}
	return (1);
}

int	ft_check_double(char *joined)
{
	size_t	ln;
	size_t	next;
	char	**stack;
	int		ok;

	ok = 1;
	ln = 0;
	stack = ft_split(joined, ' ');
	while (stack[ln])
	{
		next = ln + 1;
		while (stack[next])
		{
			if (ft_atoi(stack[ln]) == ft_atoi(stack[next]))
				ok = 0;
			next++;
		}
		ln++;
	}
	stack = ft_auto_free_arr(stack);
	if (!ok)
		ft_printf_fd(2, "Error\n");
	return (ok);
}
