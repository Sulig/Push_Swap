/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:59:55 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/07 20:32:52 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_arr_str_to_arr_chr(char **arr)
{
	char	*join;
	size_t	cnt;

	cnt = 2;
	join = NULL;
	join = ft_strjoin(arr[1], join);
	while (arr[cnt])
	{
		join = ft_strjoin_free_first(join, arr[cnt]);
		cnt++;
	}
	return (join);
}

int	main(int argc, char **args)
{
	char	*join;

	if (argc > 1)
	{
		join = ft_arr_str_to_arr_chr(args);
		if (join)
		{
			ft_printf("%s\n", join);
			free(join);
		}
	}
	join = NULL;
	return (0);
}
