/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:18:09 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/14 20:21:43 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if (c < '0')
		return (0);
	else if (c > 'z')
		return (0);
	else if (c > '9' && c < 'A')
		return (0);
	else if (c > 'Z' && c < 'a')
		return (0);
	else
		return (1);
}

int	ft_isalpha(int c)
{
	if (c < 'A')
		return (0);
	else if (c > 'z')
		return (0);
	else if (c > 'Z' && c < 'a')
		return (0);
	else
		return (1);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}
