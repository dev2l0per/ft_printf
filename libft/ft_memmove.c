/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:46:41 by juyang            #+#    #+#             */
/*   Updated: 2020/10/05 20:24:01 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	if (dst == src || len == 0)
		return (dst);
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	i = 0;
	if (dst < src)
		while (i++ < len)
			*new_dst++ = *new_src++;
	else
	{
		new_dst = new_dst + len - 1;
		new_src = new_src + len - 1;
		while (i++ < len)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
