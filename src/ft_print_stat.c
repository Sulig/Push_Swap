/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:28:33 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/15 13:33:20 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack_cnt(char **stack)
{
	size_t	cnt;

	cnt = 0;
	if (!stack)
		ft_printf("\n\033[1;31mNULL & NULL pointer");
	else
	{
		if (!stack[cnt])
		{
			ft_printf("\n\033[1;31mNULL but the pointer is not NULL");
			ft_printf("\n\033[1;33mRemember to free: %p\n", &stack);
		}
		while (stack[cnt])
		{
			ft_printf("[%u]: %s\t", cnt, stack[cnt]);
			cnt++;
		}
	}
	ft_printf("\033[1;37m\n");
}

void	ft_print_stat(char **stack_a, char **stack_b)
{
	size_t	ln_a;
	size_t	ln_b;

	ln_a = ft_arr_strlen(stack_a);
	ln_b = ft_arr_strlen(stack_b);
	ft_printf("\033[1;35m\n ~ Actual status ~\n\n");
	ft_printf("\033[1;33mStack A is Sorted: ");
	if (ft_is_sorted(stack_a))
		ft_printf("\033[1;32mYES\n");
	else
		ft_printf("\033[1;31mNO\n");
	ft_printf("\n\033[1;37mActual len of Stack_A: %u\n", ln_a);
	ft_printf("\033[1;37mActual len of Stack_B: %u\n", ln_b);
	ft_printf("\n\033[1;37mContent of Stack_A:\n");
	ft_print_stack_cnt(stack_a);
	ft_printf("\nMin is in pose: %u\n", ft_where_is_min(stack_a));
	ft_printf("Max is in pose: %u\n", ft_where_is_max(stack_a));
	ft_printf("\n\n\033[1;37mContent of Stack_B:\n");
	ft_print_stack_cnt(stack_b);
	ft_printf("\033[1;35m\n ~ ~~~~~~~~~~~~~~ ~\n\n");
}
