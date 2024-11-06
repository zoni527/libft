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

static size_t		ft_word_count(const char *s, char c);
static const char	*ft_skip_over_char(const char *str, char c);
static char			**ft_free_array(char **array, size_t len);
static size_t		ft_len_till_c(const char *str, char c);

char	**ft_split(char const *s, char c)
{
	char		**str_array;
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
		str_array[i] = ft_substr(str, 0, ft_len_till_c(str, c));
		if (!str_array[i])
			return (ft_free_array(str_array, i));
		str = ft_strchr(str, c);
		i++;
	}
	str_array[i] = NULL;
	return (str_array);
}

static size_t	ft_word_count(const char *s, char c)
{
	size_t	wc;

	wc = 0;
	while (s && *s)
	{
		if (*s == c)
		{
			s = ft_skip_over_char(s, c);
			continue ;
		}
		wc++;
		s = ft_strchr(s, c);
	}
	return (wc);
}

static size_t	ft_len_till_c(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
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
