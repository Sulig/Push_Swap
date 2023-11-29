/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:58:33 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/29 20:48:37 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_decide_num_of_chunks(size_t len)
{
	if (len < 15)
		return (2);
	else if (len < 40)
		return (4);
	else if (len <= 100)
		return (5);
	else if (len <= 500)
		return (11);
	else if (len > 500)
		return (12);
	return (5);
}

static void	ft_set_g_chunks(t_chunk *chunk, int max, int min)
{
	size_t	sta_to_end;
	size_t	end_to_sta;
	size_t	sep_of;

	sta_to_end = 0;
	chunk->act_chunk = 0;
	chunk->num_of_args = max;
	end_to_sta = chunk->chunks - 1;
	sep_of = max / chunk->chunks;
	while (sta_to_end < chunk->chunks)
	{
		chunk->g_chunks[end_to_sta].max = max;
		chunk->g_chunks[sta_to_end].min = min;
		min += sep_of;
		max -= sep_of;
		sta_to_end++;
		end_to_sta--;
	}
}

static void	ft_pb_with_chunks(t_stack *a, t_stack *b, t_chunk *chunk)
{
	size_t	i;
	size_t	j;
	t_piece	to_push;

	while (a->len)
	{
		i = 0;
		j = a->len - 1;
		while (a->arr[i].g_chunk != chunk->act_chunk && i < a->len)
			i++;
		while (j && a->arr[j].g_chunk != chunk->act_chunk)
			j--;
		to_push = ft_decide_to_push(a, i, j);
		if (to_push.ok)
		{
			ft_in_first(a, to_push, 'a');
			ft_pb(a, b);
		}
		else
			chunk->act_chunk++;
	}
}

static void	ft_pa_and_sort(t_stack *a, t_stack *b)
{
	t_piece	to_push;
	t_piece	bef;

	while (b->len)
	{
		to_push = b->arr[ft_where_is(b, 0, '>')];
		bef = ft_need_swap(b);
		if (bef.index < to_push.index && bef.ok)
		{
			ft_in_first(b, bef, 'b');
			ft_pa(a, b);
			ft_in_first(b, to_push, 'b');
			ft_pa(a, b);
			ft_sa(a);
		}
		else
		{
			ft_in_first(b, to_push, 'b');
			ft_pa(a, b);
		}
	}
}

void	ft_big_sort(t_stack *a, t_stack *b)
{
	t_chunk	chunk;
	t_piece	first;
	int		max;

	max = a->arr[ft_where_is(a, 0, '>')].index;
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
	ft_set_g_chunks(&chunk, max, 0);
	ft_set_group_of_chunk(a, &chunk);
	ft_pb_with_chunks(a, b, &chunk);
	ft_pa_and_sort(a, b);
	free(chunk.g_chunks);
}
