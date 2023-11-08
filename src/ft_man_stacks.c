/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:24:39 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/08 20:31:55 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_free_stack(int *stack)
{
	free(stack);
	return (NULL);
}

int	*ft_create_stack(char **arr)
{
	int		*stack;
	size_t	cnt;

	cnt = 0;
	stack = ft_calloc(sizeof(int), ft_arr_strlen(arr) + 1);
	if (!stack)
		return (NULL);
	while (arr[cnt])
	{
		stack[cnt] = ft_atoi(arr[cnt]);
		cnt++;
	}
	return (stack);
}
