/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:47:40 by juyang            #+#    #+#             */
/*   Updated: 2020/10/31 18:47:42 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_address_align_precision(t_info *info,
long long int lld, int len, char *str)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	info->precision = (len > info->precision) ? len : info->precision;
	while (index++ < info->precision - len)
		res += ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	res += ft_strlen(str);
	index = 0;
	index += (lld < 0) ? 1 : 0;
	while (index++ < info->width - info->precision)
		res += (info->zero) ?
		ft_putchar_fd('0', 1) : ft_putchar_fd(' ', 1);
	return (res);
}

int			print_address_align(t_info *info, long long int lld, int len, char *str)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	ft_putstr_fd("0x", 1);
	res += 2;
	if (!(lld == 0 && info->dot))
	{
		ft_putstr_fd(str, 1);
		res += ft_strlen(str);
	}
	else
		len = 0;
	while (index++ < info->width - len - 2)
		res += (info->zero) ? ft_putchar_fd('0', 1) : ft_putchar_fd(' ', 1);
	return (res);
}

int			print_address_precision(t_info *info, long long int lld, int len, char *str)
{
	int				index;
	int				res;

	index = 0;
	res = 0;

	if ((int)num_len(lld, 16) > info->precision)
		info->precision = (int)num_len(lld, 16);
	while (index < info->width - info->precision - 2)
	{
		res += (info->zero) ? ft_putchar_fd('0', 1) : ft_putchar_fd(' ', 1);
		index++;
	}
	ft_putstr_fd("0x", 1);
	res += 2;
	len = (info->width > info->precision) ? len + 2 : len;
	info->width -= index;
	index = 0;
	while (index++ < info->precision - len)
		res += ft_putchar_fd('0', 1);
	if (!(info->dot && lld == 0) || !info->width)
	{
		res +=ft_putstr_fd(str, 1);
	}
	return (res);
}

int			print_address_noflag(t_info *info, long long int lld, int len, char *str)
{
	int				index;
	int				res;

	index = 0;
	res = 0;
	if (info->zero)
	{
		len = (lld == 0) ? 0 : len;
		while (index++ < info->width - len - 2)
			res += ft_putchar_fd('0', 1);
		res += ft_putstr_fd("0x", 1);
	}
	else
	{
		len = (info->dot && lld == 0) ? 0 : len;
		while (index++ < info->width - len - 2)
			res += ft_putchar_fd(' ', 1);
		res += ft_putstr_fd("0x", 1);
	}
	if (!(info->dot && lld == 0))
		res += ft_putstr_fd(str, 1);
	else if ((info->dot && lld == 0) &&
	(info->precision > (int)ft_strlen(str)))
		res += ft_putchar_fd('0', 1);
	return (res);
}

int			print_address(t_info *info, va_list ap)
{
	long long int	lld;
	int				len;
	int				index;
	int				res;
	char			*str;

	res = 0;
	lld = (long long int)va_arg(ap, long long);
	str = ft_itoa_base(lld, 16);
	len = ft_strlen(str);
	index = 0;
	if (info->width < 0)
		info->width = info->width * -1;
	if (info->left_align)
		res += (info->precision) ?
		print_address_align_precision(info, lld, len, str)
		: print_address_align(info, lld, len, str);
	else
		res += (info->precision) ?
		print_address_precision(info, lld, len, str)
		: print_address_noflag(info, lld, len, str);
	free(str);
	return (res);
}
