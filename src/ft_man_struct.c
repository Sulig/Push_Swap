/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:52:03 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/29 14:31:16 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_set_group_of_chunk(t_stack *a, t_chunk *chunk)
{
	size_t	i;
	size_t	act;
	size_t	min;
	size_t	max;

	i = 0;
	while (i < a->len)
	{
		act = 0;
		while (act < chunk->chunks)
		{
			min = chunk->g_chunks[act].min;
			max = chunk->g_chunks[act].max;
			if (a->arr[i].index >= min && a->arr[i].index <= max)
				a->arr[i].g_chunk = act;
			act++;
		}
		i++;
	}
}

int	ft_dup_stack(t_stack *s, t_stack *to_dup)
{
	t_piece	*arr_to_dup;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	arr_to_dup = ft_calloc(sizeof(t_piece), s->len + 1);
	if (!arr_to_dup)
		return (0);
	while (i < s->len)
	{
		arr_to_dup[i].value = s->arr[i].value;
		arr_to_dup[i].index = s->arr[i].index;
		i++;
	}
	to_dup->len = s->len;
	to_dup->arr = arr_to_dup;
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
