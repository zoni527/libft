/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:58:39 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/12 11:52:31 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_to_significant_digits(const char **pointer_to_numeric_string);

int	ft_atoi(const char *nptr)
{
	int				num;
	unsigned long	ul_num;
	int				sign;
	size_t			significant_digits;

	if (!*nptr)
		return (0);
	num = 0;
	ul_num = 0;
	significant_digits = 0;
	sign = skip_to_significant_digits(&nptr);
	while (*nptr >= '0' && *nptr <= '9')
	{
		significant_digits++;
		ul_num = ul_num * 10 + *(nptr) - '0';
		num = num * 10 + *(nptr++) - '0';
	}
	if ((ul_num > LONG_MAX && sign > 0)
		|| (significant_digits > 19 && sign > 0))
		return ((int)LONG_MAX);
	if ((ul_num > (unsigned long)LONG_MIN && sign < 0)
		|| (significant_digits > 19 && sign < 0))
		return ((int)LONG_MIN);
	return (sign * num);
}

static int	skip_to_significant_digits(const char **pointer_to_numeric_string)
{
	const char	**nptr;
	int			sign;

	nptr = pointer_to_numeric_string;
	sign = 1;
	while (**nptr == 32 || (**nptr >= 9 && **nptr <= 13))
		(*nptr)++;
	if (**nptr == '-' || **nptr == '+')
		if (*((*nptr)++) == '-')
			sign = -1;
	while (**nptr == 0)
		(*nptr)++;
	return (sign);
}
