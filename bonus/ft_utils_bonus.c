/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:58:26 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/17 13:49:55 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_null(char **stack)
{
	if (!stack)
		return (1);
	if (!stack[0])
		return (1);
	return (0);
}

int	ft_is_sorted(char **stack)
{
	size_t	ln;
	size_t	next;
	int		st;
	int		nx;
	int		ok;

	ok = 1;
	ln = 0;
	if (!stack)
		return (0);
	while (stack[ln])
	{
		st = ft_atoi(stack[ln]);
		next = ln + 1;
		while (stack[next])
		{
			nx = ft_atoi(stack[next]);
			if (st > nx)
				ok = 0;
			next++;
		}
		ln++;
	}
	return (ok);
}

void	ft_checker(char **stack_a, char **stack_b)
{
	int	sorted;
	int	null;

	null = ft_is_null(stack_b);
	sorted = ft_is_sorted(stack_a);
	if (sorted && null)
		ft_printf("\033[1;32mOK\n");
	else
		ft_printf("\033[1;31mKO\n");
}

int	ft_switch_move(char ***stack_a, char ***stack_b, char *move)
{
	if (my_strcmp(move, "sa\n"))
		ft_swap_a(*stack_a);
	else if (my_strcmp(move, "sb\n"))
		ft_swap_b(*stack_b);
	else if (my_strcmp(move, "ss\n"))
		ft_swap_s(*stack_a, *stack_b);
	else if (my_strcmp(move, "pa\n"))
		ft_push_a(stack_a, stack_b);
	else if (my_strcmp(move, "pb\n"))
		ft_push_b(stack_a, stack_b);
	else if (my_strcmp(move, "ra\n"))
		ft_rotate_a(*stack_a);
	else if (my_strcmp(move, "rb\n"))
		ft_rotate_b(*stack_b);
	else if (my_strcmp(move, "rr\n"))
		ft_rotate_r(*stack_a, *stack_b);
	else if (my_strcmp(move, "rra\n"))
		ft_reverse_a(*stack_a);
	else if (my_strcmp(move, "rrb\n"))
		ft_reverse_b(*stack_b);
	else if (my_strcmp(move, "rrr\n"))
		ft_reverse_r(*stack_a, *stack_b);
	else
		return (0);
	return (1);
}

void	ft_do_while(char ***stack_a, char ***stack_b)
{
	char	*move;

	move = get_next_line(1);
	while (move)
	{
		if (!ft_switch_move(stack_a, stack_b, move))
		{
			ft_printf("Error\n");
			free(move);
			*stack_a = ft_auto_free_arr(*stack_a);
			*stack_b = ft_auto_free_arr(*stack_b);
			return ;
		}
		free(move);
		move = get_next_line(1);
	}
	ft_checker(*stack_a, *stack_b);
	*stack_a = ft_auto_free_arr(*stack_a);
	if (*stack_b)
		if (*stack_b[0])
			*stack_b = ft_auto_free_arr(*stack_b);
}
