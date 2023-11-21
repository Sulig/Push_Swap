/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:12:00 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/17 18:05:59 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_push(char **stack, char *first)
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

static char	**ft_pop(char **stack)
{
	char	**new;
	size_t	cnt;
	size_t	ln;

	ln = 0;
	cnt = 1;
	new = NULL;
	new = ft_calloc(sizeof(char *), ft_arr_strlen(stack));
	if (!new)
		return (NULL);
	while (stack[cnt])
	{
		new[ln] = ft_strdup(stack[cnt]);
		cnt++;
		ln++;
	}
	return (new);
}

void	ft_push_a(char ***stack_a, char ***stack_b)
{
	char	**new_a;
	char	**new_b;

	if (ft_arr_strlen(*stack_b))
	{
		new_b = ft_pop(stack_b[0]);
		new_a = ft_push(*stack_a, stack_b[0][0]);
		*stack_a = ft_auto_free_arr(*stack_a);
		stack_a[0] = new_a;
		*stack_b = ft_auto_free_arr(*stack_b);
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
		new_a = ft_pop(stack_a[0]);
		new_b = ft_push(*stack_b, stack_a[0][0]);
		stack_a[0] = ft_auto_free_arr(*stack_a);
		stack_a[0] = new_a;
		stack_b[0] = ft_auto_free_arr(*stack_b);
		stack_b[0] = new_b;
		ft_printf("pb\n");
	}
}
