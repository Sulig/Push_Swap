/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:52:29 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/15 17:30:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(char **stack_a)
{
	size_t	act;
	size_t	next;
	char	*first;

	first = NULL;
	act = 0;
	if (stack_a[0])
		first = stack_a[0];
	while (stack_a[act])
	{
		if (stack_a[act + 1])
			next = act + 1;
		else
			break ;
		stack_a[act] = stack_a[next];
		act++;
	}
	stack_a[act] = first;
	ft_printf("ra\n");
}

void	ft_rotate_b(char **stack_b)
{
	size_t	act;
	size_t	next;
	char	*first;

	first = NULL;
	act = 0;
	if (stack_b[0])
		first = stack_b[0];
	while (stack_b[act])
	{
		if (stack_b[act + 1])
			next = act + 1;
		else
			break ;
		stack_b[act] = stack_b[next];
		act++;
	}
	stack_b[act] = first;
	ft_printf("rb\n");
}

void	ft_rotate(char **stack)
{
	size_t	act;
	size_t	next;
	char	*first;

	first = NULL;
	act = 0;
	if (stack[0])
		first = stack[0];
	while (stack[act])
	{
		if (stack[act + 1])
			next = act + 1;
		else
			break ;
		stack[act] = stack[next];
		act++;
	}
	stack[act] = first;
}

void	ft_rotate_r(char **stack_a, char **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
