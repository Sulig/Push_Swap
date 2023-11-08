/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:59:55 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/08 14:31:02 by sadoming         ###   ########.fr       */
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

int	main(int argc, char **args)
{
	char	**arr;
	char	*join;
	int		ok;

	ok = 0;
	if (argc > 1)
	{
		join = ft_arr_str_to_arr_chr(args);
		if (join)
		{
			if (ft_check_digit(join))
				ok = 1;
			if (ok)
			{
				arr = ft_split(join, ' ');
				if (arr)
				{
					ft_printf("%s\n", join);
					arr = ft_free_arr(ft_arr_strlen(arr), arr);
				}
			}
			else
				ft_printf("Error\n");
			free(join);
		}
	}
	return (0);
}
