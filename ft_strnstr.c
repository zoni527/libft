/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:48:35 by jvarila           #+#    #+#             */
/*   Updated: 2024/10/31 10:55:05 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	while (*big)
	{
		i = 0;
		while (i < len && little[i] == big[i])
			i++;
		if (i == len)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
