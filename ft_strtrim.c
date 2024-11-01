/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:27:46 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/01 16:38:24 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	const char	*right;
	const char	*left;

	if (!*s1)
		return (ft_calloc(1, 1));
	left = s1;
	right = ft_strchr(s1, '\0') - 1;
	while (ft_strchr(set, *left))
		left++;
	while (ft_strrchr(set, *right))
		right--;
	if (left >= right)
		return (ft_calloc(1, 1));
	str = malloc(left - right + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, left, left - right + 1);
	return (str);
}
