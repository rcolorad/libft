/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolorad <rcolorad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:28:13 by rcolorad          #+#    #+#             */
/*   Updated: 2024/09/19 22:17:30 by rcolorad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*aux;

	i = 0;
	aux = (void *)s;
	while (i < n)
	{
		if (*aux == (char)c)
			return (aux);
		i++;
		aux++;
	}
	return (NULL);
}
