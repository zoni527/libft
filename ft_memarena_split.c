/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memarena_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:41:26 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/21 12:44:33 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		word_count_delim(const char *s, char c);
static const char	*ft_skip_over_char(const char *s, char c);
static char			**ft_free_array(char **array, size_t len);
static size_t		ft_len_till_c(const char *s, char c);

char	**ft_memarena_split(t_memarena *arena, char const *s, char c)
{
	char		**str_array;
	size_t		word_count;
	size_t		i;

	word_count = word_count_delim(s, c);
	str_array = ft_memarena_malloc(arena, (word_count + 1) * sizeof(char *));
	if (str_array == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		s = ft_skip_over_char(s, c);
		str_array[i] = ft_memarena_substr(arena, s, 0, ft_len_till_c(s, c));
		if (!str_array[i])
			return (ft_free_array(str_array, i));
		s = ft_strchr(s, c);
		i++;
	}
	str_array[i] = NULL;
	return (str_array);
}

static size_t	word_count_delim(const char *s, char c)
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

static size_t	ft_len_till_c(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static const char	*ft_skip_over_char(const char *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static char	**ft_free_array(char **array, size_t len)
{
	while (len--)
		free(array[len]);
	free (array);
	return (NULL);
}
