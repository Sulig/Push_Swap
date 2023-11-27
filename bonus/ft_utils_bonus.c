/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:58:26 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/27 18:26:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_null(t_stack *s)
{
	if (!s)
		return (1);
	if (!s->arr)
		return (1);
	if (!s->len)
		return (1);
	return (0);
}

int	ft_is_sorted(t_stack *stack)
{
	size_t	ln;
	size_t	nx;
	int		ok;

	ok = 1;
	ln = 0;
	if (!stack)
		return (0);
	while (ln < stack->len)
	{
		nx = ln + 1;
		while (nx < stack->len)
		{
			if (stack->arr[ln].value > stack->arr[nx].value)
				ok = 0;
			nx++;
		}
		ln++;
	}
	return (ok);
}

void	ft_checker(t_stack *a, t_stack *b)
{
	int	sorted;
	int	null;

	null = ft_is_null(b);
	sorted = ft_is_sorted(a);
	if (sorted && null)
		ft_printf("\033[1;32mOK\n");
	else
		ft_printf("\033[1;31mKO\n");
}

int	ft_switch_move(t_stack *a, t_stack *b, char *move)
{
	if (my_strcmp(move, "sa\n"))
		ft_sa(a);
	else if (my_strcmp(move, "sb\n"))
		ft_sb(b);
	else if (my_strcmp(move, "ss\n"))
		ft_ss(a, b);
	else if (my_strcmp(move, "pa\n"))
		ft_pa(a, b);
	else if (my_strcmp(move, "pb\n"))
		ft_pb(a, b);
	else if (my_strcmp(move, "ra\n"))
		ft_ra(a);
	else if (my_strcmp(move, "rb\n"))
		ft_rb(b);
	else if (my_strcmp(move, "rr\n"))
		ft_rr(a, b);
	else if (my_strcmp(move, "rra\n"))
		ft_rra(a);
	else if (my_strcmp(move, "rrb\n"))
		ft_rrb(b);
	else if (my_strcmp(move, "rrr\n"))
		ft_rrr(a, b);
	else
		return (0);
	return (1);
}

void	ft_do_while(t_stack *a, t_stack *b)
{
	char	*move;

	move = get_next_line(1);
	while (move)
	{
		if (!ft_switch_move(a, b, move))
		{
			write(2, "Error\n", 6);
			free(move);
			return ;
		}
		free(move);
		move = get_next_line(1);
	}
	ft_checker(a, b);
}
