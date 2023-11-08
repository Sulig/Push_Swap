/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:59:55 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/08 20:34:30 by sadoming         ###   ########.fr       */
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

static char	**ft_do_arr(char **args)
{
	char	**arr;
	char	*join;

	arr = NULL;
	join = ft_arr_str_to_arr_chr(args);
	if (!join)
		return (NULL);
	if (ft_check_digit(join))
	{
		arr = ft_split(join, ' ');
		if (arr)
			if (!ft_check_max(arr))
				arr = ft_free_arr(ft_arr_strlen(arr), arr);
	}
	else
		ft_printf("Error\n");
	free(join);
	join = NULL;
	return (arr);
}

int	main(int argc, char **args)
{
	char	**arr;
	int		*stack_a;
	int		*stack_b;

	if (argc > 1)
	{
		arr = ft_do_arr(args);
		if (arr)
		{
			stack_a = ft_create_stack(arr);
			if (stack_a)
			{
				stack_b = ft_calloc(sizeof(int), ft_arr_strlen(arr) + 1);
				if (stack_b)
				{
					ft_printf("For now is ok\n");
					ft_printf("Call check_double && do prog\n");
					stack_a = ft_free_stack(stack_a);
					stack_b = ft_free_stack(stack_b);
				}
			}
			arr = ft_free_arr(ft_arr_strlen(arr), arr);
		}
	}
	return (0);
}
