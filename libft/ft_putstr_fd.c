/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@42student.co.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 20:58:10 by juyang            #+#    #+#             */
/*   Updated: 2020/10/10 21:08:59 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_fd(char *s, int fd)
{
	int		index;

	index = 0;
	if (!s || fd < 0)
		return (0);
	while (s[index])
	{
		write(fd, &s[index++], 1);
	}
	return (index);
}
