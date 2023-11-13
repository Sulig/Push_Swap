/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:12:00 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/13 20:45:45 by sadoming         ###   ########.fr       */
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
	char	**tmp;
	size_t	cnt;
	size_t	ln;

	ln = 0;
	cnt = 1;
	tmp = NULL;
	tmp = ft_calloc(sizeof(char *), ft_arr_strlen(stack));
	if (!tmp)
		return (NULL);
	while (stack[cnt])
	{
		tmp[ln] = ft_strdup(stack[cnt]);
		cnt++;
		ln++;
	}
	return (tmp);
}

void	ft_push_b(char ***stack_a, char ***stack_b)
{
	char	**new;

	if (ft_arr_strlen(*stack_a))
	{
		*stack_b = ft_push(*stack_b, stack_a[0][0]);
		new = ft_rm_first(stack_a[0]);
		stack_a[0] = ft_auto_free_arr(*stack_a);
		stack_a[0] = new;
		ft_printf("pb\n");
	}
}
