/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:10:37 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/28 15:31:19 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_long_digits(long int n)
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
