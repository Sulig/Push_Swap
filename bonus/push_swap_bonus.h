/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:41:43 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/20 18:47:19 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../Libft/include/libft.h"

typedef struct s_piece
{
	int			value;
	size_t		index;
}				t_piece;

typedef struct s_stack
{
	size_t		len;
	t_piece		*arr;
}				t_stack;

int		ft_check_if_null_args(char **args, int argc);
int		ft_check_digit(char *str);
int		ft_check_max(char **arr);
int		ft_check_double(char *joined);

int		ft_is_null(t_stack *s);
int		ft_is_sorted(t_stack *stack);

void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);

void	ft_rotate(t_stack *s);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);

void	ft_reverse(t_stack *s);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

void	ft_swap(t_stack *s);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);

void	ft_checker(t_stack *a, t_stack *b);
int		ft_switch_move(t_stack *a, t_stack *b, char *move);
void	ft_do_while(t_stack *a, t_stack *b);

void	ft_free_stacks(t_stack *a, t_stack *b);
int		ft_init(t_stack *a, t_stack *b, char *join);

#endif
