/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolorad <rcolorad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:44 by rcolorad          #+#    #+#             */
/*   Updated: 2024/09/19 22:16:05 by rcolorad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n != 0)
		{
			n /= 10;
			count++;
		}
	}
	return (count);
}

static char	*fill_str(char *str, int n, int digits)
{
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		str[digits - 1] = (n % 10) + '0';
		n /= 10;
		digits--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	else
	{
		digits = count_digits(n);
		if (n < 0)
			digits++;
		str = (char *)malloc((digits + 1) * sizeof(char));
		if (!str)
			return (NULL);
		str = fill_str(str, n, digits);
		str[digits] = '\0';
	}
	return (str);
}
