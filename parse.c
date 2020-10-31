/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:33:49 by juyang            #+#    #+#             */
/*   Updated: 2020/10/22 00:33:50 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				star_parse(t_info *info, size_t *index, va_list ap)
{
	int			va;

	(*index)++;
	va = (int)va_arg(ap, int);
	if (info->dot)
	{
		info->precision = va;
		info->zero = (info->precision > -1) ? 0 : info->zero;
	}
	else
	{
		if (va < 0)
		{
			info->left_align = 1;
			info->width = va;
		}
		else if (info->width == 0)
			info->width = va;
	}
	return (0);
}

int				precision_parse(char *format, t_info *info,
size_t *index)
{
	(*index)++;
	info->dot = 1;
	info->precision = ft_atoi(&format[*index]);
	info->zero = (format[*index] != '*') ? 0 : info->zero;
	while (ft_isdigit(format[*index]))
		(*index)++;
	return (0);
}

int				flag_parse(char *format, t_info *info,
size_t *index, va_list ap)
{
	if (format[*index] == '-' && (info->left_align = 1))
		(*index)++;
	else if (format[*index] == '0' && info->width == 0)
	{
		info->zero = 1;
		info->percent_zero = 1;
		(*index)++;
		while (format[*index] == '0')
			(*index)++;
	}
	else if (format[*index] != '0' && ft_isdigit(format[*index]))
	{
		info->width = ft_atoi(&format[*index]);
		while (ft_isdigit(format[*index]))
			(*index)++;
	}
	else if (format[*index] == '.')
		precision_parse(format, info, index);
	else if (format[*index] == '*')
		star_parse(info, index, ap);
	else
		return (-1);
	return (0);
}

int				conversion_parse(char *format, t_info *info,
size_t *index, va_list ap)
{
	if (format[*index] == 'c')
		return (print_cspercent(info, ap, 'c'));
	else if (format[*index] == 's')
		return (print_cspercent(info, ap, 's'));
	else if (format[*index] == 'p')
		return (print_address(info, ap));
	else if (format[*index] == 'd')
		return (print_integer(info, ap, 'd'));
	else if (format[*index] == 'i')
		return (print_integer(info, ap, 'i'));
	else if (format[*index] == 'u')
		return (print_integer(info, ap, 'u'));
	else if (format[*index] == 'x')
		return (print_hex_lower(info, ap));
	else if (format[*index] == 'X')
		return (print_hex_upper(info, ap));
	else if (format[*index] == '%')
		return (print_cspercent(info, ap, '%'));
	else
		return (-1);
	return (0);
}

int				percent_parse(char *format, va_list ap,
t_info *info, size_t *index)
{
	int			res;

	res = 0;
	init_info(info);
	(*index)++;
	if (!ft_strchr_set(&format[*index], CONVERSION))
		return (res);
	while (!(ft_strchr(CONVERSION, format[*index])))
		if (flag_parse(format, info, index, ap))
			return (-1);
	if (ft_strchr(CONVERSION, format[*index]))
		res += conversion_parse(format, info, index, ap);
	return (res);
}
