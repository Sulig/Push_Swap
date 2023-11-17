/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:54:55 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/17 13:49:29 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_reverse_a(char **stack_a)
{
	long	act;
	long	bef;
	char	*last;

	if (stack_a)
	{
		last = NULL;
		act = (long) ft_arr_strlen(stack_a) - 1;
		last = stack_a[act];
		while (stack_a[act])
		{
			if (act - 1 > -1)
				bef = act - 1;
			else
				break ;
			stack_a[act] = stack_a[bef];
			act--;
		}
		stack_a[0] = last;
	}
}

void	ft_reverse_b(char **stack_b)
{
	long	act;
	long	bef;
	char	*last;

	if (stack_b)
	{
		last = NULL;
		act = (long) ft_arr_strlen(stack_b) - 1;
		last = stack_b[act];
		while (stack_b[act])
		{
			if (act - 1 > -1)
				bef = act - 1;
			else
				break ;
			stack_b[act] = stack_b[bef];
			act--;
		}
		stack_b[0] = last;
	}
}

static void	ft_reverse(char **stack)
{
	long	act;
	long	bef;
	char	*last;

	if (stack)
	{
		last = NULL;
		act = (long) ft_arr_strlen(stack) - 1;
		last = stack[act];
		while (stack[act])
		{
			if (act - 1 > -1)
				bef = act - 1;
			else
				break ;
			stack[act] = stack[bef];
			act--;
		}
		stack[0] = last;
	}
}

void	ft_reverse_r(char **stack_a, char **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
}
