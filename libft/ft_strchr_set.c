/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:17:11 by juyang            #+#    #+#             */
/*   Updated: 2020/10/31 17:17:12 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr_set(const char *s, char *set)
{
	int			index;

	index = 0;
	while (set[index])
	{
		if (ft_strchr(s, set[index]))
			return (ft_strchr(s, set[index]));
		index++;
	}
	return (NULL);
}
