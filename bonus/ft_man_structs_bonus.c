/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_structs_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:22:30 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/27 16:23:56 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_set_index_piece(t_stack *a)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	while (i < a->len)
	{
		j = 0;
		index = 0;
		while (j < a->len)
		{
			if (a->arr[i].value > a->arr[j].value)
				index++;
			j++;
		}
		a->arr[i].index = index;
		i++;
	}
}

int	ft_init(t_stack *a, t_stack *b, char *join)
{
	char	**arr;
	size_t	cnt;

	cnt = 0;
	arr = ft_split(join, ' ');
	if (!arr)
		return (0);
	a->len = ft_arr_strlen(arr);
	b->len = 0;
	b->arr = NULL;
	a->arr = ft_calloc(sizeof(t_piece), ft_arr_strlen(arr) + 1);
	if (!a->arr)
		return (0);
	while (arr[cnt])
	{
		a->arr[cnt].value = ft_atoi(arr[cnt]);
		cnt++;
	}
	arr = ft_auto_free_arr(arr);
	ft_set_index_piece(a);
	return (1);
}

void	ft_free_stacks(t_stack *a, t_stack *b)
{
	if (a)
	{
		while (a->len--)
		{
			a->arr[a->len].value = 0;
			a->arr[a->len].index = 0;
		}
		free(a->arr);
		a = NULL;
	}
	if (b)
	{
		while (b->len--)
		{
			b->arr[b->len].value = 0;
			b->arr[b->len].value = 0;
		}
		free(b->arr);
		b = NULL;
	}
}
