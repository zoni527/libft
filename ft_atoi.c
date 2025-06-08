/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:58:39 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/08 12:54:14 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;

	if (!*nptr)
		return (0);
	num = 0;
	sign = 1;
	nptr = ft_skip_whitespace(nptr);
	if (*nptr == '-' || *nptr == '+')
		if (*(nptr++) == '-')
			sign = -1;
	while (ft_isdigit(*nptr))
	{
		if (sign > 0 && num > (LONG_MAX - (*nptr - '0')) / 10)
			return ((int)LONG_MAX);
		if (sign < 0 && num > -(((*nptr - '0') + LONG_MIN) / 10))
			return ((int)LONG_MIN);
		num = num * 10 + *(nptr++) - '0';
	}
	return (sign * (int)num);
}
