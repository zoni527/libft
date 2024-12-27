/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:42:36 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/27 10:46:57 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *str)
{
	int	wc;

	if (*str == '\0')
		return (0);
	wc = 0;
	while (*str != '\0')
	{
		if (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		wc++;
		while (!(*str == ' ' || (*str >= 9 && *str <= 13)))
			str++;
	}
	return (wc);
}
