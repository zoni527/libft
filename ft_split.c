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

static size_t			ft_word_count(const char *s, char c);
static const char		*ft_skip_over_char(const char *str, char c);
static char				**ft_free_array(char **array, size_t len);

char	**ft_split(char const *s, char c)
{
	char		**str_array;
	const char	*temp;
	const char	*str;
	size_t		word_count;
	size_t		i;

	str = s;
	word_count = ft_word_count(str, c);
	str_array = malloc((word_count + 1) * sizeof(char *));
	if (str_array == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		str = ft_skip_over_char(str, c);
		temp = ft_strchr(s, c);
		str_array[i] = malloc((s - temp) + 1);
		if (!str_array[i])
			return (ft_free_array(str_array, i));
		ft_strlcpy(str_array[i], s, (s - temp) + 1);
		s = temp;
		i++;
	}
	return (str_array);
}

static size_t	ft_word_count(const char *s, char c)
{
	size_t	wc;

	wc = 0;
	while (*s)
	{
		if (*s == c)
			s = ft_skip_over_char(s, c);
		wc++;
		s = ft_strchr(s, c);
	}
	return (wc);
}

static const char	*ft_skip_over_char(const char *str, char c)
{
	while (*str && *str == c)
		str++;
	return (str);
}

static char	**ft_free_array(char **array, size_t len)
{
	while (len--)
		free(array[len]);
	free (array);
	return (NULL);
}
