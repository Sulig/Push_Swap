/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:28:11 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/09 20:14:57 by sadoming         ###   ########.fr       */
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
	ln_a = -1;
	ln_b = -1;
	if (stack_a)
		while (stack_a[ln_a++])
			ft_printf("[%u]: %s\t", ln_a, stack_a[ln_a]);
	ft_printf("\n\n\033[1;37mContent of Stack_B:\n");
	if (stack_b)
		while (stack_b[ln_b++])
			ft_printf("[%u]: %s\t", ln_b, stack_b[ln_b]);
	ft_printf("\033[1;35m\n ~ ~~~~~~~~~~~~~~ ~\n\n");
}
