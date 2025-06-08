/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:58:39 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/08 12:54:23 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	num;
	long	sign;

	if (!*nptr)
		return (0);
	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*(nptr++) == '-')
			sign = -1;
	while (ft_isdigit(*nptr))
	{
		if (sign > 0 && num > (LONG_MAX - (*nptr - '0')) / 10)
			return (LONG_MAX);
		if (sign < 0 && num > -(((*nptr - '0') + LONG_MIN) / 10))
			return (LONG_MIN);
		num = num * 10 + *(nptr++) - '0';
	}
	return (sign * num);
}
