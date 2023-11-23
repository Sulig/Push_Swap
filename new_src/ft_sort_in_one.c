/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:53:34 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/23 18:56:19 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_can_sort(t_stack *s, char ins)
{
	t_stack	copy;
	int		ok;

	ok = 0;
	ft_dup_stack(s, &copy);
	if (!copy.arr)
		return (0);
	if (ins == 's')
		ft_swap(&copy);
	if (ins == 'r')
		ft_rotate(&copy);
	if (ins == 'i')
		ft_reverse(&copy);
	if (ft_is_sorted(&copy))
		ok = 1;
	ft_free_stacks(&copy, NULL);
	return (ok);
}

static char	ft_what_ins(t_stack *s)
{
	char	ret;

	ret = '\0';
	if (ft_can_sort(s, 's'))
		ret = 's';
	else if (ft_can_sort(s, 'r'))
		ret = 'r';
	else if (ft_can_sort(s, 'i'))
		ret = 'i';
	return (ret);
}

int	ft_can_sort_in_one(t_stack *s)
{
	if (!ft_what_ins(s))
		return (0);
	else if (ft_what_ins(s) == 's')
		ft_sa(s);
	else if (ft_what_ins(s) == 'r')
		ft_ra(s);
	else if (ft_what_ins(s) == 'i')
		ft_rra(s);
	else
		return (0);
	return (1);
}
