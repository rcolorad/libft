/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolorad <rcolorad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:27:22 by rcolorad          #+#    #+#             */
/*   Updated: 2024/09/19 22:18:06 by rcolorad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

static void	ft_free(char **matriz, int i)
{
	while (i)
	{
		free(matriz[i - 1]);
		i--;
	}
	free(matriz);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**words;

	i = -1;
	words = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!words || !s)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				count = ft_strlen(s);
			else
				count = ft_strchr(s, c) - s;
			words[++i] = ft_substr(s, 0, count);
			if (!words[i])
				return (ft_free(words, i), NULL);
			s += count;
		}
	}
	return (words);
}
