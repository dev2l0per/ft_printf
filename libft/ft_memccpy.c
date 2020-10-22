/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:39:28 by juyang            #+#    #+#             */
/*   Updated: 2020/10/05 15:45:26 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	unsigned char	find;
	size_t			i;

	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*new_dst = *new_src;
		if (*new_src == find)
			return (dst + (i + 1));
		new_dst++;
		new_src++;
		i++;
	}
	return (0);
}
