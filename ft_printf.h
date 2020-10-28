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
}				t_info;

int				ft_printf(const char *format, ...);

#endif
