/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:13:18 by juyang            #+#    #+#             */
/*   Updated: 2020/10/19 17:13:50 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_info(t_info *info)
{
	info->left_align = 0;
	info->zero = 0;
	info->dot = 0;
	info->width = 0;
	info->precision = 0;
	info->len = 0;
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			res;

	va_start(ap, format);
	res = format_parse((char *)format, ap);
	va_end(ap);
	return (res);
}

int main()
{
	// printf("[%d]\n", -123);
	// ft_printf("[%d]", -123);
	printf("%lu", sizeof(void *));
}