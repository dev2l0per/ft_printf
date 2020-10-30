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
	info->percent_zero = 0;
	info->zero = 0;
	info->dot = 0;
	info->width = 0;
	info->precision = 0;
	info->precision_sign = 0;
	info->space = 0;
	info->len = 0;
}

void			print_info(t_info *info)
{
	printf("left_align : %d\n", info->left_align);
	printf("zero : %d\n", info->zero);
	printf("dot : %d\n", info->dot);
	printf("width : %d\n", info->width);
	printf("precision : %d\n", info->precision);
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
