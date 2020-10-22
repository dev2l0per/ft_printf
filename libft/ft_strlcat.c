/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:49:55 by juyang            #+#    #+#             */
/*   Updated: 2020/10/05 23:15:34 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	dst_len_tmp;

	dst_len = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (dst[dst_len] != '\0' && dst_len < dstsize)
		dst_len++;
	dst_len_tmp = dst_len;
	i = 0;
	if (dst_len < dstsize)
	{
		while (dst_len < (dstsize - 1) && src[i])
			dst[dst_len++] = src[i++];
		dst[dst_len] = '\0';
	}
	if (dstsize < dst_len_tmp)
		return (dstsize + src_len);
	return (dst_len_tmp + src_len);
}
