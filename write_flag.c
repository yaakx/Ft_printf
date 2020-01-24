/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:27:35 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/24 13:37:11 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_string(t_flags *fl, va_list vl)
{
	char	*s;
	int		i;
	int		len_max;
	int		len;

	s = va_arg(vl, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	i = (int)ft_strlen(s);
	len = (fl->precision < i) ? fl->precision : i;
	fl->precision = (len > 0) ? len : fl->precision;
	len = (len < 0) ? i : len;
	s = ft_substr(s, 0, len);
	len_max = (len > fl->width) ? len : fl->width;
	print_it(fl, 0, len_max, s);
	free(s);
	return (len_max);
}

int		write_char(t_flags *fl, va_list vl)
{
	char	s;
	int		i;

	i = 1;
	s = (char)va_arg(vl, int);
	if (fl->minus != -1)
		write(1, &s, 1);
	while (i < fl->width)
	{
		if (fl->zero == 1 && fl->minus == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
	if (fl->minus == -1)
		write(1, &s, 1);
	return (i);
}

int		write_pointer(t_flags *fl, va_list vl)
{
	unsigned long long	n;
	char				*s;
	int					len;

	n = (unsigned long long)va_arg(vl, void *);
	s = ft_itoa_base(n, 'x');
	if (fl->precision == 0)
	{
		free(s);
		s = ft_strdup("");
	}
	len = maxlen_int(fl, 0, s);
	if (fl->width > 0)
		fl->width = fl->width - 2;
	print_it(fl, 0, len, s);
	free(s);
	return (len);
}

int		write_percent(t_flags *fl)
{
	int i;

	i = 1;
	if (fl->minus != -1)
		write(1, "%", 1);
	while (i < fl->width)
	{
		if (fl->zero == 1 && fl->minus == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
	if (fl->minus == -1)
		write(1, "%", 1);
	return (i);
}

int		write_flag(t_flags *fl, va_list vl)
{
	if (fl->type == 'd' || fl->type == 'i')
		return (write_int(fl, vl));
	if (fl->type == 's')
		return (write_string(fl, vl));
	if (fl->type == 'c')
		return (write_char(fl, vl));
	if (fl->type == 'x' || fl->type == 'X' || fl->type == 'u')
		return (write_unsigned(fl, vl));
	if (fl->type == 'p')
		return (write_pointer(fl, vl));
	if (fl->type == '%')
		return (write_percent(fl));
	return (0);
}
