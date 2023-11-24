/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:58:33 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/24 14:43:10 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_decide_num_of_chunks(size_t len)
{
	size_t	num_of_chunks;

	if (len > 20)
		num_of_chunks = 4;
	else
		num_of_chunks = 2;
	while (len % num_of_chunks)
		num_of_chunks++;
	return (num_of_chunks);
}

void	ft_set_g_chunks(t_chunk *chunk, size_t len)
{
	size_t	act;
	size_t	sep_of;

	act = chunk->chunks;
	chunk->act_chunk = 0;
	sep_of = len / chunk->chunks;
	while (act--)
	{
		chunk->g_chunks[act].max = len;
		chunk->g_chunks[act].g_len = sep_of;
		len -= sep_of;
		chunk->g_chunks[act].min = len;
	}
}

void	ft_pb_with_chunks(t_stack *a, t_stack *b, t_chunk *chunk)
{
	size_t	i;
	int		pushed;
	t_piece	to_push;

	i = 0;
	while (a->len && !ft_is_sorted(a))
	{
		pushed = 0;
		if (a->arr[i].g_chunk == chunk->act_chunk)
		{
			to_push = a->arr[i];
			ft_in_first(a, to_push, 'a');
			ft_pb(a, b);
			chunk->g_chunks[chunk->act_chunk].g_len--;
			pushed = 1;
		}
		if (!chunk->g_chunks[chunk->act_chunk].g_len)
			chunk->act_chunk++;
		if (!pushed)
			i++;
	}
}

void	ft_pa_and_sort(t_stack *a, t_stack *b)
{
	size_t	i;
	t_piece	to_push;
	t_piece	max;

	while (b->len)
	{
		i = 0;
		max = a->arr[ft_where_is(a, 0, '>')];
		while (i < b->len)
		{
			if (b->arr[i].index > max.index)
			{
				if ((b->arr[i].index - max.index) == 1)
				{
					to_push = b->arr[i];
					break ;
				}
			}
			i++;
		}
		if (i == b->len)
			to_push = b->arr[ft_where_is(b, 0, '>')];
		ft_in_first(b, to_push, 'b');
		ft_pa(a, b);
		if (to_push.value > max.value)
			ft_ra(a);
	}
}

void	ft_big_sort(t_stack *a, t_stack *b)
{
	t_chunk	chunk;
	t_piece	first;

	if (ft_is_prime(a->len))
	{
		first = a->arr[ft_where_is(a, 0, '<')];
		ft_in_first(a, first, 'a');
		ft_pb(a, b);
	}
	chunk.chunks = ft_decide_num_of_chunks(a->len);
	chunk.g_chunks = ft_calloc(sizeof(t_g_chunk), chunk.chunks);
	if (!chunk.g_chunks)
		return ;
	ft_set_g_chunks(&chunk, a->len);
	ft_set_group_of_chunk(a, &chunk);
	ft_pb_with_chunks(a, b, &chunk);
	ft_pa_and_sort(a, b);
}
