/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:59:55 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/16 13:16:55 by sadoming         ###   ########.fr       */
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
	char	**stack_a;
	char	**stack_b;
	char	*join;

	if (argc == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	join = ft_check_dimax(args);
	if (join)
	{
		stack_a = ft_split(join, ' ');
		stack_b = NULL;
		if (stack_a)
		{
			if (ft_check_double(stack_a))
				ft_switch_lenght(&stack_a, &stack_b);
			stack_a = ft_auto_free_arr(stack_a);
			if (stack_b)
				free(stack_b);
		}
		join = ft_free_str(join);
	}
	return (0);
}
