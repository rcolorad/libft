/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolorad <rcolorad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:54:44 by rcolorad          #+#    #+#             */
/*   Updated: 2024/09/19 22:18:22 by rcolorad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	n;

	if (!s1 || !s2)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2);
	join = (char *) malloc((n + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, (char *)s1, n + 1);
	ft_strlcat(join, s2, n + 1);
	return (join);
}
