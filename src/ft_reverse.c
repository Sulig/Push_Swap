/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:04:06 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/14 14:32:13 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_a(char **stack_a)
{
	size_t	act;
	size_t	bef;
	char	*last;

	last = NULL;
	act = ft_arr_strlen(stack_a) - 1;
	if (stack_a[act])
		last = stack_a[act];
	ft_printf("Last [%u]: %s\n", act, last);
	while (stack_a[act])
	{
		if (stack_a[act - 1])
			bef = act - 1;
		else
			break ;
		stack_a[act] = stack_a[bef];
		act--;
	}
	stack_a[0] = last;
	ft_printf("Last: %s\n Stack: %s\n", last, stack_a[0]);
	ft_printf("rra\n");
}
