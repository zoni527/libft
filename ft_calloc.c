/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:51:58 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/01 10:56:46 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	bytes;
	size_t	i;

	bytes = size * nmemb;
	if (size == 0 || nmemb == 0 || bytes / nmemb != size)
		return (NULL);
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = '\0';
	return ((void *)ptr);
}
