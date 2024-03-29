/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:37:46 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/13 14:01:16 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/include/libft.h"

typedef struct s_piece
{
	int			ok;
	int			value;
	int			last_five;
	size_t		index;
	size_t		g_chunk;
}				t_piece;

typedef struct s_stack
{
	size_t		len;
	t_piece		*arr;
}				t_stack;

typedef struct s_g_chunk
{
	int			min;
	int			max;
}				t_g_chunk;

typedef struct s_chunk
{
	size_t		act;
	size_t		chunks;
	size_t		num_of_args;
	t_g_chunk	*g_chunks;
}				t_chunk;

int		ft_check_if_null_args(char **args, int argc);
int		ft_check_digit(char *str);
int		ft_check_max(char **arr);
int		ft_check_double(char *joined);

int		ft_is_null(t_stack *s);
int		ft_is_sorted(t_stack *stack);
int		ft_is_sorted_inverse(t_stack *stack);
size_t	ft_where_is(t_stack *stack, size_t index, char c);
int		ft_can_sort_in_one(t_stack *s);

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

void	ft_sort_three(t_stack *a);
void	ft_sort_four(t_stack *a, t_stack *b);
void	ft_in_first(t_stack *s, t_piece first, char move);
void	ft_sort_five(t_stack *a, t_stack *b);
void	ft_big_sort(t_stack *a, t_stack *b);
void	ft_switch_lenght(t_stack *a, t_stack *b);

t_piece	ft_decide_to_push(t_stack *s, size_t num_1, size_t num_2);
t_piece	ft_need_swap_aft_pa(t_stack *s);

void	ft_free_stacks(t_stack *a, t_stack *b);
int		ft_init(t_stack *a, t_stack *b, char *join);
void	ft_set_last_five(t_stack *s, t_chunk *chunk);
void	ft_set_group_of_chunk(t_stack *a, t_chunk *chunk);
int		ft_dup_stack(t_stack *s, t_stack *to_dup);

void	ft_print_piece(t_piece *a, t_piece *b);
void	ft_print_structs(t_stack *a, t_stack *b);
void	ft_print_stat(t_stack *a, t_stack *b);
void	ft_print_chunk(t_chunk *chunk, t_stack *s);
void	ft_print_checker(t_stack *a, t_stack *b);

#endif
