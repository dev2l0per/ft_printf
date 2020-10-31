/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:01:27 by juyang            #+#    #+#             */
/*   Updated: 2020/10/31 19:01:28 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hex_lower_align_zero(t_info *info,
long long int lld, int len, char *str)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	if (lld < 0)
		res += ft_putchar_fd('-', 1);
	while (index++ < info->precision)
		res += ft_putchar_fd('0', 1);
	res += ft_putstr_fd(str, 1);
	if (lld < 0)
		len++;
	index = 0;
	while (index++ < info->width - info->precision - len)
		res += ft_putchar_fd(' ', 1);
	free(str);
	return (res);
}

int			print_hex_lower_align(t_info *info,
long long int lld, int len, char *str)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	if (lld == 0 && info->dot && info->precision == 0)
		len--;
	info->precision -= (info->precision >= len) ? len : 0;
	len += (lld < 0 && info->width > 0) ? 1 : 0;
	if (lld < 0)
		res += ft_putchar_fd('-', 1);
	while (index++ < info->precision)
		res += ft_putchar_fd('0', 1);
	if (!(lld == 0 && info->dot &&
	((info->precision + len) == 0)) || info->precision_sign)
	{
		res += ft_putstr_fd(str, 1);
		if (lld == 0)
			len = ft_strlen(str);
	}
	index = 0;
	while (index++ < info->width - info->precision - len)
		res += ft_putchar_fd(' ', 1);
	free(str);
	return (res);
}

int			print_hex_lower_zero(t_info *info,
long long int lld, int len, char *str)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	len -= (lld == 0 && info->dot && info->precision == 0) ? 1 : 0;
	info->precision -= (info->precision >= len) ? len : 0;
	len += (lld < 0 && info->width > 0) ? 1 : 0;
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
	info->precision == 0) || info->precision_sign)
		res += ft_putstr_fd(str, 1);
	free(str);
	return (res);
}

int			print_hex_lower_noflag(t_info *info,
long long int lld, int len, char *str)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	len -= (lld == 0 && info->dot && info->precision == 0) ? 1 : 0;
	info->precision -= (info->precision >= len) ? len : 0;
	len += (lld < 0 && info->width > 0) ? 1 : 0;
	len = (info->precision == 0 && lld == 0
	&& info->width != -1 && info->precision_sign) ? 1 : len;
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
		res += ft_putstr_fd(str, 1);
		len = (!lld) ? ft_strlen(str) : len;
	}
	free(str);
	return (res);
}

int			print_hex_lower(t_info *info, va_list ap)
{
	long long int	lld;
	int				len;
	int				res;
	char			*str;

	res = 0;
	lld = (unsigned int)va_arg(ap, unsigned int);
	str = ft_itoa_base(lld, 16);
	len = ft_strlen(str);
	info->width -= info->space;
	info->width *= (info->width < 0) ? -1 : 1;
	info->width = (info->width < len) ? -1 : info->width;
	if (info->precision < 0 && (info->precision_sign = 1))
		info->precision = 0;
	else if (info->precision < len && info->precision != 0)
		info->precision = len;
	if (info->left_align)
		res += (info->zero) ?
		print_hex_lower_align_zero(info, lld, len, str)
		: print_hex_lower_align(info, lld, len, str);
	else
		res += (info->zero) ?
		print_hex_lower_zero(info, lld, len, str)
		: print_hex_lower_noflag(info, lld, len, str);
	return (res);
}
