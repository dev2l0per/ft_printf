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

void		print_string(t_info *info, va_list ap, char conversion)
{
	if (conversion == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (conversion == '%')
		ft_putchar_fd('%', 1);
	else if (conversion == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
}

void		print_address(t_info *info, va_list ap, char conversion)
{
	ft_putstr_fd(ft_itoa_base(va_arg(ap, long long int), 16), 1);
}

void		print_integer(t_info *info, va_list ap, char conversion)
{
	long long int	lld;
	int				len;
	int				index;

	lld = (long long int)va_arg(ap, int);
	len = ft_strlen(ft_itoa_base(lld, 10));
	index = 0;
	if (info->left_align)
	{
		if (info->precision)
		{
			if (lld < 0)
				ft_putchar_fd('-', 1);
			while (index++ < info->precision - len)
				ft_putchar_fd('0', 1);
			ft_putstr_fd(ft_itoa_base(lld, 10), 1);
			index = 0;
			if (lld < 0)
				index++;
			while (index++ < info->width - info->precision)
			{
				if (info->zero)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
			}
		}
		else
		{
			if (lld < 0)
				ft_putchar_fd('-', 1);
			while (index++ < info->width - len)
				ft_putchar_fd('0', 1);
			ft_putstr_fd(ft_itoa_base(lld, 10), 1);
		}
	}
	else
	{
		if (info->precision)
		{
			if (lld < 0)
				index++;
			while (index++ < info->width - info->precision)
			{
				if (info->zero)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
			}
			if (lld < 0)
				ft_putchar_fd('-', 1);
			index = 0;
			while (index++ < info->precision - len)
				ft_putchar_fd('0', 1);
			ft_putstr_fd(ft_itoa_base(lld, 10), 1);
		}
		else
		{
			if (lld < 0)
				ft_putchar_fd('-', 1);
			while (index++ < info->width - len)
			{
				if (info->zero)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(ft_itoa_base(lld, 10), 1);
		}
	}
}

void		print_hex(t_info *info, va_list ap, char conversion)
{
	ft_putstr_fd(ft_itoa_base(va_arg(ap, int), 16), 1);
}