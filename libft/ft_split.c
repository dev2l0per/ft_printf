/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@42student.co.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:00:53 by juyang            #+#    #+#             */
/*   Updated: 2020/10/10 22:23:31 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(char const *s, char c)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	if (s[i] && s[i] != c)
		cnt++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			cnt++;
		i++;
	}
	return (cnt);
}

static int	word_len(char const *s, char c)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static void	*isfree(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i++]);
	}
	free(str);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s || !(res = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(res[i] = (char *)malloc(sizeof(char) * word_len(s, c) + 1)))
				return (isfree(res));
			while (*s && *s != c)
				res[i][j++] = (char)*s++;
			res[i][j] = '\0';
			i++;
		}
	}
	res[i] = 0;
	return (res);
}
