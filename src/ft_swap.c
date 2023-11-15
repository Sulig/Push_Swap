/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:54:04 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/15 17:33:01 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(char **stack_a)
{
	char	*tmp;

	if (ft_arr_strlen(stack_a) > 1)
	{
		tmp = stack_a[1];
		stack_a[1] = stack_a[0];
		stack_a[0] = tmp;
		tmp = NULL;
		ft_printf("sa\n");
	}
}

void	ft_swap_b(char **stack_b)
{
	char	*tmp;

	if (ft_arr_strlen(stack_b) > 1)
	{
		tmp = stack_b[1];
		stack_b[1] = stack_b[0];
		stack_b[0] = tmp;
		tmp = NULL;
		ft_printf("sb\n");
	}
}

void	ft_swap(char **stack)
{
	char	*tmp;

	if (ft_arr_strlen(stack) > 1)
	{
		tmp = stack[1];
		stack[1] = stack[0];
		stack[0] = tmp;
		tmp = NULL;
	}
}

void	ft_swap_s(char **stack_a, char **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
