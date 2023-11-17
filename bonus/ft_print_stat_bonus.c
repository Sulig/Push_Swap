/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stat_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:43:30 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/17 12:51:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_print_stack_cnt(char **stack)
{
	size_t	cnt;

	cnt = 0;
	if (!stack)
		ft_printf("\n\033[1;31mNULL & NULL pointer");
	else
	{
		if (!stack[cnt])
			ft_printf("\n\033[1;31mNULL but the pointer is not NULL");
		while (stack[cnt])
		{
			ft_printf("[%u]: %s\t", cnt, stack[cnt]);
			cnt++;
		}
		ft_printf("\n\033[1;33mRemember to free: %p\033[1;37m\n", stack);
	}
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
	ft_printf("\n\n\033[1;37mContent of Stack_B:\n");
	ft_print_stack_cnt(stack_b);
	ft_printf("\033[1;35m\n ~ ~~~~~~~~~~~~~~ ~\n\n");
}

void	ft_print_checker(char **stack_a, char **stack_b)
{
	int	sorted;
	int	null;

	null = ft_is_null(stack_b);
	sorted = ft_is_sorted(stack_a);
	ft_printf("\033[1;37m\n ~ Checker ~\n\n");
	ft_printf("\033[1;33mStack A is Sorted: ");
	if (sorted)
		ft_printf("\033[1;32mYES\n");
	else
		ft_printf("\033[1;31mNO\n");
	ft_printf("\033[1;33mStack B is NULL: ");
	if (null)
		ft_printf("\033[1;32mYES\n");
	else
		ft_printf("\033[1;31mNO\n");
	ft_printf("\033[1;37m\n ~  Grade:\t");
	if (sorted && null)
		ft_printf("\033[1;32m50%%\n");
	else if (sorted && !null)
		ft_printf("\033[1;33m45%%\n");
	else if (!sorted && null)
		ft_printf("\033[1;31m10%%\n");
	else
		ft_printf("\033[1;31m0%%!\n");
}
