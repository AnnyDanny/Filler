/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:51:21 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/09 17:51:22 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long long int i)
{
	int k;

	k = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i = -i;
		k++;
	}
	while (i > 0)
	{
		i = i / 10;
		k++;
	}
	return (k);
}

char		*ft_itoa(int n)
{
	int				i;
	long long int	l;
	int				len;
	char			*str;

	i = 0;
	l = n;
	len = count(l);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (l < 0)
	{
		str[0] = '-';
		l = -l;
	}
	if (l == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (l)
	{
		str[len] = l % 10 + '0';
		l = l / 10;
		len--;
	}
	return (str);
}
