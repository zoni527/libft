/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:23:36 by jvarila           #+#    #+#             */
/*   Updated: 2024/10/29 11:33:36 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	size_t	i;
	char	*char_position;

	char_position = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			char_position = s + i;
		i++;
	}
	if (c == '\0')
		return (s + i);
	return (char_position);
}
