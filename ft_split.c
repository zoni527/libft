/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:13:34 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/01 18:34:20 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	size_t	i;


}

size_t	ft_word_count(const char *s, char c)
{
	size_t	wc;

	wc = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue;
		}
		wc++;
		while (*s != c)
			s++;
	}
	return (wc);
}
