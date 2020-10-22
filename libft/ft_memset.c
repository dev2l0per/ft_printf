/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:24:52 by juyang            #+#    #+#             */
/*   Updated: 2020/10/05 15:45:52 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new_b;
	unsigned char	src;
	size_t			i;

	new_b = (unsigned char *)b;
	src = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*new_b++ = src;
		i++;
	}
	return (b);
}
