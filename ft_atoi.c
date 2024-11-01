/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:58:39 by jvarila           #+#    #+#             */
/*   Updated: 2024/10/31 11:04:01 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	num;
	int	negative;

	num = 0;
	negative = 1;
	if (*(nptr) == '-')
	{
		negative = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		num = num * 10 + *(nptr++) - '0';
	return (negative * num);
}
