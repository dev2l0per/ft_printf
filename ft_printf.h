/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:10:12 by juyang            #+#    #+#             */
/*   Updated: 2020/10/21 19:05:44 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

# define CONVERSION "cspdiuxX%"
# define FLAG "-0.*"

typedef struct	s_info
{
	int			left_align;
	int			zero;
	int			dot;
	int			width;
	int			precision;
	int			len;
}				t_info;

int				ft_printf(const char *format, ...);
void			init_info(t_info *info);
char		*ft_itoa_base(long long int num, int base);
int				format_parse(char *format, va_list ap);
int				conversion_parse(char *format, t_info *info, size_t *index, va_list ap);
int			flag_parse(char *format, t_info *info, size_t *index, va_list ap);
void		print_hex(t_info *info, va_list ap, char conversion);
void		print_integer(t_info *info, va_list ap, char conversion);
void		print_address(t_info *info, va_list ap, char conversion);
void		print_string(t_info *info, va_list ap, char conversion);

#endif
