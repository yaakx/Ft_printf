/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:22:14 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/24 13:40:14 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct		s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	char	type;
}					t_flags;

int					parse_flags(t_flags *fl, const char *s, va_list vl);
int					ft_printf(const char *s, ...);
int					write_flag(t_flags *fl, va_list vl);
int					maxlen_int(t_flags *fl, int n, char *s);
int					write_unsigned(t_flags *fl, va_list vl);
int					write_int(t_flags *fl, va_list vl);
int					write_percent(t_flags *fl);
int					write_pointer(t_flags *fl, va_list vl);
int					write_char(t_flags *fl, va_list vl);
int					write_string(t_flags *fl, va_list vl);
char				*ft_itoa_base(unsigned long long int n, char type);
void				print_it(t_flags *fl, int n, int len, char *s);

#endif
