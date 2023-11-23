/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:43:57 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/23 19:07:43 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_piece(t_piece *a, t_piece *b)
{
	size_t	in_a;
	size_t	in_b;
	int		val_a;
	int		val_b;

	in_a = 0;
	in_b = 0;
	val_a = 0;
	val_b = 0;
	if (a)
	{
		in_a = a->index;
		val_a = a->value;
	}
	if (b)
	{
		in_b = b->index;
		val_b = b->value;
	}
	if (a && b)
		ft_printf("\t [%u] %i\t\t [%u] %i\n", in_a, val_a, in_b, val_b);
	else if (a && !b)
		ft_printf("\t [%u] %i\t\t NULL\n", in_a, val_a);
	else if (!a && b)
		ft_printf("\t NULL\t\t [%u] %i\n", in_b, val_b);
}

void	ft_print_structs(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	max;

	i = 0;
	if (a->len > b->len)
		max = a->len;
	else
		max = b->len;
	ft_printf("\n\tStack A\t\tStack B\n\t-------\t\t-------\n");
	while (i < max)
	{
		if (i < a->len && i < b->len)
			ft_print_piece(&a->arr[i], &b->arr[i]);
		else if (i < a->len && i >= b->len)
			ft_print_piece(&a->arr[i], NULL);
		else if (i >= a->len && i < b->len)
			ft_print_piece(NULL, &b->arr[i]);
		else
			ft_printf("\t NULL\t\t NULL\n");
		i++;
	}
	ft_printf("\t--------\t-------\n");
}

void	ft_print_stat(t_stack *a, t_stack *b)
{
	ft_printf("\033[1;35m\n ~ Actual status ~\n\n");
	ft_printf("\033[1;33mStack A is Sorted: ");
	if (ft_is_sorted(a))
		ft_printf("\033[1;32mYES\n");
	else
		ft_printf("\033[1;31mNO\n");
	ft_printf("\n\033[1;37mActual len of Stack_A: %u\n", a->len);
	ft_printf("\033[1;37mActual len of Stack_B: %u\n", b->len);
	ft_print_structs(a, b);
	ft_printf("\033[1;35m\n ~ ~~~~~~~~~~~~~~ ~\n\n");
}

void	ft_print_checker(t_stack *a, t_stack *b)
{
	int	sorted;
	int	null;

	null = ft_is_null(b);
	sorted = ft_is_sorted(a);
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
