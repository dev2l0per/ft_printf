/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@42student.co.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:20:15 by juyang            #+#    #+#             */
/*   Updated: 2020/10/07 15:20:18 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		num_len(int n)
{
	size_t			len;
	long long int	nbr;

	len = 0;
	nbr = (long long int)n;
	if (nbr < 0)
	{
		len++;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	size_t			len;
	long long int	nbr;
	char			*res;
	int				sign;
	unsigned int	start;

	if (n == 0)
		return (ft_strdup("0"));
	start = 0;
	len = num_len(n);
	nbr = n;
	sign = (nbr < 0 ? -1 : 1);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nbr = nbr * sign;
	if (sign == -1)
		res[start++] = '-';
	res[len--] = '\0';
	while (nbr > 0)
	{
		res[len--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (res);
}
