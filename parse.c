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

int			flag_parse(char *format, t_info *info, int *index, va_list ap)
{
	if (format[*index] == '-')
		info->left_align = 1;
	else if (format[*index] == '0' && info->width == 0)
	{
		info->zero = 1;
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
	{
		(*index)++;
		info->dot = 1;
		info->precision = ft_atoi(&format[*index]);
		while (ft_isdigit(format[*index]))
			(*index)++;
	}
	else if (format[*index] == '*')
	{
		if (info->width == 0)
			info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->width = 0;
		}
		else
			return (-1);
	}
	else
	{
		return (-1);
	}
	
	return (0);
}

int				conversion_parse(char *format, t_info *info, int *index, va_list ap)
{
	if (format[*index] == 'c')
		print_string(&info, ap, 'c');
	else if (format[*index] == 's')
		print_string(&info, ap, 's');
	else if (format[*index] == 'p')
		print_address(&info, ap, 'p');
	else if (format[*index] == 'd')
		print_integer(&info, ap, 'd');
	else if (format[*index] == 'i')
		print_integer(&info, ap, 'i');
	else if (format[*index] == 'u')
		print_integer(&info, ap, 'u');
	else if (format[*index] == 'x')
		print_hex(&info, ap, 'x');
	else if (format[*index] == 'X')
		print_hex(&info, ap, 'X');
	else if (format[*index] == '%')
		print_string(&info, ap, '%');
	else
		return (-1);
	return (0);
}

int				format_parse(char *format, va_list ap)
{
	size_t		index;
	char		*tmp;
	t_info		*info;

	index = 0;
	info = (t_info *)malloc(sizeof(t_info) * 1);
	while (format[index])
	{
		if (format[index] && format[index] != '%')
			ft_putchar_fd(format[index++], 1);
		else if (format[index] == '%' && format[index + 1])
		{
			init_info(&info);
			index++;
			while (!(ft_strchr(CONVERSION, format[index])))
				if (flag_parse(format, &info, &index, ap))
					return (-1);
			if (ft_strchr(CONVERSION, format[index]))
				conversion_parse(format, &info, &index, ap);
			else
				return (-1);
		}
	}
	free(info);
}
