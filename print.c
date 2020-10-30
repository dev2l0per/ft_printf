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

int			print_string(t_info *info, va_list ap, char conversion)
{
	int				res;
	char			*str;
	int				str_len;
	int				index;

	res = 0;
	index = 0;
	if (conversion == 'c')
	{
		if (info->width < 0)
			info->width = info->width * -1;
		if (info->left_align)
		{
			ft_putchar_fd((char)va_arg(ap, int), 1);
			res++;
			while (++index < info->width)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
		}
		else
		{
			while (++index < info->width)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
			ft_putchar_fd((char)va_arg(ap, int), 1);
			res++;
		}
	}
	else if (conversion == '%')
	{
		if (info->width < 0)
		{
			info->percent_zero = 0;
			info->width *= -1;
		}
		info->width -= 1;
		if (info->precision < 0)
			info->precision = info->precision * -1;
		if (info->left_align)
		{
			if (info->percent_zero)
			{
				ft_putchar_fd('%', 1);
				res++;
				while (index++ < info->width)
				{
					ft_putchar_fd(' ', 1);
					res++;
				}
			}
			else
			{
				ft_putchar_fd('%', 1);
				res++;
				while (index++ < info->width)
				{
					ft_putchar_fd(' ', 1);
					res++;
				}
			}
		}
		else
		{
			if (info->percent_zero)
			{
				while (index++ < info->width)
				{
					ft_putchar_fd('0', 1);
					res++;
				}
				ft_putchar_fd('%', 1);	
				res++;
			}
			else
			{
				while (index++ < info->width)
				{
					ft_putchar_fd(' ', 1);
					res++;
				}
				ft_putchar_fd('%', 1);	
				res++;
			}
		}
	}
	else if (conversion == 's')
	{
		if (info->width < 0)
			info->width = info->width * -1;
		str = va_arg(ap, char *);
		if (!str)
			str = ft_strdup("(null)");
		str_len = (int)ft_strlen(str);
		if (info->width < 0)
			info->width = ((info->width * -1) < str_len) ? str_len : info->width * -1;
		if (info->precision < 0)
			info->precision = ((info->precision * -1) < str_len) ? str_len : info->precision * -1;
		if (info->left_align)
		{
			if (info->precision)
			{
				if (info->precision > str_len)
					info->precision = str_len;
				while (str[index] && index < info->precision)
				{
					ft_putchar_fd(str[index++], 1);
					res++;
				}
				index = 0;
				while (index++ < info->width - info->precision)
				{
					ft_putchar_fd(' ', 1);
					res++;
				}
			}
			else
			{
				if (info->dot && !info->precision)
				{
					while (index++ < info->width)
					{
						ft_putchar_fd(' ', 1);
						res++;
					}
				}
				else if (!info->dot)
				{
					ft_putstr_fd(str, 1);
					res += str_len;
					while (index++ < info->width - str_len)
					{
						ft_putchar_fd(' ', 1);
						res++;
					}
				}
				else if (!(info->dot && !info->width))
				{
					ft_putstr_fd(str, 1);
					res += str_len;
					while (index++ < info->width - str_len)
					{
						ft_putchar_fd(' ', 1);
						res++;
					}
				}
				
			}
		}
		else
		{
			if (info->precision)
			{
				if (info->precision > str_len)
					info->precision = str_len;
				while (index++ < info->width - info->precision)
				{
					ft_putchar_fd(' ', 1);
					res++;
				}
				index = 0;
				while (str[index] && index < info->precision)
				{
					ft_putchar_fd(str[index++], 1);
					res++;
				}
			}
			else
			{
				if (info->dot && !info->precision)
				{
					while (index++ < info->width)
					{
						ft_putchar_fd(' ', 1);
						res++;
					}
				}
				else if (!(info->dot && !info->width))
				{
					while (index++ < info->width - str_len)
					{
						if (info->zero)
							ft_putchar_fd('0', 1);
						else
							ft_putchar_fd(' ', 1);
						res++;
					}
					ft_putstr_fd(str, 1);
					res += str_len;
				}
				else if (!info->dot)
				{
					while (index++ < info->width - str_len)
					{
						if (info->zero)
							ft_putchar_fd('0', 1);
						else
							ft_putchar_fd(' ', 1);
						res++;
					}
					ft_putstr_fd(str, 1);
					res += str_len;
				}
			}
		}
	}
	return (res);
}

int			print_address(t_info *info, va_list ap, char conversion)
{
	long long int	lld;
	int				len;
	int				index;
	int				res;

	(void)conversion;
	res = 0;
	lld = (long long int)va_arg(ap, long long);
	len = ft_strlen(ft_itoa_base(lld, 16));
	index = 0;
	if (info->width < 0)
		info->width = info->width * -1;
	if (info->left_align)
	{
		if (info->precision)
		{
			if (len > info->precision)
				info->precision = len;
			while (index++ < info->precision - len)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			ft_putstr_fd(ft_itoa_base(lld, 16), 1);
			res += ft_strlen(ft_itoa_base(lld, 16));
			index = 0;
			if (lld < 0)
				index++;
			while (index++ < info->width - info->precision)
			{
				if (info->zero)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
				res++;
			}
		}
		else
		{
			ft_putstr_fd("0x", 1);
			res += 2;
			if (!(lld == 0 && info->dot))
			{
				ft_putstr_fd(ft_itoa_base(lld, 16), 1);
				res += ft_strlen(ft_itoa_base(lld, 16));
			}
			else
				len = 0;
			while (index++ < info->width - len - 2)
			{
				if (info->zero)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
				res++;
			}
		}
	}
	else
	{
		if (info->precision)
		{
			if ((int)num_len(lld, 16) > info->precision)
				info->precision = (int)num_len(lld, 16);
			while (index < info->width - info->precision - 2)
			{
				if (info->zero)
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
				res++;
				index++;
			}
			ft_putstr_fd("0x", 1);
			res += 2;
			len = (info->width > info->precision) ? len + 2 : len;
			info->width -= index;
			index = 0;
			while (index++ < info->precision - len)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(info->dot && lld == 0) || !info->width)
			{
				ft_putstr_fd(ft_itoa_base(lld, 16), 1);
				res += ft_strlen(ft_itoa_base(lld, 16));
			}
		}
		else
		{
			if (info->zero)
			{
				len = (lld == 0) ? 0 : len;
				while (index++ < info->width - len - 2)
				{
					ft_putchar_fd('0', 1);
					res++;
				}
				ft_putstr_fd("0x", 1);
				res += 2;
			}
			else
			{
				len = (info->dot && lld == 0) ? 0 : len;
				while (index++ < info->width - len - 2)
				{
					ft_putchar_fd(' ', 1);
					res++;
				}
				ft_putstr_fd("0x", 1);
				res += 2;
			}
			if (!(info->dot && lld == 0))
			{
				ft_putstr_fd(ft_itoa_base(lld, 16), 1);
				res += ft_strlen(ft_itoa_base(lld, 16));
			}
			else if ((info->dot && lld == 0) && (info->precision > (int)ft_strlen(ft_itoa_base(lld, 16))))
			{
				ft_putchar_fd('0', 1);
				res++;
			}
		}
	}
	return (res);
}

int			print_integer(t_info *info, va_list ap, char conversion)
{
	long long int	lld;
	int				len;
	int				index;
	int				res;

	res = 0;
	if (conversion == 'u')
		lld = (long long int)va_arg(ap, unsigned int);
	else
		lld = (long long int)va_arg(ap, int);
	len = ft_strlen(ft_itoa_base(lld, 10));
	info->width -= info->space;
	if (info->width < 0)
		info->width = info->width * -1;
	if (info->width < len)
		info->width = -1;
	if (info->precision < 0)
	{
		info->precision_sign = 1;
		info->precision = 0;
	}
	else if (info->precision < len && info->precision != 0)
		info->precision = len;
	index = 0;
	if (info->left_align)
	{
		if (info->zero)
		{
			if (lld == 0 && info->dot && info->precision == 0)
				len--;
			if (info->precision >= len)
				info->precision -= len;
			if (lld < 0 && info->width > 0)
				len++;
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(lld == 0 && info->dot && ((info->precision + len) == 0)) || info->precision_sign)
			{
				ft_putstr_fd(ft_itoa_base(lld, 10), 1);
				res += ft_strlen(ft_itoa_base(lld, 10));
				if (lld == 0)
					len = ft_strlen(ft_itoa_base(lld, 10));
			}
			index = 0;
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
		}
		else
		{
			if (lld == 0 && info->dot && info->precision == 0)
				len--;
			if (info->precision >= len)
				info->precision -= len;
			if (lld < 0 && info->width > 0)
				len++;
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(lld == 0 && info->dot && ((info->precision + len) == 0)) || info->precision_sign)
			{
				ft_putstr_fd(ft_itoa_base(lld, 10), 1);
				res += ft_strlen(ft_itoa_base(lld, 10));
				if (lld == 0)
					len = ft_strlen(ft_itoa_base(lld, 10));
			}
			index = 0;
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
		}
	}
	else
	{
		if (info->zero)
		{
			if (lld == 0 && info->dot && info->precision == 0)
				len--;
			if (info->precision >= len)
				info->precision -= len;
			if (lld < 0 && info->width > 0)
				len++;
			len = (info->precision == 0 && lld == 0 && info->width != -1 && info->precision_sign) ? 1 : len;
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			index = 0;
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(lld == 0 && info->dot && (info->precision + len) == 0) || info->precision_sign)
			{
				ft_putstr_fd(ft_itoa_base(lld, 10), 1);
				res += ft_strlen(ft_itoa_base(lld, 10));
				if (lld == 0)
					len = ft_strlen(ft_itoa_base(lld, 10));
			}
		}
		else
		{
			if (lld == 0 && info->dot && info->precision == 0)
				len--;
			if (info->precision >= len)
				info->precision -= len;
			if (lld < 0 && info->width > 0)
				len++;
			len = (info->precision == 0 && lld == 0 && info->width != -1 && info->precision_sign) ? 1 : len;
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			index = 0;
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(lld == 0 && info->dot && (info->precision + len) == 0) || info->precision_sign)
			{
				ft_putstr_fd(ft_itoa_base(lld, 10), 1);
				res += ft_strlen(ft_itoa_base(lld, 10));
				if (lld == 0)
					len = ft_strlen(ft_itoa_base(lld, 10));
			}
		}
	}
	return (res);
}

int		print_hex_lower(t_info *info, va_list ap, char conversion)
{
	long long int	lld;
	int				len;
	int				index;
	int				res;

	(void)conversion;
	res = 0;
	lld = (unsigned int)va_arg(ap, unsigned int);
	len = ft_strlen(ft_itoa_base(lld, 16));
	info->width -= info->space;
	if (info->width < 0)
		info->width = info->width * -1;
	if (info->width < len)
		info->width = -1;
	if (info->precision < 0)
	{
		info->precision_sign = 1;
		info->precision = 0;
	}
	else if (info->precision < len && info->precision != 0)
		info->precision = len;
	index = 0;
	if (info->left_align)
	{
		if (info->zero)
		{
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			ft_putstr_fd(ft_itoa_base(lld, 16), 1);
			res += ft_strlen(ft_itoa_base(lld, 16));
			if (lld < 0)
				len++;
			index = 0;
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
		}
		else
		{
			if (lld == 0 && info->dot && info->precision == 0)
				len--;
			if (info->precision >= len)
				info->precision -= len;
			if (lld < 0 && info->width > 0)
				len++;
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(lld == 0 && info->dot && ((info->precision + len) == 0)) || info->precision_sign)
			{
				ft_putstr_fd(ft_itoa_base(lld, 16), 1);
				res += ft_strlen(ft_itoa_base(lld, 16));
				if (lld == 0)
					len = ft_strlen(ft_itoa_base(lld, 16));
			}
			index = 0;
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
		}
	}
	else
	{
		if (info->zero)
		{
			if (lld == 0 && info->dot && info->precision == 0)
				len--;
			if (info->precision >= len)
				info->precision -= len;
			if (lld < 0 && info->width > 0)
				len++;
			len = (info->precision == 0 && lld == 0 && info->width != -1 && info->precision_sign) ? 1 : len;
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			index = 0;
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(lld == 0 && info->dot && info->precision == 0) || info->precision_sign)
			{
				ft_putstr_fd(ft_itoa_base(lld, 16), 1);
				res += ft_strlen(ft_itoa_base(lld, 16));
			}
		}
		else
		{
			if (lld == 0 && info->dot && info->precision == 0)
				len--;
			if (info->precision >= len)
				info->precision -= len;
			if (lld < 0 && info->width > 0)
				len++;
			len = (info->precision == 0 && lld == 0 && info->width != -1 && info->precision_sign) ? 1 : len;
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			index = 0;
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(lld == 0 && info->dot && (info->precision + len) == 0) || info->precision_sign)
			{
				ft_putstr_fd(ft_itoa_base(lld, 16), 1);
				res += ft_strlen(ft_itoa_base(lld, 16));
				if (lld == 0)
					len = ft_strlen(ft_itoa_base(lld, 16));
			}
		}
	}
	return (res);
}

int		print_hex_upper(t_info *info, va_list ap, char conversion)
{
	long long int	lld;
	int				len;
	int				index;
	int				res;

	(void)conversion;
	res = 0;
	lld = (unsigned int)va_arg(ap, unsigned int);
	len = ft_strlen(ft_itoa_base_upper(lld, 16));
	info->width -= info->space;
	if (info->width < 0)
		info->width = info->width * -1;
	if (info->width < len)
		info->width = -1;
	// if (info->precision >= len)
	// 	info->precision -= len;
	if (info->precision < 0)
	{
		info->precision_sign = 1;
		info->precision = 0;
	}
	else if (info->precision < len && info->precision != 0)
		info->precision = len;
	index = 0;
	if (info->left_align)
	{
		if (info->zero)
		{
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			ft_putstr_fd(ft_itoa_base_upper(lld, 16), 1);
			res += ft_strlen(ft_itoa_base_upper(lld, 16));
			if (lld < 0)
				len++;
			index = 0;
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
		}
		else
		{
			if (lld == 0 && info->dot && info->precision == 0)
				len--;
			if (info->precision >= len)
				info->precision -= len;
			if (lld < 0 && info->width > 0)
				len++;
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(lld == 0 && info->dot && ((info->precision + len) == 0)) || info->precision_sign)
			{
				ft_putstr_fd(ft_itoa_base_upper(lld, 16), 1);
				res += ft_strlen(ft_itoa_base_upper(lld, 16));
				if (lld == 0)
					len = ft_strlen(ft_itoa_base_upper(lld, 16));
			}
			index = 0;
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
		}
	}
	else
	{
		if (info->zero)
		{
			if (lld == 0 && info->dot && info->precision == 0)
				len--;
			if (info->precision >= len)
				info->precision -= len;
			if (lld < 0 && info->width > 0)
				len++;
			len = (info->precision == 0 && lld == 0 && info->width != -1 && info->precision_sign) ? 1 : len;
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			index = 0;
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(lld == 0 && info->dot && info->precision == 0) || info->precision_sign)
			{
				ft_putstr_fd(ft_itoa_base_upper(lld, 16), 1);
				res += ft_strlen(ft_itoa_base_upper(lld, 16));
			}
		}
		else
		{
			if (lld == 0 && info->dot && info->precision == 0)
				len--;
			if (info->precision >= len)
				info->precision -= len;
			if (lld < 0 && info->width > 0)
				len++;
			len = (info->precision == 0 && lld == 0 && info->width != -1 && info->precision_sign) ? 1 : len;
			while (index++ < info->width - info->precision - len)
			{
				ft_putchar_fd(' ', 1);
				res++;
			}
			if (lld < 0)
			{
				ft_putchar_fd('-', 1);
				res++;
			}
			index = 0;
			while (index++ < info->precision)
			{
				ft_putchar_fd('0', 1);
				res++;
			}
			if (!(lld == 0 && info->dot && (info->precision + len) == 0) || info->precision_sign)
			{
				ft_putstr_fd(ft_itoa_base_upper(lld, 16), 1);
				res += ft_strlen(ft_itoa_base_upper(lld, 16));
				if (lld == 0)
					len = ft_strlen(ft_itoa_base_upper(lld, 16));
			}
		}
	}
	return (res);
}