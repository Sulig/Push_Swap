/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:00:36 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/14 19:53:46 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

int		ft_check_digit(char *str);
int		ft_check_max(char **arr);
int		ft_check_double(char **stack);
int		ft_is_sorted(char **stack);

size_t	ft_where_is_min(char **stack);
size_t	ft_where_is_max(char **stack);

char	**ft_push(char **stack_a, char *first);
void	ft_push_a(char ***stack_a, char ***stack_b);
void	ft_push_b(char ***stack_a, char ***stack_b);

void	ft_rotate_a(char **stack_a);
void	ft_rotate_b(char **stack_b);
void	ft_rotate_r(char **stack_a, char **stack_b);

void	ft_reverse_a(char **stack_a);
void	ft_reverse_b(char **stack_b);
void	ft_reverse_r(char **stack_a, char **stack_b);

void	ft_swap_a(char **stack_a);
void	ft_swap_b(char **stack_b);
void	ft_swap_s(char **stack_a, char **stack_b);

void	ft_switch_lenght(char ***stack_a, char ***stack_b);

void	ft_print_stack_cnt(char **stack);
void	ft_print_stat(char **stack_a, char **stack_b);

#endif
