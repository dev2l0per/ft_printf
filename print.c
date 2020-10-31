/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 20:17:25 by juyang            #+#    #+#             */
/*   Updated: 2020/10/22 20:17:27 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_integer_setting(t_info *info, int *len, long long int lld)
{
	*len -= (!lld && info->dot && !info->precision) ? 1 : 0;
	info->precision -= (info->precision >= *len) ? *len : 0;
	*len += (lld < 0 && info->width > 0) ? 1 : 0;
}

void		null_string(va_list ap, char *str)
{
	char		*va;

	va = va_arg(ap, char *);
	if (!str)
	{
		str = ft_strdup("(null)");
	}
	else
		str = ft_strdup(va);
}