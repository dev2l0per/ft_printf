/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:34:11 by juyang            #+#    #+#             */
/*   Updated: 2020/10/31 18:34:13 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_string_align_precision(t_info *info, char *str, int str_len)
{
	int				index;
	int				res;

	res = 0;
	index = 0;
	if (info->precision > str_len)
		info->precision = str_len;
	while (str[index] && index < info->precision)
		res += ft_putchar_fd(str[index++], 1);
	index = 0;
	while (index++ < info->width - info->precision)
		res += ft_putchar_fd(' ', 1);
	return (res);
}

int			print_string_align(t_info *info, char *str, int str_len)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	if (info->dot && !info->precision)
	{
		while (index++ < info->width)
			res += ft_putchar_fd(' ', 1);
	}
	else if (!info->dot)
	{
		res += ft_putstr_fd(str, 1);
		while (index++ < info->width - str_len)
			res += ft_putchar_fd(' ', 1);
	}
	else if (!(info->dot && !info->width))
	{
		res += ft_putstr_fd(str, 1);
		while (index++ < info->width - str_len)
			res += ft_putchar_fd(' ', 1);
	}
	return (res);
}

int			print_string_precision(t_info *info, char *str, int str_len)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	if (info->precision > str_len)
		info->precision = str_len;
	while (index++ < info->width - info->precision)
		res += ft_putchar_fd(' ', 1);
	index = 0;
	while (str[index] && index < info->precision)
		res += ft_putchar_fd(str[index++], 1);
	return (res);
}

int			print_string_noflag(t_info *info, char *str, int str_len)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	if (info->dot && !info->precision)
		while (index++ < info->width)
			res += ft_putchar_fd(' ', 1);
	else if (!(info->dot && !info->width))
	{
		while (index++ < info->width - str_len)
			res += (info->zero) ? ft_putchar_fd('0', 1) : ft_putchar_fd(' ', 1);
		res += ft_putstr_fd(str, 1);
	}
	else if (!info->dot)
	{
		while (index++ < info->width - str_len)
			res += (info->zero) ? ft_putchar_fd('0', 1) : ft_putchar_fd(' ', 1);
		res += ft_putstr_fd(str, 1);
	}
	return (res);
}

int			print_string(t_info *info, va_list ap)
{
	char			*str;
	int				str_len;
	int				res;
	char			*va;

	res = 0;
	info->width *= (info->width < 0) ? -1 : 1;
	va = va_arg(ap, char *);
	str = (!va) ? ft_strdup("(null)") : ft_strdup(va);
	str_len = (int)ft_strlen(str);
	if (info->width < 0)
		info->width = ((info->width * -1) < str_len)
		? str_len : info->width * -1;
	if (info->precision < 0)
		info->precision = ((info->precision * -1) < str_len)
		? str_len : info->precision * -1;
	if (info->left_align)
		res += (info->precision) ?
		print_string_align_precision(info, str, str_len)
		: print_string_align(info, str, str_len);
	else
		res += (info->precision) ? print_string_precision(info, str, str_len)
		: print_string_noflag(info, str, str_len);
	free(str);
	return (res);
}
