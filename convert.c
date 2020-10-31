/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@42student.co.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:43:08 by juyang            #+#    #+#             */
/*   Updated: 2020/10/28 13:43:09 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		num_len(long long int n, int base)
{
	size_t			len;
	long long int	nbr;

	len = 0;
	nbr = (long long int)n;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr > 0)
	{
		len++;
		nbr = nbr / base;
	}
	return (len);
}

char		*ft_itoa_base(long long int num, int base)
{
	size_t			len;
	long long int	nbr;
	char			*res;
	int				sign;
	unsigned int	start;

	if (num == 0)
		return (ft_strdup("0"));
	start = 0;
	len = num_len(num, base);
	nbr = num;
	sign = (nbr < 0 ? -1 : 1);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nbr = nbr * sign;
	res[len--] = '\0';
	while (nbr > 0)
	{
		res[len--] = HEX_LOWER[nbr % base];
		nbr = nbr / base;
	}
	return (res);
}

char		*ft_itoa_base_upper(long long int num, int base)
{
	size_t			len;
	long long int	nbr;
	char			*res;
	int				sign;
	unsigned int	start;

	if (num == 0)
		return (ft_strdup("0"));
	start = 0;
	len = num_len(num, base);
	nbr = num;
	sign = (nbr < 0 ? -1 : 1);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nbr = nbr * sign;
	res[len--] = '\0';
	while (nbr > 0)
	{
		res[len--] = HEX_UPPER[nbr % base];
		nbr = nbr / base;
	}
	return (res);
}
