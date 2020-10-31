/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:25:11 by juyang            #+#    #+#             */
/*   Updated: 2020/10/31 18:25:12 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_character(t_info *info, va_list ap)
{
	int				res;
	int				index;

	res = 0;
	index = 0;
	if (info->width < 0)
		info->width = info->width * -1;
	if (info->left_align)
	{
		res += ft_putchar_fd((char)va_arg(ap, int), 1);
		while (++index < info->width)
			res += ft_putchar_fd(' ', 1);
	}
	else
	{
		while (++index < info->width)
			res += ft_putchar_fd(' ', 1);
		res += ft_putchar_fd((char)va_arg(ap, int), 1);
	}
	return (res);
}

int			print_percent(t_info *info)
{
	int				res;
	int				index;

	res = 0;
	index = 0;
	info->width *= (info->width < 0 && !(info->percent_zero = 0)) ? -1 : 1;
	info->width -= 1;
	info->precision *= (info->precision < 0) ? -1 : 1;
	if (info->left_align)
	{
		res += ft_putchar_fd('%', 1);
		while (index++ < info->width)
			res += ft_putchar_fd(' ', 1);
	}
	else
	{
		if (info->percent_zero)
			while (index++ < info->width)
				res += ft_putchar_fd('0', 1);
		else
			while (index++ < info->width)
				res += ft_putchar_fd(' ', 1);
		res += ft_putchar_fd('%', 1);
	}
	return (res);
}

int			print_cspercent(t_info *info, va_list ap, char conversion)
{
	int				res;
	int				index;

	res = 0;
	index = 0;
	if (conversion == 'c')
		res += print_character(info, ap);
	else if (conversion == '%')
		res += print_percent(info);
	else if (conversion == 's')
		res += print_string(info, ap);
	return (res);
}
