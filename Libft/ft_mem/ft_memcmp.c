/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:19:23 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/12 16:37:27 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*com;
	size_t			cnt;
	int				ascii;

	str = (unsigned char *) s1;
	com = (unsigned char *) s2;
	ascii = 0;
	cnt = 0;
	if (n > 0)
	{
		n--;
		while (cnt < n && (str[cnt] == com[cnt]))
			cnt++;
		ascii = str[cnt] - com[cnt];
	}
	if (str[cnt] < 0 || com[cnt] < 0)
		return (ascii * -1);
	else
		return (ascii);
}
