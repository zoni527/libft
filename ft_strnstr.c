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
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < len && *big)
	{
		j = 0;
		while (little[j] == big[j] && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)big);
		i++;
		big++;
	}
	return (NULL);
}
