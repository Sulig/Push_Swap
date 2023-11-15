/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:53:34 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/15 18:17:55 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_can_sort(char **stack, char ins)
{
	if (ins == 's')
		ft_swap(stack);
	if (ins == 'r')
		ft_rotate(stack);
	if (ins == 'i')
		ft_reverse(stack);
	if (ft_is_sorted(stack))
		return (1);
	else
		return (0);
}

static char	ft_what_ins(char **stack)
{
	char	**copy;
	char	ret;

	ret = '\0';
	copy = ft_strarrdup(stack);
	if (!copy)
		return ('\0');
	if (ft_can_sort(copy, 's'))
		ret = 's';
	else if (ft_can_sort(copy, 'r'))
		ret = 'r';
	else if (ft_can_sort(copy, 'i'))
		ret = 'i';
	copy = ft_auto_free_arr(copy);
	return (ret);
}

int	ft_can_sort_in_one(char **stack)
{
	if (!ft_what_ins(stack))
		return (0);
	else if (ft_what_ins(stack) == 's')
		ft_swap_a(stack);
	else if (ft_what_ins(stack) == 'r')
		ft_rotate_a(stack);
	else if (ft_what_ins(stack) == 'i')
		ft_reverse_a(stack);
	else
		return (0);
	return (1);
}
