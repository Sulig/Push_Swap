/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:12:00 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/14 13:49:10 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_push(char **stack, char *first)
{
	size_t	cnt;
	size_t	ln;
	char	**new;

	ln = 1;
	cnt = 0;
	new = NULL;
	new = ft_calloc(sizeof(char *), ft_arr_strlen(stack) + 2);
	if (!new)
		return (NULL);
	new[0] = ft_strdup(first);
	if (stack)
	{
		while (stack[cnt])
		{
			new[ln] = ft_strdup(stack[cnt]);
			cnt++;
			ln++;
		}
	}
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

void	ft_push_a(char ***stack_a, char ***stack_b)
{
	char	**new_a;
	char	**new_b;

	if (ft_arr_strlen(*stack_b))
	{
		new_b = ft_rm_first(stack_b[0]);
		new_a = ft_push(*stack_a, stack_b[0][0]);
		stack_a[0] = ft_auto_free_arr(*stack_a);
		stack_a[0] = new_a;
		stack_b[0] = ft_auto_free_arr(*stack_b);
		stack_b[0] = new_b;
		ft_printf("pa\n");
	}
}

void	ft_push_b(char ***stack_a, char ***stack_b)
{
	char	**new_a;
	char	**new_b;

	if (ft_arr_strlen(*stack_a))
	{
		new_a = ft_rm_first(stack_a[0]);
		new_b = ft_push(*stack_b, stack_a[0][0]);
		stack_a[0] = ft_auto_free_arr(*stack_a);
		stack_a[0] = new_a;
		stack_b[0] = ft_auto_free_arr(*stack_b);
		stack_b[0] = new_b;
		ft_printf("pb\n");
	}
}
