/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:11 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/09 19:47:20 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_auto_free_arr(char **arr)
{
	size_t	size;

	size = ft_arr_strlen(arr);
	if (size)
	{
		while (size--)
			free(arr[size]);
		free(arr);
	}
	arr = NULL;
	return (NULL);
}

void	*ft_free_str(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}
