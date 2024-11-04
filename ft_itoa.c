/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:48:20 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/04 10:16:20 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		str_len;
	int		n_temp;

	str_len = ft_int_len(n);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	str[str_len] = '\0';
	n_temp = n;
	if (n < 0)
		n_temp *= -1;
	while (--str_len)
	{
		str[str_len] = n_temp % 10 + '0';
		n_temp /= 10;
	}
	if (n < 0)
		str[0] = '-';
	else
		str[0] = n_temp % 10 + '0';
	return (str);
}

static int	ft_int_len(int n)
{
	int	int_len;

	int_len = 0;
	if (n < 0)
		int_len++;
	while (n != 0)
	{
		int_len++;
		n /= 10;
	}
	return (int_len);
}
