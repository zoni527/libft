/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:10:37 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/28 15:30:15 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uint_digits(unsigned int n)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}
