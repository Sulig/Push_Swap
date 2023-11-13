/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:00:36 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/13 14:33:37 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

int		ft_check_digit(char *str);
int		ft_check_max(char **arr);
int		ft_check_double(char **stack);
int		ft_is_sorted(char **stack);

char	**ft_push(char **stack_a, char *first);
void	ft_push_b(char ***stack_a, char ***stack_b);

void	ft_swap_a(char **stack_a);
void	ft_swap_b(char **stack_b);
void	ft_swap_s(char **stack_a, char **stack_b);

void	ft_print_stack_cnt(char **stack);
void	ft_print_stat(char **stack_a, char **stack_b);

#endif