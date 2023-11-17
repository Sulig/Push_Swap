/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:41:43 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/17 13:59:25 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../Libft/libft.h"

int		ft_check_if_null_args(char **args, int argc);
int		ft_check_digit(char *str);
int		ft_check_max(char **arr);
int		ft_check_double(char **stack);

int		ft_is_null(char **stack);
int		ft_is_sorted(char **stack);

void	ft_do_while(char ***stack_a, char ***stack_b);
void	ft_checker(char **stack_a, char **stack_b);

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

#endif
