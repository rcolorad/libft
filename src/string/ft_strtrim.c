/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolorad <rcolorad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:39:45 by rcolorad          #+#    #+#             */
/*   Updated: 2024/09/19 22:18:48 by rcolorad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	size;

	str = NULL;
	i = 0;
	if (!s1)
		return (NULL);
	if (set)
	{
		size = ft_strlen(s1);
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
			i++;
		while (s1[size - 1] && size > i && ft_strchr(set, s1[size - 1]))
			size--;
		str = (char *) malloc((size - i + 1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, ((char *)s1 + i), size - i + 1);
	}
	return (str);
}
