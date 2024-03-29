/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:16:49 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/12 20:17:54 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
 * Trim the *set off of s1
 * Returns a new str with the result
*/
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	ln;
	size_t	cnt;

	if (s1[0] == '\0')
		return (ft_substr("", 0, 0));
	if (set[0] == '\0')
		return (ft_substr(s1, 0, ft_strlen(s1)));
	ln = 0;
	while (s1[ln])
	{
		if (!ft_strchr(set, s1[ln]))
			break ;
		ln++;
	}
	cnt = 0;
	while (s1[cnt + 1])
		cnt++;
	while (cnt >= 0)
	{
		if (!ft_strchr(set, s1[cnt]))
			break ;
		cnt--;
	}
	return (ft_substr(s1, ln, (cnt + 1) - ln));
}
