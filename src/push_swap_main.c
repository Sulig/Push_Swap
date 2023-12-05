/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:40:32 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/05 13:45:49 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_arr_str_to_arr_chr(char **arr)
{
	char	*join;
	size_t	cnt;

	cnt = 2;
	join = NULL;
	join = ft_strjoin_s(arr[1], join);
	while (arr[cnt])
	{
		join = ft_strjoin_free_first(join, " ");
		join = ft_strjoin_free_first(join, arr[cnt]);
		cnt++;
	}
	return (join);
}

static char	*ft_check_dimax(char **args)
{
	char	**stack;
	char	*join;
	int		ok;

	ok = 1;
	join = ft_arr_str_to_arr_chr(args);
	if (!join)
		return (0);
	if (!ft_check_digit(join))
		ok = 0;
	stack = ft_split(join, ' ');
	if (stack)
	{
		if (!ft_check_max(stack))
			ok = 0;
		stack = ft_free_arr(ft_arr_strlen(stack), stack);
	}
	if (ok)
		return (join);
	else
	{
		free(join);
		join = NULL;
		return (NULL);
	}
}

int	main(int argc, char **args)
{
	t_stack	a;
	t_stack	b;
	char	*join;

	if (!ft_check_if_null_args(args, argc))
		return (0);
	join = ft_check_dimax(args);
	if (join)
	{
		if (ft_check_double(join))
		{
			if (ft_init(&a, &b, join))
			{
				ft_switch_lenght(&a, &b);
				ft_free_stacks(&a, &b);
			}
		}
		join = ft_free_str(join);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
