/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:34:48 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/24 13:42:39 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		maxlen_int(t_flags *fl, int n, char *s)
{
	int len;
	int	max_len;

	len = (fl->type == 'p') ? ft_strlen(s) + 2 : ft_strlen(s);
	max_len = 0;
	if (len >= fl->width && len >= fl->precision)
		max_len = (n < 0) ? len + 1 : len;
	else if (fl->width >= fl->precision && fl->width >= len)
		max_len = fl->width;
	else
	{
		max_len = (n < 0) ? fl->precision + 1 : fl->precision;
		max_len = (fl->type == 'p') ? max_len + 2 : max_len;
	}
	return (max_len);
}

int		write_unsigned(t_flags *fl, va_list vl)
{
	unsigned long int	n;
	unsigned long int	len;
	char				*s;

	n = va_arg(vl, unsigned int);
	s = ft_itoa_base(n, fl->type);
	len = maxlen_int(fl, 0, s);
	if (fl->precision == 0 && fl->width == -1)
		len = 0;
	print_it(fl, 0, len, s);
	free(s);
	return (len);
}

int		write_int(t_flags *fl, va_list vl)
{
	long		n;
	long		c;
	int			len;
	char		*s;

	n = (long)va_arg(vl, int);
	c = (n < 0) ? n * -1 : n;
	s = ft_itoa_base(c, 'u');
	len = maxlen_int(fl, n, s);
	if (fl->precision == 0 && fl->width == -1)
		len = 0;
	print_it(fl, n, len, s);
	free(s);
	return (len);
}
