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
		ft_putchar_fd(va_arg(ap, char), 1);
	else if (conversion == '%')
		ft_putchar_fd('%', 1);
	else if (conversion == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
}

void		print_address(t_info *info, va_list ap, char conversion)
{
	unsigned char	*addr;

	addr = va_arg(ap, unsigned char *);
}

void		print_integer(t_info *info, va_list ap, char conversion)
{
	ft_putstr_fd(ft_itoa(va_arg(ap, int)), 1);
}

void		print_hex(t_info *info, va_list ap, char conversion)
{
	ft_putstr_fd(ft_itoa_base(va_arg(ap, int), 16), 1);
}