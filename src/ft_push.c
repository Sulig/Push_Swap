/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:12:00 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/09 20:27:54 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_push(char **stack, char *first)
{
	size_t	cnt;
	size_t	len;
	char	**new;

	cnt = 0;
	len = ft_arr_strlen(stack);
	if (!len)
		cnt += 1;
	cnt += len + 1;
	new = ft_calloc(sizeof(char *), cnt);
	if (!new)
		return (NULL);
	if (len)
	{
		while (--cnt > 0)
		{
			new[cnt] = stack[len];
			len--;
		}
	}
	new[0] = ft_strdup(first);
	stack = ft_auto_free_arr(stack);
	return (new);
}

char	**ft_rm_first(char **stack)
{
	size_t	cnt;
	size_t	len;
	char	**new;

	cnt = 0;
	len = ft_arr_strlen(stack);
	if (!len)
		len = 1;
	new = ft_calloc(sizeof(char *), len);
	if (!new)
		return (NULL);
	len = 1;
	while (stack[len])
	{
		new[cnt] = stack[len];
		len++;
		cnt++;
	}
	stack = ft_auto_free_arr(stack);
	return (new);
}

char	**ft_push_b(char ***stack_a, char **stack_b)
{
	if (ft_arr_strlen(*stack_a))
	{
		stack_b = ft_push(stack_b, *stack_a[0]);
		*stack_a = ft_rm_first(*stack_a);
		//ft_print_stat(stack_a, stack_b);
		ft_printf("pb\n");
	}
	return (stack_b);
}
