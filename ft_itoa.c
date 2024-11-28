/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:48:20 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/12 12:41:23 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Use the calculated amount of digits and a possible minus sign to
// create the string memory with malloc, create a positive copy of
// the number but store the sign, write backwards and insert digits
// from the right end of the number using modulo, shrink the number
// by dividing by ten. If the number is negative the last element
// will be the minus sign, the last remaining digit otherwise. Use
// long to avoid converting INT_MIN to a positive int and overflowing.
// Return string and enjoy!

char	*ft_itoa(int n)
{
	char	*str;
	int		str_len;
	long	n_temp;

	str_len = ft_int_digits(n);
	if (n < 0)
		str_len++;
	str = malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[str_len] = '\0';
	n_temp = (long)n;
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
