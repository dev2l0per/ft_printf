/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:30:52 by juyang            #+#    #+#             */
/*   Updated: 2020/10/31 17:30:53 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_integer_align_zero(long long int lld,
t_info *info, int len, char *str)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	if (lld < 0)
		res += ft_putchar_fd('-', 1);
	while (index++ < info->precision)
		res += ft_putchar_fd('0', 1);
	if (!(lld == 0 && info->dot &&
	((info->precision + len) == 0)) || info->precision_sign)
	{
		ft_putstr_fd(str, 1);
		res += ft_strlen(str);
		len = (!lld) ? ft_strlen(str) : len;
	}
	index = 0;
	while (index++ < info->width - info->precision - len)
		res += ft_putchar_fd(' ', 1);
	free(str);
	return (res);
}

int			print_integer_align(long long int lld,
t_info *info, int len, char *str)
{
	int			index;
	int			res;

	index = 0;
	res = 0;
	if (lld < 0)
		res += ft_putchar_fd('-', 1);
	while (index++ < info->precision)
		res += ft_putchar_fd('0', 1);
	if (!(lld == 0 && info->dot &&
	((info->precision + len) == 0)) || info->precision_sign)
	{
		ft_putstr_fd(str, 1);
		res += ft_strlen(str);
		len = (!lld) ? ft_strlen(str) : len;
	}
	index = 0;
	while (index++ < info->width - info->precision - len)
		res += ft_putchar_fd(' ', 1);
	free(str);
	return (res);
}

int			print_integer_zero(long long int lld,
t_info *info, int len, char *str)
{
	int			index;
	int			res;

	index = 0;
	res = 0;
	len = (info->precision == 0 && lld == 0 &&
	info->width != -1 && info->precision_sign) ? 1 : len;
	if (lld < 0)
		res += ft_putchar_fd('-', 1);
	while (index++ < info->width - info->precision - len)
		res += ft_putchar_fd('0', 1);
	index = 0;
	while (index++ < info->precision)
		res += ft_putchar_fd('0', 1);
	if (!(lld == 0 && info->dot &&
	(info->precision + len) == 0) || info->precision_sign)
	{
		ft_putstr_fd(str, 1);
		res += ft_strlen(str);
		if (lld == 0)
			len = ft_strlen(str);
	}
	free(str);
	return (res);
}

int			print_integer_noflag(long long int lld,
t_info *info, int len, char *str)
{
	int			index;
	int			res;

	index = 0;
	res = 0;
	len = (info->precision == 0 && lld == 0 &&
	info->width != -1 && info->precision_sign) ? 1 : len;
	while (index++ < info->width - info->precision - len)
		res += ft_putchar_fd(' ', 1);
	if (lld < 0)
		res += ft_putchar_fd('-', 1);
	index = 0;
	while (index++ < info->precision)
		res += ft_putchar_fd('0', 1);
	if (!(lld == 0 && info->dot &&
	(info->precision + len) == 0) || info->precision_sign)
	{
		ft_putstr_fd(str, 1);
		res += ft_strlen(str);
		len = (!lld) ? ft_strlen(str) : len;
	}
	free(str);
	return (res);
}

int			print_integer(t_info *info, va_list ap, char conversion)
{
	long long int	lld;
	int				len;
	int				res;
	char			*str;

	res = 0;
	lld = (conversion == 'u') ?
	(long long int)va_arg(ap, unsigned int) : (long long int)va_arg(ap, int);
	str = ft_itoa_base(lld, 10);
	len = ft_strlen(str);
	info->width -= info->space;
	info->width = (info->width < 0) ? info->width * -1 : info->width;
	info->width = (info->width < len) ? -1 : info->width;
	if (info->precision < 0 && (info->precision_sign = 1))
		info->precision = 0;
	else if (info->precision < len && info->precision != 0)
		info->precision = len;
	print_integer_setting(info, &len, lld);
	if (info->left_align)
		res += (info->zero) ? print_integer_align_zero(lld, info, len, str)
		: print_integer_align(lld, info, len, str);
	else
		res += (info->zero) ? print_integer_zero(lld, info, len, str)
		: print_integer_noflag(lld, info, len, str);
	return (res);
}
