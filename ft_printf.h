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
# define FLAG "-0. *"

typedef struct	s_info
{
	int			left_align;
	int			percent_zero;
	int			zero;
	int			dot;
	int			width;
	int			precision;
	int			precision_sign;
	int			space;
	int			len;
}				t_info;

int				ft_printf(const char *format, ...);
void			print_info(t_info *info);
void			init_info(t_info *info);
int				format_parse(char *format, va_list ap);

int				percent_parse(char *format, va_list ap,
t_info *info, size_t *index);
int				conversion_parse(char *format, t_info *info,
size_t *index, va_list ap);
int				flag_parse(char *format, t_info *info,
size_t *index, va_list ap);
int				precision_parse(char *format, t_info *info,
size_t *index);
int				star_parse(t_info *info, size_t *index, va_list ap);

char		*ft_itoa_base_upper(long long int num, int base);
char		*ft_itoa_base(long long int num, int base);
size_t		num_len(long long int n, int base);

void		null_string(va_list ap, char *str);
void		print_integer_setting(t_info *info, int *len, long long int lld);

int			print_address(t_info *info, va_list ap);
int			print_address_noflag(t_info *info, long long int lld, int len, char *str);
int			print_address_precision(t_info *info, long long int lld, int len, char *str);
int			print_address_align(t_info *info, long long int lld, int len, char *str);
int			print_address_align_precision(t_info *info,
long long int lld, int len, char *str);

int			print_cspercent(t_info *info, va_list ap, char conversion);
int			print_percent(t_info *info);
int			print_character(t_info *info, va_list ap);

int			print_hex_lower(t_info *info, va_list ap);
int			print_hex_lower_noflag(t_info *info,
long long int lld, int len, char *str);
int			print_hex_lower_zero(t_info *info,
long long int lld, int len, char *str);
int			print_hex_lower_align(t_info *info,
long long int lld, int len, char *str);
int			print_hex_lower_align_zero(t_info *info,
long long int lld, int len, char *str);

int			print_hex_upper(t_info *info, va_list ap);
int			print_hex_upper_noflag(t_info *info,
long long int lld, int len, char *str);
int			print_hex_upper_zero(t_info *info,
long long int lld, int len, char *str);
int			print_hex_upper_align(t_info *info,
long long int lld, int len, char *str);
int			print_hex_upper_align_zero(t_info *info,
long long int lld, int len, char *str);

int			print_integer(t_info *info, va_list ap, char conversion);
int			print_integer_noflag(long long int lld,
t_info *info, int len, char *str);
int			print_integer_zero(long long int lld,
t_info *info, int len, char *str);
int			print_integer_align(long long int lld,
t_info *info, int len, char *str);
int			print_integer_align_zero(long long int lld,
t_info *info, int len, char *str);

int			print_string(t_info *info, va_list ap);
int			print_string_noflag(t_info *info, char *str, int str_len);
int			print_string_precision(t_info *info, char *str, int str_len);
int			print_string_align(t_info *info, char *str, int str_len);
int			print_string_align_precision(t_info *info, char *str, int str_len);

#endif
