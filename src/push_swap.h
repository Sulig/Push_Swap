/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:00:36 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/22 20:52:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

struct typedef s_cost_moves
{
	size_t		ra;
	size_t		rb;
	size_t		rr;
	size_t		rra;
	size_t		rrb;
	size_t		rrr;
	size_t		total;
}				t_cst_ms;



typedef struct s_piece
{
	int value;
	int index;
} t_piece;

typedef struct s_tack
{
	int len;
	t_piece  *arr;
}

int		ft_check_if_null_args(char **args, int argc);
int		ft_check_digit(char *str);
int		ft_check_max(char **arr);
int		ft_check_double(char **stack);

int		ft_is_null(char **stack);
int		ft_is_sorted(char **stack);
int		ft_diference_of_num(char *num, char *other);
int		ft_is_smaller_than(char *num, char *other);
int		ft_can_sort_in_one(char **stack);
size_t	ft_where_is_min(char **stack);
size_t	ft_where_is_max(char **stack);

void	ft_push_a(char ***stack_a, char ***stack_b);
void	ft_push_b(char ***stack_a, char ***stack_b);

void	ft_rotate(char **stack);
void	ft_rotate_a(char **stack_a);
void	ft_rotate_b(char **stack_b);
void	ft_rotate_r(char **stack_a, char **stack_b);

void	ft_reverse(char **stack);
void	ft_reverse_a(char **stack_a);
void	ft_reverse_b(char **stack_b);
void	ft_reverse_r(char **stack_a, char **stack_b);

void	ft_swap(char **stack);
void	ft_swap_a(char **stack_a);
void	ft_swap_b(char **stack_b);
void	ft_swap_s(char **stack_a, char **stack_b);

void	ft_sort_tree(char **stack_a);
void	ft_sort_four(char ***stack_a, char ***stack_b);
void	ft_sort_five(char ***stack_a, char ***stack_b);
void	ft_big_sort(char ***stack_a, char ***stack_b);
void	ft_min_in_first(char **stack);
void	ft_switch_lenght(char ***stack_a, char ***stack_b);

void	ft_print_stack_cnt(char **stack);
void	ft_print_stat(char **stack_a, char **stack_b);
void	ft_print_checker(char **stack_a, char **stack_b);

#endif
