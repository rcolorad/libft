/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolorad <rcolorad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:24:29 by rcolorad          #+#    #+#             */
/*   Updated: 2024/09/19 22:18:16 by rcolorad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!copy || !s1)
		return (NULL);
	ft_memcpy(copy, s1, ft_strlen(s1));
	copy[ft_strlen(s1)] = '\0';
	return (copy);
}
